//
// Created by Madeline Leonard on 10/26/15.
//

#ifndef UCD_CSI2312_PA2_KMEANS_H
#define UCD_CSI2312_PA2_KMEANS_H

#include "Cluster.h"
#include <iostream>

namespace Clustering{

    class KMeans
    {

    public:
        static double SCORE_DIFF_THRESHOLD;
        double computeClusteringScore();

    };



};


#endif //UCD_CSI2312_PA2_KMEANS_H
