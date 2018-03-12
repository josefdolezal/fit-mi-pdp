//
//  Location.cpp
//  semester-project
//
//  Created by Josef Dolezal on 12/03/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#include "Location.hpp"

Location::Location(u_int32_t x, u_int32_t y): x(x), y(y) { }

ostream& operator << (ostream &os, const Location &location) {
    os << "(" << location.x << ", " << location.y << ")";

    return os;
}
