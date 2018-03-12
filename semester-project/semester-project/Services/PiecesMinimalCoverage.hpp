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

#include "ChessBoard.hpp"
#include "CoverageSolution.hpp"

class PiecesMinimalCoverage{
public:
    PiecesMinimalCoverage(ChessBoard chessboard);

    CoverageSolution minimalCoverage();
private:
    ChessBoard chessboard;
};

#endif /* PiecesMinimalCoverage_hpp */
