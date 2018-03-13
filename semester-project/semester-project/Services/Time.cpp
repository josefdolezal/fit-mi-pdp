//
//  Time.cpp
//  semester-project
//
//  Created by Josef Dolezal on 13/03/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#include "Time.hpp"

using namespace std;

Time::Time(): timestamp(clock()) { }

double Time::delta(const Time &time) {
    return (timestamp - time.timestamp) / (double)CLOCKS_PER_SEC;
}
