//
// Created by Madeline Leonard on 9/20/15.
//

#include "Cluster.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::stringstream;

namespace Clustering {

    Cluster::Cluster(const Cluster &cluster)
    {
        head = cluster.head;
        currentNode = cluster.currentNode;
        size = cluster.size;
    }
    Cluster& Cluster::operator=(const Cluster& source)
    {
        LnodePtr tempNode;

        for(tempNode = source.head; tempNode!= nullptr; tempNode = tempNode->next)
        {
          this->add(tempNode->value);
        }
    }

    void Cluster::add(const pointPtr sourcePoint) {

        LnodePtr newNode;
        newNode = new Lnode;
        currentNode = head;
        if (size == 0) {
            (newNode->value) = sourcePoint;

            (newNode->next) = nullptr;
            head = newNode;
            size++;
            return;

        }


        for (currentNode = head; currentNode != nullptr; currentNode = currentNode->next) {
            if (size == 1) {
                if ((*(currentNode->value) > (*sourcePoint))) {
                    (newNode->value) = sourcePoint;
                    (newNode->next) = currentNode;
                    head = newNode;
                }
                else {
                    (newNode->value) = sourcePoint;
                    (newNode->next) = nullptr;
                    (currentNode->next) = newNode;
                }
                size++;
                return;
            }

            if ((currentNode->next) == nullptr) {

                (newNode->value) = sourcePoint;
                (newNode->next) = nullptr;
                (currentNode->next) = newNode;

                size++;

                return;
            }

            else if (*((currentNode->next)->value) > (*sourcePoint)) {

                (newNode->value) = sourcePoint;   //set value in newNode to sourcePoint
                (newNode->next) = (currentNode->next);     //set tempNode Ptr to nex node
                (currentNode->next) = newNode;

                size++;

                return;
            }

        }

    }



    void Cluster::remove(const pointPtr sourcePoint) {
        LnodePtr deleteNode;
        deleteNode = new Lnode;


        for(currentNode = head; currentNode!=nullptr; currentNode = currentNode->next)
        {
            if ( (head->value) == sourcePoint)
            {
                deleteNode->next = head;
                head = head->next;
                size--;

                delete deleteNode;
                return;

            }
            else if( currentNode->next == nullptr)
            {
                return;
            }
            else if( ((currentNode->next)->value) == sourcePoint )
            {
                if(currentNode == head)
                {
                    deleteNode = currentNode->next;
                    head = ((currentNode->next)->next);
                    delete deleteNode;
                    size--;
                    return;
                }
                else
                {
                    deleteNode = currentNode->next;
                    (currentNode->next) = ((currentNode->next)->next);
                    delete deleteNode;
                    size--;
                    return;
                }
            }

        }

    }

    std::ostream &operator<<(std::ostream &os, Cluster &cluster) {
        cluster.currentNode = cluster.head;




        for (cluster.currentNode; cluster.currentNode != nullptr; cluster.currentNode = cluster.currentNode->next)
        {

            cout << *(cluster.currentNode->value);
            cout << ": " << cluster._id << endl;

        }



        return os;
    }

    std::istream &operator>>(std::istream &is, Cluster &cluster) {
        string line;


        stringstream pointstream;


        while (getline(is, line)) {

            Point *tempPoint;
            tempPoint = new Point;

            stringstream lineStream(line);

            lineStream >> *tempPoint;

            cluster.add(tempPoint);

        }


        return is;
    }


    bool operator==(const Cluster &lhs, const Cluster &rhs) {
        bool checking = true;

        LnodePtr lhsPtr;
        LnodePtr rhsPtr;

        lhsPtr = lhs.head;
        rhsPtr = rhs.head;


        while (checking) {
            if ((*(lhsPtr->value)) == (*(rhsPtr->value))) {
                if (((lhsPtr->next) == nullptr) && ((rhsPtr->next) == nullptr)) {
                    return true;
                }
                checking = true;

                lhsPtr = (lhsPtr->next);
                rhsPtr = (rhsPtr->next);

            }
            else {
                checking = false;
            }
        }

        return checking;
    }

    bool operator!=(const Cluster &lhs, const Cluster &rhs) {
        bool checking = true;

        LnodePtr lhsPtr;
        LnodePtr rhsPtr;

        lhsPtr = lhs.head;
        rhsPtr = rhs.head;


        while (checking) {
            if ((*(lhsPtr->value)) != (*(rhsPtr->value))) {
                if (((lhsPtr->next) == nullptr) && ((rhsPtr->next) == nullptr)) {
                    return true;
                }
                checking = true;

                lhsPtr = (lhsPtr->next);
                rhsPtr = (rhsPtr->next);

            }
            else {
                checking = false;
            }
        }

        return checking;
    }

