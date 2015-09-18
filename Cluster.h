//
// Created by Madeline Leonard on 9/18/15.
//

#ifndef CLUSTERING_CLUSTER_H
#define CLUSTERING_CLUSTER_H

#include "Point.h"

namespace Clustering {

    typedef Point *PointPtr;
    typedef struct Lnode *LnodePtr;

    struct{

        PointPtr p;
        LnodePtr next;

    };
}


class Cluster {

};


#endif //UCD_CSI2312_PA2_CLUSTER_H
