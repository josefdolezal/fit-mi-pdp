//
//  DataParameters.cpp
//  semester-project
//
//  Created by Josef Dolezal on 10/04/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#include "DataParameters.hpp"

DataParameters::DataParameters(Location location, CoverageSolution currentSolution, uint32_t currentDepth, uint32_t blacksTaken):
    location(location), currentSolution(currentSolution), currentDepth(currentDepth), blacksTaken(blacksTaken)
{
    
}

ostream& operator <<(ostream & os, const DataParameters& lhs) {
    os << lhs.currentSolution << "at " << lhs.location;

    return os;
}
