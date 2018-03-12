//
//  ChessBoard.hpp
//  semester-project
//
//  Created by Josef Dolezal on 12/03/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#ifndef ChessBoard_hpp
#define ChessBoard_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>

#include "Field.hpp"
#include "Location.hpp"

using namespace std;

// Represents the chessboard play area
class ChessBoard {
public:

    const uint32_t size;

    uint32_t numberOfBlackPieces = 0;
    uint32_t upperBound;
    Location queenLocation = Location(0, 0);

    ChessBoard(uint32_t size, uint32_t upperBound);
    ~ChessBoard();

    void setPiece(uint32_t x, uint32_t y, char value);
    const Field& fieldAtLocation(uint32_t x, uint32_t y);

    friend ostream& operator << (ostream & os, const ChessBoard & chessboard);

private:
    Field **playArea;
};


#endif /* ChessBoard_hpp */
