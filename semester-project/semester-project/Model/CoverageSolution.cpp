//
//  CoverageSolution.cpp
//  semester-project
//
//  Created by Josef Dolezal on 12/03/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#include "CoverageSolution.hpp"

CoverageSolution::CoverageSolution(uint32_t size): solutionSize(size) { }

size_t CoverageSolution::size() const {
    return solutionSize;
}

void CoverageSolution::add(const Location &location, bool taken) {
    steps.push_back(make_pair(location, taken));
    ++solutionSize;

    if(taken)
        takens.insert(make_pair(make_pair(location.x, location.y), taken));
}

bool CoverageSolution::isTaken(const Location &location) const {
    auto it = takens.find(make_pair(location.x, location.y));

    return it != takens.end();
}

ostream& operator << (ostream &os, const CoverageSolution &solution) {
    for(auto &step: solution.steps) {
        char taken = step.second ? '\0' : '*';

        os << step.first << taken;
    }

    return os;
}
