//
//  ChessBoard.cpp
//  semester-project
//
//  Created by Josef Dolezal on 12/03/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#include "ChessBoard.hpp"

using namespace std;

ChessBoard::ChessBoard(uint32_t size, uint32_t upperBound): size(size), upperBound(upperBound) {
    playArea = new Field * [size];

    for(uint32_t x = 0; x < size; ++x)
        playArea[x] = new Field[size];
}

ChessBoard::~ChessBoard() {
    for(uint32_t i = 0; i < size; ++i)
        delete [] playArea[i];

    delete [] playArea;
}

void ChessBoard::setPiece(uint32_t x, uint32_t y, char value) {
    Field& field = playArea[x][y];

    field.setLocation(x, y);
    field.setType(value);

    if(field.isBlack())
        ++numberOfBlackPieces;

    if(field.isQueen())
        queenLocation = field.location;
}

const Field& ChessBoard::fieldAtLocation(uint32_t x, uint32_t y) {
    return playArea[x][y];
}

ostream& operator << (ostream & os, const ChessBoard & chessboard) {
    for(uint32_t y = 0; y < chessboard.size; ++y) {
        for(uint32_t x = 0; x < chessboard.size; ++x){
            os << chessboard.playArea[x][y];
        }

        os << endl;
    }

    return os;
}
