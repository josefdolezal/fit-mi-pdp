//
//  main.cpp
//  semester-project
//
//  Created by Josef Dolezal on 10/03/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#include <iostream>
#include "Reader.hpp"
#include "ChessBoard.hpp"
#include "PiecesMinimalCoverage.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // Run the solution for each file from given list
    for(int i = 1; i < argc; ++i) {
        const char* fileName = argv[i];
        ChessBoard chessboard = Reader::readInput(fileName);
        PiecesMinimalCoverage solver(chessboard);

        cout << "::::: File: " << fileName << " :::::"  << endl;
        cout << solver.minimalCoverage() << endl;
        cout << "::::: Time: " << 0 << ":::::" << endl;
    }

    return 0;
}
