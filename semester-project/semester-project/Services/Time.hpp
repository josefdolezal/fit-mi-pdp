//
//  Time.hpp
//  semester-project
//
//  Created by Josef Dolezal on 13/03/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#ifndef Time_hpp
#define Time_hpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Time {
public:
    Time();

    double delta(const Time &);

private:
    clock_t timestamp;
};

#endif /* Time_hpp */
