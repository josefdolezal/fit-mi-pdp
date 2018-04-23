//
//  DataParameters.hpp
//  semester-project
//
//  Created by Josef Dolezal on 10/04/2018.
//  Copyright © 2018 Josef Dolezal. All rights reserved.
//

#ifndef DataParameters_hpp
#define DataParameters_hpp

#include "ChessBoard.hpp"
#include "CoverageSolution.hpp"

struct DataParameters {
public:
    Location location;
    CoverageSolution currentSolution;
    uint32_t currentDepth;
    uint32_t blacksTaken;

    DataParameters(Location, CoverageSolution, uint32_t, uint32_t);

    friend ostream& operator <<(ostream & os, const DataParameters& lhs);
};

#endif /* DataParameters_hpp */
