//
// Created by Madeline Leonard on 10/26/15.
//

#include "KMeans.h"
#include "Cluster.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

namespace Clustering {


    double KMeans::computeClusteringScore()
    {
        int k = 2;
        Cluster point_space;
        ifstream inFile("points.txt");
        inFile >> point_space;

        cout << "Please select a k" << endl;

        pointPtr pointArray[k];

        clusterPtr clusterArray[k];
        clusterArray[0] = &point_space;


        point_space.pickPoints(k, pointArray);

        for ( int i = 0; i < (k-1); i++)
        {

            Cluster *myCluster;
            myCluster = new Cluster;
            myCluster->setCentroid(*pointArray[i]);
            clusterArray[i+1] = myCluster;

        }

        double score;
        double scoreDiff = (SCORE_DIFF_THRESHOLD+1);

        while(scoreDiff >= SCORE_DIFF_THRESHOLD)
        {
            for ( int i = 0; i < k; i++)
            {
                for((clusterArray[i])->currentNode = (clusterArray[i])->head; (clusterArray[i])->currentNode != nullptr; (clusterArray[i])->currentNode = (clusterArray[i])->currentNode->next)
                {

                }
            }
        }

        return 0;
    }
};
