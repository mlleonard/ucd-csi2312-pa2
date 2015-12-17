//
// Created by Madeline Leonard on 11/13/15.
//

#include "Exception.h"

namespace Clustering {


    std::ostream &operator<<(std::ostream &os, DimensionalityMismatchEx &DimMisEx)
    {
        std::cout << DimMisEx.getName() << "( " << DimMisEx.getDim1() << ", " << DimMisEx.getDim2() << ")" << std::endl;
        return os;
    }

    std::ostream &Clustering::operator<<(std::ostream &os, OutOfBoundsEx &OOBEx)
    {
        std::cout << OOBEx.getName() << "( " << OOBEx.getIndex() << " )" << std::endl;
        return os;
    }

    std::ostream &Clustering::operator<<(std::ostream &os, RemoveFromEmptyEx &RemoveEmpt)
    {
        std::cout << RemoveEmpt.getName() << "( " << RemoveEmpt.getId() << " )" << std::endl;
        return os;
    }
};
