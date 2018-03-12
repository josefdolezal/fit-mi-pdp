//
//  CoverageSolution.cpp
//  semester-project
//
//  Created by Josef Dolezal on 12/03/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#include "CoverageSolution.hpp"

ostream& operator << (ostream &os, const CoverageSolution &solution) {
    for(auto &step: solution.steps) {
        os << step;
    }

    return os;
}
