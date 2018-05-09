//
//  DataOrientedCoverage.cpp
//  semester-project
//
//  Created by Josef Dolezal on 10/04/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#include <deque>
#include <omp.h>

#include "DataOrientedCoverage.hpp"

using namespace std;

DataOrientedCoverage::DataOrientedCoverage(ChessBoard& chessboard): chessboard(chessboard), bestSolution(CoverageSolution(3*chessboard.upperBound)) { }

CoverageSolution DataOrientedCoverage::minimalCoverage() {
    CoverageSolution initialSolution;
    DataParameters initialParameters(chessboard.queenLocation, initialSolution, 0, 0);

    return minimailCoverageWithInitial(initialParameters);
}

CoverageSolution DataOrientedCoverage::minimailCoverageWithInitial(DataParameters initialParameters) {
    deque<DataParameters> parametersQueue;
    uint32_t maxQueueSize = 70;

    parametersQueue.push_back(initialParameters);

    while(parametersQueue.size() < maxQueueSize && !parametersQueue.empty()) {
        DataParameters params = parametersQueue.front();
        Location location = params.location;
        CoverageSolution currentSolution = params.currentSolution;
        uint32_t currentDepth = params.currentDepth;
        uint32_t blacksTaken = params.blacksTaken;

        parametersQueue.pop_front();

        // Check the terminating condition
        if(bestSolution.size() - 1 == chessboard.numberOfBlackPieces ||
           params.currentDepth > chessboard.upperBound ||
           params.currentDepth + (chessboard.numberOfBlackPieces - params.blacksTaken) >= bestSolution.size())
            continue;


        // Checke if the is taken in this step
        bool isBlackTaken = chessboard.fieldAtLocation(location.x, location.y).isBlack() && !currentSolution.isTaken(location);

        // Add informations about about current step
        currentSolution.add(location, isBlackTaken);
        blacksTaken += isBlackTaken ? 1 : 0;

        // All black pieces are taken, check for the optimality and stop this branch
        if(blacksTaken == chessboard.numberOfBlackPieces && currentSolution.size() < bestSolution.size()) {
            bestSolution = currentSolution;

            continue;
        }

        if(currentDepth + 1 > chessboard.upperBound)
            continue;

        // Create itenary with next steps and explore them
        deque<Location> itenary;
        scheduleMovements(location, itenary, currentSolution);

        // Recursive call
        for(auto &step: itenary) {
            DataParameters neighbor = DataParameters(step, currentSolution, currentDepth + 1, blacksTaken);

            parametersQueue.push_back(neighbor);
        }
    }

    uint32_t iterator;

    #pragma omp parallel for private(iterator)
    for(iterator = 0; iterator < (uint32_t) parametersQueue.size(); iterator++) {
        findPath(parametersQueue[iterator]);
    }

    return bestSolution;
}

void DataOrientedCoverage::findPath(DataParameters dataParameters) {
    Location location = dataParameters.location;
    CoverageSolution currentSolution = dataParameters.currentSolution;
    uint32_t currentDepth = dataParameters.currentDepth;
    uint32_t blacksTaken = dataParameters.blacksTaken;

    // Check the terminating condition
    if(bestSolution.size() - 1 == chessboard.numberOfBlackPieces ||
       currentDepth > chessboard.upperBound ||
       currentDepth + (chessboard.numberOfBlackPieces - blacksTaken) >= bestSolution.size())
        return;


    // Checke if the is taken in this step
    bool isBlackTaken = chessboard.fieldAtLocation(location.x, location.y).isBlack() && !currentSolution.isTaken(location);

    // Add informations about about current step
    currentSolution.add(location, isBlackTaken);
    blacksTaken += isBlackTaken ? 1 : 0;

    // All black pieces are taken, check for the optimality and stop this branch
    if(blacksTaken == chessboard.numberOfBlackPieces) {
        // Check the result without creating lock
        if(currentSolution.size() < bestSolution.size()) {
            // Create the lock and check again
            #pragma omp critical
            if(currentSolution.size() < bestSolution.size()) bestSolution = currentSolution;
        }

        return;
    }

    if(currentDepth + 1 > chessboard.upperBound)
        return;

    // Create itenary with next steps and explore them
    deque<Location> itenary;
    scheduleMovements(location, itenary, currentSolution);

    // Recursive call
    for(auto &step: itenary) {
        DataParameters params = DataParameters(step, currentSolution, currentDepth + 1, blacksTaken);
        findPath(params);
    }
}

void DataOrientedCoverage::scheduleMovements(const Location& location, deque<Location>& itenary, const CoverageSolution& currentSolution) {

    for(auto &direction : directions)
        scheduleMovement(location.x, location.y, direction.first, direction.second, itenary, currentSolution);
}

void DataOrientedCoverage::scheduleMovement(int32_t x, int32_t y, uint32_t directionX, uint32_t directionY,
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
