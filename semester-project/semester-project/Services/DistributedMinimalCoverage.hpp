//
//  DistributedMinimalCoverage.hpp
//  semester-project-mpi
//
//  Created by Josef Dolezal on 16/04/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#ifndef DistributedMinimalCoverage_hpp
#define DistributedMinimalCoverage_hpp

#include <mpi.h>
#include <deque>

#include "ChessBoard.hpp"
#include "CoverageSolution.hpp"
#include "DataParameters.hpp"

class DistributedMinimalCoverage {
public:
    DistributedMinimalCoverage(ChessBoard&, int, char**);

    CoverageSolution minimalCoverage();

    ~DistributedMinimalCoverage();
private:
    ChessBoard& chessboard;
    CoverageSolution bestSolution;
    pair<uint32_t, uint32_t> directions[8] = {
        make_pair(1, 0), make_pair(1, 1), make_pair(0, 1), make_pair(-1, 1),
        make_pair(-1, 0), make_pair(-1, -1), make_pair(0, -1), make_pair(1, -1) };

    static int TAG_FINISHED;
    static int TAG_WORK;
    static int TAG_SOLUTION;
    static int TAG_FAILED;

    int argumentsCount;
    char **arguments;
    int * serializationBuffer;
    int bufferSize;

    int serialize(DataParameters&);
    DataParameters deserialize();

    void findSolution();
    void scheduleMovements(const Location&, deque<Location>&, const CoverageSolution&);
    void scheduleMovement(int32_t, int32_t, uint32_t, uint32_t, deque<Location>&, const CoverageSolution&);

    void scheduleWork();
    void receiveWork();
    bool isScheduler(int);
};

#endif /* DistributedMinimalCoverage_hpp */
