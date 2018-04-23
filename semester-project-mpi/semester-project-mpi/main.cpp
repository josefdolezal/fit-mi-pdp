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
#include "Time.hpp"
#include "DistributedMinimalCoverage.hpp"

using namespace std;

void printUsage(const string& progName);

int main(int argc, char * argv[]) {
    // Run the solution for each file from given list
    for(int i = 1; i < argc; ++i) {
        const char* fileName = argv[i];
        ChessBoard chessboard = Reader::readInput(fileName);
        DistributedMinimalCoverage solver(chessboard, argc, argv);
        Time start;
        CoverageSolution solution = solver.minimalCoverage();

        // Skip outputs for worker threads
        if(!solution.isActualSolution) continue;

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
