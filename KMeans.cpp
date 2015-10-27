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

        Cluster* clusterArray[k];
        clusterArray[0] = &point_space;
        double minDistance;
        int minCentroidDistance;


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
            for ( int i = 0; i < (k-1); i++)
            {
                int j = 0;
                for((clusterArray[i])->currentNode = (clusterArray[i])->head; (clusterArray[i])->currentNode != nullptr; (clusterArray[i])->currentNode = (clusterArray[i])->currentNode->next)
                {
                    minDistance = (clusterArray[i]->currentNode->value->distanceTo(clusterArray[i]->_centroid));
                    minCentroidDistance = i;

                    if((minDistance) > (clusterArray[i]->currentNode->value->distanceTo(clusterArray[j]->_centroid)))
                    {
                        minDistance = (clusterArray[i]->currentNode->value->distanceTo(clusterArray[j]->_centroid));
                        minCentroidDistance = j;

                    }
                    if(j != i)
                    {
                        Cluster::Move pointMove(clusterArray[i]->currentNode->value, clusterArray[i], clusterArray[j]);
                        pointMove.Perform();
                    }

                    j++;

                }
            }
        }

        return 0;
    }
};
