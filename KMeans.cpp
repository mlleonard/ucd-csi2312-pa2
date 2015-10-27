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

    const double KMeans::SCORE_DIFF_THRESHOLD = 1;

    double KMeans::computeClusteringScore(Cluster clusterArray[])
    {

        double intraDisSum = 0;
        double interDisSum = 0;
        int intraEdgeSum = 0;
        double interEdgeSum = 0;

        double score = 0;

        for( int i = 0; i < k; i++)
        {
            intraDisSum += clusterArray[i].intraClusterDistance();
        }

        for (int i = 0; i < (k-1); i++)
        {
            for (int j = (i+1); j < k; j++)
            {
                interDisSum += interClusterDistance(clusterArray[i], clusterArray[j]);
            }
        }

        for (int i = 0; i < k; i++ )
        {
           intraEdgeSum += clusterArray[i].getClusterEdges();
        }

        for( int i = 0; i < (k-1); i++)
        {
            for (int j = (i+1); j < k; j++ )
            {
                interEdgeSum += interClusterEdges(clusterArray[i], clusterArray[j]);
            }
        }

        score = ((intraDisSum/interEdgeSum)/(interDisSum/interEdgeSum));


        return score;
    }

    double KMeans::computeAbsoluteDifference(Cluster clusterArray[], KMeans& myK) {

        double minDistance;
        int minCentroidDistance;
        double score;

        while(scoreDiff >= myK.SCORE_DIFF_THRESHOLD)
        {
            for ( int i = 0; i < (k-1); i++)
            {
                int j = 0;
                for((clusterArray[i]).currentNode = (clusterArray[i]).head; (clusterArray[i]).currentNode != nullptr; (clusterArray[i]).currentNode = (clusterArray[i]).currentNode->next)
                {
                    minDistance = (clusterArray[i].currentNode->value->distanceTo(clusterArray[i]._centroid));
                    minCentroidDistance = i;

                    if((minDistance) > (clusterArray[i].currentNode->value->distanceTo(clusterArray[j]._centroid)))
                    {
                        minDistance = (clusterArray[i].currentNode->value->distanceTo(clusterArray[j]._centroid));
                        minCentroidDistance = j;

                    }
                    if(j != i)
                    {
                        Cluster::Move pointMove(clusterArray[i].currentNode->value, &clusterArray[i], &clusterArray[j]);
                        pointMove.Perform();
                    }


                    j++;

                }
            }

            for ( int i = 0; i < k; i++)
            {
                if (clusterArray[i].valid == false)
                {
                    clusterArray[i].computeCentroid();
                }
            }

            score = myK.computeClusteringScore(clusterArray);

            cout << score;





        }
        return 0;
    }

    void KMeans::setScoreDifference(double d)
    {
        scoreDiff = d;
    }
};
