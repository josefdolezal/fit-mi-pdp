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

using namespace std;

// Represents the chessboard play area
class ChessBoard {
public:

    static const char EMPTY_IDENTIFIER = '0';
    static const char BLACK_IDENTIFIER = '1';
    static const char WHITE_IDENTIFIER = '2';
    static const char QUEEEN_IDENTIFIER = '3';

    uint32_t numberOfBlackPieces = 0;

    ChessBoard(uint32_t size);
    ~ChessBoard();

    void setPiece(uint32_t x, uint32_t y, char value);

    friend ostream& operator << (ostream & os, const ChessBoard & chessboard);

private:
    const uint32_t size;
    char **playArea;
};


#endif /* ChessBoard_hpp */
