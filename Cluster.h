//
// Created by Madeline Leonard on 9/20/15.
//

#ifndef _CLUSTER_H
#define _CLUSTER_H

#include "Point.h"

namespace Clustering{
typedef Clustering::Point* pointPtr;
typedef struct Lnode* LnodePtr;


    struct Lnode {
        //nodePtr before;
        LnodePtr next;
        pointPtr value;
        //node(pointPtr pt,nodePtr n) : value(pt), (n) {}
    };


    class Cluster {
        LnodePtr head;
        LnodePtr currentNode;
        int size;
    public:
        //Default Constructor
        Cluster() : head(nullptr), size(0) { };

        //Copy Constructor
        Cluster(const Cluster&);
        Cluster &operator=(const Cluster&);
        ~Cluster();

        void add(const pointPtr sourcePoint);
        void remove(const pointPtr sourcePoint);

        friend std::ostream &operator<<(std::ostream &os, Cluster &cluster);

        friend std::istream &operator>>(std::istream &is, Cluster &cluster);

        friend bool operator==(const Cluster &lhs, const Cluster &rhs);

        friend bool operator!=(const Cluster &lhs, const Cluster &rhs);

        Cluster &operator+=(const Cluster &rhs); // union
        Cluster &operator-=(const Cluster &rhs);

        friend const Cluster operator+(const Cluster &lhs, const Cluster &rhs);
        friend const Cluster operator-(const Cluster &lhs, const Cluster &rhs);
        friend const Cluster operator+(const Cluster &lhs, const pointPtr &rhs);
        friend const Cluster operator-(const Cluster &lhs, const pointPtr &rhs);
    };

};
#endif