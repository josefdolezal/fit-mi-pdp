//
//  DataOrientedCoverage.hpp
//  semester-project
//
//  Created by Josef Dolezal on 10/04/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#ifndef DataOrientedCoverage_hpp
#define DataOrientedCoverage_hpp

#include <cstdio>
#include <deque>
#include <omp.h>

#include "ChessBoard.hpp"
#include "CoverageSolution.hpp"
#include "DataParameters.hpp"

class DataOrientedCoverage {
public:
    DataOrientedCoverage(ChessBoard &);

    CoverageSolution minimalCoverage();
    CoverageSolution minimailCoverageWithInitial(DataParameters);
private:
    ChessBoard &chessboard;
    CoverageSolution bestSolution;

    // Create all possible directions and move along them
    pair<uint32_t, uint32_t> directions[8] = {
        make_pair(1, 0), make_pair(1, 1), make_pair(0, 1), make_pair(-1, 1),
        make_pair(-1, 0), make_pair(-1, -1), make_pair(0, -1), make_pair(1, -1) };

    void findPath(DataParameters dataParameters);
    void scheduleMovements(const Location &, deque<Location> &, const CoverageSolution &);
    void scheduleMovement(int32_t x, int32_t y, uint32_t directionX,
                          uint32_t directionY, deque<Location> &, const CoverageSolution &);
};

#endif /* DataOrientedCoverage_hpp */
