//
// Created by Madeline Leonard on 9/20/15.
//

#include "Cluster.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Exception.h"


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
        _centroid = std::numeric_limits<double>::infinity();
    }
    Cluster& Cluster::operator=(const Cluster& source)
    {

        LnodePtr tempNode;

        this->_points.assign(source._points.begin(), source._points.end());

//
//        for(tempNode = source.head; tempNode!= nullptr; tempNode = tempNode->next)
//        {
//
//            this->add(*tempNode->value);
//        }
        valid = false;
    }

    void Cluster::add(const Point & sourcePoint) {

        auto it2 = (this->_points.begin()++);

        if(*this->_points.begin() > sourcePoint)
        {
            this->_points.push_front(sourcePoint);
        }

            //Todo create another else if statement here for if the sourcepoint is less than
            //it so that we iterate through the objects in points accurately??

        else
        {
            for ( auto it = this->_points.begin(); it != this->_points; it++)
            {
                if(*it2 > sourcePoint)
                {
                    this->_points.insert_after(it, sourcePoint);

                }
            }
        }

        for(auto it = this->_points.begin(); it != this->_points.end(); it++)
        {
            if(*it > sourcePoint)
            {
                this->_points.
            }
        }















//        LnodePtr newNode;
//        newNode = new Lnode;
//        currentNode = head;
//        if (size == 0) {
//
//            *(newNode->value) = sourcePoint;
//
//            (newNode->next) = nullptr;
//            head = newNode;
//            size++;
//            return;
//
//        }
//
//
//        for (currentNode = head; currentNode != nullptr; currentNode = currentNode->next) {
//            if (size == 1) {
//                if ((*(currentNode->value) > (sourcePoint))) {
//                    *(newNode->value) = sourcePoint;
//                    (newNode->next) = currentNode;
//                    head = newNode;
//                }
//                else {
//                    *(newNode->value) = sourcePoint;
//                    (newNode->next) = nullptr;
//                    (currentNode->next) = newNode;
//                }
//                size++;
//                return;
//            }
//
//            if ((currentNode->next) == nullptr) {
//
//                *(newNode->value) = sourcePoint;
//                (newNode->next) = nullptr;
//                (currentNode->next) = newNode;
//
//                size++;
//
//                return;
//            }
//
//            else if (*((currentNode->next)->value) > (sourcePoint)) {
//
//                *(newNode->value) = sourcePoint;   //set value in newNode to sourcePoint
//                (newNode->next) = (currentNode->next);     //set tempNode Ptr to nex node
//                (currentNode->next) = newNode;
//
//                size++;
//
//                return;
//            }
//
//        }

        valid = false;
    }



    void Cluster::remove(const Point & sourcePoint) {
        LnodePtr deleteNode;
        deleteNode = new Lnode;

        try {
            if (size == 0) {
                throw RemoveFromEmptyEx("Cluster remove when empty Error", this->_id);
            }
        }catch(RemoveFromEmptyEx &cException)
        {
            std::cout << cException;
        }


        for(currentNode = head; currentNode!=nullptr; currentNode = currentNode->next)
        {
            if ( *(head->value) == sourcePoint)
            {
                deleteNode = head;
                head = head->next;
                size--;

                delete deleteNode;
                return;

            }
            else if( currentNode->next == nullptr)
            {
                return;
            }
            else if( (*(currentNode->next)->value) == sourcePoint )
            {
                if(currentNode == head)
                {
                    deleteNode = currentNode->next;
                    currentNode->next = deleteNode->next;
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

        valid = false;
    }

    std::ostream &operator<<(std::ostream &os, Cluster &cluster) {
        cluster.currentNode = cluster.head;




        for (cluster.currentNode; cluster.currentNode != nullptr; cluster.currentNode = cluster.currentNode->next)
        {

            cout << *(cluster.currentNode->value);
            cout << ": " << cluster._id << endl;

        }



        cluster.valid = false;
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

            cluster.add(*tempPoint);

        }


        cluster.valid = false;
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
                    this->add(*rhsPtr->value);
                }

            }
        }

        valid = false;
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
                    this->remove(*rhsPtr->value);
                }

            }
        }



        valid = false;
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

                clusterPtr->add(*rhsPtr->value);

            }
        }


        clusterPtr->valid = false;
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
                    clusterPtr->remove(*rhsPtr->value);
                }
            }
        }


        clusterPtr->valid = false;
        return *clusterPtr;
    }


    const Cluster operator+( const Cluster &lhs, const pointPtr &rhs)
    {
        Cluster *clusterPointer;
        clusterPointer = new Cluster();

        (*clusterPointer)=lhs;

        clusterPointer->add(*rhs);

        clusterPointer->valid = false;
        return *clusterPointer;
    }

    const Cluster operator-( const Cluster &lhs, const pointPtr &rhs)
    {
        Cluster *clusterPointer;
        clusterPointer = new Cluster();

        (*clusterPointer)=lhs;

        clusterPointer->remove(*rhs);

        clusterPointer->valid = false;
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
        valid = true;
    }


    const Point Cluster::getCentroid()
    {
        return _centroid;
    }

    const Point Cluster::computeCentroid()
    {
        try {
            if (size == 0) {
                throw RemoveFromEmptyEx("Cluster computeCentroid when empty Error", this->_id);
            }
        }catch(RemoveFromEmptyEx &cException)
        {
            std::cout << cException;
        }

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

        valid = true;
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
        move_from->remove(*movePoint);
        move_to->add(*movePoint);

        move_from->valid = false;
        move_to->valid = false;
    }

    void Cluster::pickPoints(int k, pointPtr pointArray[])
    {
        double sumVal = 0;
        double averageVal = 0;
        int clusterSections;
        int count  = 0;

        clusterSections = size/k;

        currentNode = head;
        while (currentNode != nullptr) {
            for (int i = 0; i < k; i++)
            {

                pointArray[i] = (currentNode->value);

                if(size == (clusterSections))
                {
                    return;
                }

                while (count < (clusterSections) && currentNode->next != nullptr)
                {
                    currentNode = currentNode->next;
                    count ++;
                }
                count = 0;
            }


            pointArray[k-1] = (currentNode->value);

            currentNode = nullptr;

        }


    }


    double Cluster::intraClusterDistance() const
    {
        LnodePtr traverseNode;
        LnodePtr traverseNode_2;
        double sum = 0;

        for ( traverseNode = head; traverseNode != nullptr; traverseNode = traverseNode->next)
        {
            for( traverseNode_2 = traverseNode->next; traverseNode_2 != nullptr; traverseNode_2 = traverseNode_2->next)
            {
                sum += traverseNode->value->distanceTo(*(traverseNode_2->value));
            }

        }

        return sum;
    }

    double interClusterDistance(const Cluster &c1, const Cluster &c2)
    {
        LnodePtr traverseNode;
        LnodePtr traverseNode_2;
        double sum = 0;

        if (c1.size >= c2.size)
        {
            for ( traverseNode = c2.head; traverseNode != nullptr; traverseNode = traverseNode->next)
            {
                for( traverseNode_2 = c1.head; traverseNode_2 != nullptr; traverseNode_2 = traverseNode_2->next)
                {
                    sum += traverseNode->value->distanceTo(*(traverseNode_2->value));
                }
            }
        }
        else
        {
            for ( traverseNode = c1.head; traverseNode != nullptr; traverseNode = traverseNode->next)
            {
                for( traverseNode_2 = c2.head; traverseNode_2 != nullptr; traverseNode_2 = traverseNode_2->next)
                {
                    sum += traverseNode->value->distanceTo(*(traverseNode_2->value));
                }
            }

        }

        return sum;

    }

    int Cluster::getClusterEdges()
    {
        int edges;

        edges = ((size*(size-1))/2);

        return edges;
    }

    double interClusterEdges(const Cluster &c1, const Cluster &c2)
    {
        double edges = 0;

        edges = c1.size * c2.size;

        return edges;
    }
};























