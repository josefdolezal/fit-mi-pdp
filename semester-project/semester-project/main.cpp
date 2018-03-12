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

int main(int argc, const char * argv[]) {
    // Run the solution for each file from given list
    for(int i = 1; i < argc; ++i) {
        const char* fileName = argv[i];

        ChessBoard chessboard = Reader::readInput(fileName);

        std::cout << chessboard << std::endl;
    }

    return 0;
}
