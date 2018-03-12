//
//  Reader.hpp
//  semester-project
//
//  Created by Josef Dolezal on 12/03/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#ifndef Reader_hpp
#define Reader_hpp

#include "ChessBoard.hpp"

using namespace std;

// Takes care of reading the chessboard from file
class Reader {
public:
    static ChessBoard readInput(const char* &);
};

#endif /* Reader_hpp */
