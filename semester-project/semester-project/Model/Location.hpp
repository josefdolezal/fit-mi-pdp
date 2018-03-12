//
//  Location.hpp
//  semester-project
//
//  Created by Josef Dolezal on 12/03/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#ifndef Location_hpp
#define Location_hpp

#include <stdio.h>
#include <ostream>

using namespace std;

class Location {
public:
    u_int32_t x;
    u_int32_t y;

    Location(u_int32_t x, u_int32_t y);

    friend ostream& operator << (ostream &, const Location &);
};

#endif /* Location_hpp */
