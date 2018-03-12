//
//  Field.hpp
//  semester-project
//
//  Created by Josef Dolezal on 12/03/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#ifndef Field_hpp
#define Field_hpp

#include <cstdio>
#include <iostream>

#include "Location.hpp"

using namespace std;

class Field {
public:
    static const char EMPTY_IDENTIFIER = '0';
    static const char BLACK_IDENTIFIER = '1';
    static const char WHITE_IDENTIFIER = '2';
    static const char QUEEEN_IDENTIFIER = '3';

    Location location;
    char type;

    Field(u_int32_t x = 0, u_int32_t y = 0, char type = EMPTY_IDENTIFIER);

    void setType(char type);
    void setLocation(u_int32_t x, u_int32_t y);

    bool isEmpty() const;
    bool isBlack() const;
    bool isWhite() const;
    bool isQueen() const;

    friend ostream& operator << (ostream &, const Field &);
};

#endif /* Field_hpp */
