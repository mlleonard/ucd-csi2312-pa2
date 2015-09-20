//
// Created by Madeline Leonard on 9/18/15.
//

#include "Cluster.h"
using namespace Clustering;

/*Cluster::Cluster(const Cluster&)
{

}*/

void Cluster::add(const PointPtr & sourcePoint)
{
    bool moreToSearch;
    Lnode* predLoc;
    Lnode* newNode;
    current = points;

    if (size=0)
    {
        newNode = new Lnode;
        newNode->p = sourcePoint;

        newNode->next = current;
        predLoc->next = newNode;

        size++
    }

    else if (size>0)
    {

    }
    while(moreToSearch)
    {
        if (current -> p < sourcePoint)
        {
            predLoc = current;
            current = current ->next;
            moreToSearch = (current != nullptr);
        }
        else
        {
            moreToSearch = false;
        }
        newNode = new Lnode;
        newNode->p = sourcePoint;

        if(predLoc == nullptr)
        {
            newNode->next = current;
            predLoc->next = newNode;
        }

        size++;
    }

    Lnode node;

    node.p = sourcePoint;
    node.next = nullptr;




}
