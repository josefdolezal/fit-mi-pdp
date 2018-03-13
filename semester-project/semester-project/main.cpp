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
#include "Time.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // Run the solution for each file from given list
    for(int i = 1; i < argc; ++i) {
        const char* fileName = argv[i];
        ChessBoard chessboard = Reader::readInput(fileName);
        PiecesMinimalCoverage solver(chessboard);
        Time start;
        CoverageSolution solution = solver.minimalCoverage();

        cout << "::::: File: " << fileName << " :::::"  << endl;
        cout << "Minimal steps needed: " << solution.size() - 1 << endl;
        cout << solution << endl;
        cout << "::::: Time: " << Time().delta(start) << " :::::" << endl << endl;
    }

    return 0;
}
