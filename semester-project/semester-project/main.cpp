//
//  main.cpp
//  semester-project
//
//  Created by Josef Dolezal on 10/03/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#include <iostream>
#include <string>
#include "Reader.hpp"
#include "ChessBoard.hpp"
#include "PiecesMinimalCoverage.hpp"
#include "DataOrientedCoverage.hpp"
#include "Time.hpp"

using namespace std;

void printUsage(const string& progName);

int main(int argc, const char * argv[]) {
    if(argc < 3) {
        printUsage(argv[0]);
        exit(1);
    }

    string mode(argv[1]);

    if(mode != "task-p" && mode != "data-p") {
        printUsage(argv[0]);
        cout << "Error: <mode> must have either \"data-p\" or \"task-p\" value." << endl;
        exit(1);
    }

    // Run the solution for each file from given list
    for(int i = 2; i < argc; ++i) {
        const char* fileName = argv[i];
        ChessBoard chessboard = Reader::readInput(fileName);
        DataOrientedCoverage solver(chessboard);
        Time start;
        CoverageSolution solution = solver.minimalCoverage();

        cout << "::::: File: " << fileName << " :::::"  << endl;
        cout << "Minimal steps needed: " << solution.size() - 1 << endl;
        cout << solution << endl;
        cout << "::::: Time: " << Time().delta(start) << " :::::" << endl << endl;
    }

    return 0;
}

void printUsage(const string& progName) {
    cout << "Usage: " << progName << " <mode>" << " input [input ...]" << endl;
}
