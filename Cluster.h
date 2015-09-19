//
// Created by Madeline Leonard on 9/18/15.
//

#ifndef CLUSTERING_CLUSTER_H
#define CLUSTERING_CLUSTER_H

#include "Point.h"

namespace Clustering {

    typedef Point *PointPtr;
    typedef struct Lnode *LnodePtr;

    struct LinkedList{

        PointPtr p;
        LnodePtr next;

    };

    class Cluster{
        int size;
        LnodePtr points;

    public:

        Cluster() : size(0), points{nullptr} {};    //default constructor

        Cluster(const Cluster&);                    //copy constructor
        Cluster &operator=(const Cluster&);         //overloaded operator
        ~Cluster();                                 //destructor

        //Mutators which call add and remove

        void add(const PointPtr&);
        const PointPtr &remove(const PointPtr&);






    };
}


class Cluster {

};


#endif //UCD_CSI2312_PA2_CLUSTER_H
