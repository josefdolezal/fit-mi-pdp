//
//  DistributedMinimalCoverage.cpp
//  semester-project-mpi
//
//  Created by Josef Dolezal on 16/04/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#include <deque>

#include "DistributedMinimalCoverage.hpp"
#include "DataParameters.hpp"
#include "DataOrientedCoverage.hpp"

// MARK: Life cycle

DistributedMinimalCoverage::DistributedMinimalCoverage(ChessBoard& chessboard, int argumentsCount, char** arguments)
    : chessboard(chessboard), bestSolution(CoverageSolution(3*chessboard.upperBound)),
      argumentsCount(argumentsCount), arguments(arguments) {

    // length + x + y + depth + taken + (x, y, taken) * upperBound
    int bufferSize = 5 + (3 * chessboard.upperBound);

    serializationBuffer = new int[bufferSize];
}

DistributedMinimalCoverage::~DistributedMinimalCoverage() {
    delete[] serializationBuffer;
}

// MARKL MPI

CoverageSolution DistributedMinimalCoverage::minimalCoverage() {
    int rank;

    MPI_Status status;
    MPI_Init(&argumentsCount, &arguments);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(isScheduler(rank)) {
        scheduleWork();
    } else {
        receiveWork(status);
    }

    MPI_Finalize();

    return CoverageSolution();
}

// MARK: MPI

void DistributedMinimalCoverage::scheduleWork() {
    deque<DataParameters> parametersQueue;
    uint32_t maxQueueSize = 20;
    CoverageSolution initialSolution;
    DataParameters initialParameters(chessboard.queenLocation, initialSolution, 0, 0);

    parametersQueue.push_back(initialParameters);

    // Use BFS to create tasks
    while(parametersQueue.size() < maxQueueSize && !parametersQueue.empty()) {
        DataParameters params = parametersQueue.front();
        parametersQueue.pop_front();

        // Check the terminating condition
        if(bestSolution.size() - 1 == chessboard.numberOfBlackPieces ||
           params.currentDepth > chessboard.upperBound ||
           params.currentDepth + (chessboard.numberOfBlackPieces - params.blacksTaken) >= bestSolution.size())
            continue;

        // Checke if the is taken in this step
        bool isBlackTaken = chessboard.fieldAtLocation(params.location.x, params.location.y).isBlack() && !params.currentSolution.isTaken(params.location);

        // Add informations about about current step
        params.currentSolution.add(params.location, isBlackTaken);
        params.blacksTaken += isBlackTaken ? 1 : 0;

        // All black pieces are taken, check for the optimality and stop this branch
        if(params.blacksTaken == chessboard.numberOfBlackPieces && params.currentSolution.size() < bestSolution.size()) {
            bestSolution = params.currentSolution;

            continue;
        }

        // Do not search for solution behind upper bbound
        if(params.currentDepth + 1 > chessboard.upperBound)
            continue;

        // Create itenary with next steps and explore them
        deque<Location> itenary;
        scheduleMovements(params.location, itenary, params.currentSolution);

        // Recursive call
        for(auto &step: itenary) {
            DataParameters neighbor = DataParameters(step, params.currentSolution, params.currentDepth + 1, params.blacksTaken);

            parametersQueue.push_back(neighbor);
        }
    }
}

void DistributedMinimalCoverage::receiveWork(MPI_Status& status) {

}

bool DistributedMinimalCoverage::isScheduler(int threadRank) {
    return threadRank == 0;
}

// MARK: Coverage logic

void DistributedMinimalCoverage::scheduleMovements(const Location &location, deque<Location> &itenary,
                                                   const CoverageSolution &currentSolution) {

    for(auto &direction : directions)
        scheduleMovement(location.x, location.y, direction.first, direction.second, itenary, currentSolution);
}

void DistributedMinimalCoverage::scheduleMovement(int32_t x, int32_t y, uint32_t directionX, uint32_t directionY,
                                            deque<Location> &itenary, const CoverageSolution &currentSolution) {

    int32_t chessboardSize = (int32_t) chessboard.size;

    x += directionX;
    y += directionY;

    while(x >= 0 && y >= 0 && x < chessboardSize && y < chessboardSize) {
        const Field &field = chessboard.fieldAtLocation(x, y);

        if(field.isBlack() && !currentSolution.isTaken(field.location)) {
            // Prepend this move to be taken with higher priority
            itenary.push_front(field.location);
            return;
        } else if(field.isWhite()) {
            return;
        } else if(field.isEmpty()) {
            // Assign low priority to empty move
            itenary.push_back(field.location);
        }

        x += directionX;
        y += directionY;
    }
}

// MARK: Serialization

// Send object into buffer
int DistributedMinimalCoverage::serialize(DataParameters &parameters) {
    int* b = serializationBuffer;
    int solutionSize = (int)parameters.currentSolution.size();
    int size = 5 + solutionSize;

    b[0] = size;
    b[1] = parameters.location.x;
    b[2] = parameters.location.y;
    b[3] = parameters.currentDepth;
    b[4] = parameters.blacksTaken;

    for(int step = 0; step < solutionSize; ++step) {
        int index = 5 + step * 3;
        pair<Location, bool>& p = parameters.currentSolution.steps.at(step);

        b[index] = p.first.x;
        b[index+1] = p.first.y;
        b[index+2] = p.second ? 1 : 0;
    }

    return size;
}

// Recieve object from buffer
DataParameters DistributedMinimalCoverage::deserialize() {
    int* b = serializationBuffer;
    int size = b[0];
    Location location(b[1], b[2]);
    CoverageSolution solution;

    for(int index = 5; index < size; index += 3) {
        Location stepLocation(b[index], b[index+1]);
        solution.add(stepLocation, b[index+2] == 1);
    }

    return DataParameters(location, solution, b[3], b[4]);
}
