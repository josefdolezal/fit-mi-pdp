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

using namespace std;

void printUsage(const string& progName);

int main(int argc, const char * argv[]) {
    // Run the solution for each file from given list
    for(int i = 1; i < argc; ++i) {
        const char* fileName = argv[i];
        ChessBoard chessboard = Reader::readInput(fileName);
        // Create solver
        Time start;
        // Find the solution

        cout << "::::: File: " << fileName << " :::::"  << endl;
        cout << "Minimal steps needed: " << "<solution.steps>" << endl;
        cout << "<solution.path>" << endl;
        cout << "::::: Time: " << Time().delta(start) << " :::::" << endl << endl;
    }

    return 0;
}

void printUsage(const string& progName) {
    cout << "Usage: " << progName << " <mode>" << " input [input ...]" << endl;
}