    Cluster &Cluster::operator+=(const Cluster &rhs) {
        LnodePtr rhsPtr;

        for (currentNode = head; currentNode!=nullptr; currentNode = currentNode->next)
        {

            for(rhsPtr = rhs.head; rhsPtr != nullptr; rhsPtr = rhsPtr->next)
            {
                if(currentNode->value != rhsPtr->value)
                {
                    this->add(rhsPtr->value);
                }

            }
        }

        return *this;
    }


    Cluster &Cluster::operator-=(const Cluster &rhs) {
        LnodePtr rhsPtr;


        for (currentNode = head; currentNode!=nullptr; currentNode = currentNode->next)
        {

            for(rhsPtr = rhs.head; rhsPtr != nullptr; rhsPtr = rhsPtr->next)
            {
                if(currentNode->value == rhsPtr->value)
                {
                    this->remove(rhsPtr->value);
                }

            }
        }



        return *this;
    }

    const Cluster operator+(const Cluster &lhs, const Cluster &rhs) {

        LnodePtr rhsPtr;
        LnodePtr lhsPtr;
        Cluster *clusterPtr;
        clusterPtr = new Cluster;

        *clusterPtr = lhs;


        for(lhsPtr = lhs.head; lhsPtr != nullptr; lhsPtr = lhsPtr->next )
        {
            for(rhsPtr = rhs.head; rhsPtr != nullptr; rhsPtr = rhsPtr->next)
            {

                clusterPtr->add(rhsPtr->value);

            }
        }


        return *clusterPtr;
    }

    const Cluster operator-(const Cluster &lhs, const Cluster &rhs) {
        LnodePtr rhsPtr;

        LnodePtr lhsPtr;
        Cluster *clusterPtr;
        clusterPtr = new Cluster;

        *clusterPtr = lhs;


        for(lhsPtr = lhs.head; lhsPtr != nullptr; lhsPtr = lhsPtr->next )
        {
            for(rhsPtr = rhs.head; rhsPtr != nullptr; rhsPtr = rhsPtr->next)
            {
                if(lhsPtr->value == rhsPtr->value)
                {
                    clusterPtr->remove(rhsPtr->value);
                }
            }
        }


        return *clusterPtr;
    }


    const Cluster operator+( const Cluster &lhs, const pointPtr &rhs)
    {
        Cluster *clusterPointer;
        clusterPointer = new Cluster();

        (*clusterPointer)=lhs;

        clusterPointer->add(rhs);

        return *clusterPointer;
    }

    const Cluster operator-( const Cluster &lhs, const pointPtr &rhs)
    {
        Cluster *clusterPointer;
        clusterPointer = new Cluster();

        (*clusterPointer)=lhs;

        clusterPointer->remove(rhs);

        return *clusterPointer;
    }

    Cluster::~Cluster()
    {

        for (currentNode = head; currentNode!= nullptr; currentNode = currentNode->next)
        {
            head=(currentNode->next);
            delete currentNode;
        }


        return;

    }


    void Cluster::setCentroid(const Point &point)
    {
        _centroid = point;

    }


    const Point Cluster::getCentroid()
    {
        return _centroid;
    }

    const Point Cluster::computeCentroid()
    {
        double sumVal = 0;
        double averageVal = 0;
        int sumDim = 0;
        int averageDim = 0;

        for(currentNode = head; currentNode != nullptr; currentNode = currentNode->next)
        {
            sumDim += currentNode->value->getDim();
        }

        averageDim = sumDim/size;

        currentNode = head;
        for (int i = 0; i < ((currentNode->value)->getDim()); i++)
        {


            for (currentNode = head; currentNode != nullptr; currentNode = currentNode->next)
            {
                sumVal += (currentNode->value->getValue(i));

            }

            averageVal = sumVal/size;

            _centroid.setValue(i, averageVal);

            currentNode = head;
            sumVal = 0;
            averageVal= 0;
        }

        return _centroid;
    }

    unsigned int Cluster::_idGenerator()
    {
        static unsigned int id = 0;

        id++;

        return id;

    }

    Cluster::Move::Move(const pointPtr &ptr, Cluster *from, Cluster *to)
    {
        movePoint = ptr;
        move_from = from;
        move_to = to;

    }


    void Cluster::Move::Perform()
    {
        move_from->remove(movePoint);
        move_to->add(movePoint);
    }

};


