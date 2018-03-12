//
//  PiecesMinimalCoverage.hpp
//  semester-project
//
//  Created by Josef Dolezal on 12/03/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#ifndef PiecesMinimalCoverage_hpp
#define PiecesMinimalCoverage_hpp

#include <cstdio>
#include <vector>

#include "ChessBoard.hpp"
#include "CoverageSolution.hpp"

class PiecesMinimalCoverage {
public:
    PiecesMinimalCoverage(ChessBoard &);

    CoverageSolution minimalCoverage();
private:
    ChessBoard &chessboard;
    CoverageSolution bestSolution;

    void findPath(const Location &, CoverageSolution currentSolution, uint32_t currentDepth, uint32_t blacksTaken);
    void scheduleMovements(const Location &, vector<Location> &, const CoverageSolution &);
    void scheduleMovement(int32_t x, int32_t y, uint32_t directionX,
                          uint32_t directionY, vector<Location> &, const CoverageSolution &);
};

#endif /* PiecesMinimalCoverage_hpp */
