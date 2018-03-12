//
//  Reader.cpp
//  semester-project
//
//  Created by Josef Dolezal on 11/03/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <fstream>

#include "Reader.hpp"
#include "Field.hpp"

using namespace std;

ChessBoard Reader::readInput(const char * &file) {
    ifstream read(file);
    int32_t size, upperBound;
    char c = Field::EMPTY_IDENTIFIER;

    // Read the chessboard size and upperbound from given file
    read >> size >> upperBound;

    ChessBoard chessboard(size);

    // Read the actual chessboard values
    for(uint32_t y = 0; y < size; ++y) {
        for (uint32_t x = 0; x < size; ++x) {
            read >> c;
            chessboard.setPiece(x, y, c);
        }
    }

    return chessboard;
}
