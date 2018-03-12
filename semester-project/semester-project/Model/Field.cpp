//
//  Field.cpp
//  semester-project
//
//  Created by Josef Dolezal on 12/03/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#include "Field.hpp"

Field::Field(u_int32_t x, u_int32_t y, char type): location(Location(x, y)), type(type) {}

void Field::setType(char type) {
    this->type = type;
}

void Field::setLocation(u_int32_t x, u_int32_t y) {
    location.x = x;
    location.y = y;
}

bool Field::isEmpty() {
    return type == EMPTY_IDENTIFIER;
}

bool Field::isBlack() {
    return type == BLACK_IDENTIFIER;
}

bool Field::isWhite() {
    return type == WHITE_IDENTIFIER;
}

bool Field::isQueen() {
    return type == QUEEEN_IDENTIFIER;
}

ostream& operator << (ostream &os, const Field &field) {
    Location l = field.location;
    os << "(" << l.x << ", " << l.y << ")";

    return os;
}
