//
// Created by Madeline Leonard on 10/26/15.
//

#ifndef UCD_CSI2312_PA2_KMEANS_H
#define UCD_CSI2312_PA2_KMEANS_H

#include "Cluster.h"
#include <iostream>
#include <vector>


namespace Clustering{

    class Cluster;
    class KMeans
    {


    public:
        double scoreDiff;
        static const double SCORE_DIFF_THRESHOLD;
        int k;
        KMeans() : scoreDiff(SCORE_DIFF_THRESHOLD-1) {};

        double computeClusteringScore(std::vector<Cluster>& clusterArray);
        double computeAbsoluteDifference(std::vector<Cluster>& clusterArray, KMeans& myK);

        void setScoreDifference(double);
        double getScoreDifference() {return scoreDiff;}
        void setK(int my_k) { k = my_k; }
        double getK() {return k;}


    };



};


#endif //UCD_CSI2312_PA2_KMEANS_H
