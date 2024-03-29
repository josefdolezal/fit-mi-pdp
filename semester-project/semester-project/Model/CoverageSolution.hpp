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
#include <map>

#include "Location.hpp"

using namespace std;

class CoverageSolution {
public:
    CoverageSolution(uint32_t size = 0);

    vector<pair<Location, bool>> steps;

    size_t size() const;
    int blacksTaken() const;

    void add(const Location &, bool taken);
    bool isTaken(const Location &) const;

    bool isActualSolution = false;

    friend ostream& operator << (ostream &, const CoverageSolution &);

private:
    uint32_t solutionSize = 0;

    map<pair<uint32_t, uint32_t>, bool> takens;
};

#endif /* CoverageSolution_hpp */
