//
//  CoverageSolution.hpp
//  semester-project
//
//  Created by Josef Dolezal on 12/03/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#ifndef CoverageSolution_hpp
#define CoverageSolution_hpp

#include <stdio.h>
#include <vector>

#include "Location.hpp"

using namespace std;

class CoverageSolution {
public:
    vector<Location> steps;

    friend ostream& operator << (ostream &, const CoverageSolution &);
};

#endif /* CoverageSolution_hpp */
