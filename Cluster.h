//
// Created by Madeline Leonard on 9/20/15.
//

#ifndef _CLUSTER_H
#define _CLUSTER_H

#include "Point.h"

namespace Clustering{
typedef Clustering::Point* pointPtr;
typedef struct node* nodePtr;


    struct node {
        nodePtr before;
        nodePtr next;
        pointPtr value;
    };


    class Cluster {
        nodePtr head;
        nodePtr currentNode;
        int size;
    public:
        //Default Constructor
        Cluster() : head(nullptr), size(0) { };

        //Copy Constructor
        //Cluster(const Cluster&);
        void add(const pointPtr sourcePoint);

        void erase(const pointPtr sourcePoint);

        friend std::ostream &operator<<(std::ostream &os, Cluster &cluster);

        friend std::istream &operator>>(std::istream &is, Cluster &cluster);

        friend bool operator==(const Cluster &lhs, const Cluster &rhs);

        friend bool operator!=(const Cluster &lhs, const Cluster &rhs);

        Cluster &operator+=(const Cluster &rhs); // union
        Cluster &operator-=(const Cluster &rhs);

        friend const Cluster operator+(const Cluster &lhs, const Cluster &rhs);
    };

};
#endif