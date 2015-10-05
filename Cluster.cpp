//
// Created by Madeline Leonard on 9/20/15.
//

#include "Cluster.h"
namespace Clustering {

    Cluster::Cluster(const Cluster &cluster)
    {
        head = cluster.head;
        currentNode = cluster.currentNode;
        size = cluster.size;
    }

    void Cluster::add(const pointPtr sourcePoint) {

        nodePtr newNode;
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
        nodePtr deleteNode;
        deleteNode = new Lnode;


        for(currentNode = head; currentNode!=nullptr; currentNode = currentNode->next)
        {
            if ( *(head->value) == *sourcePoint)
            {
                deleteNode->next = head;
                head = head->next;
                size--;

                delete deleteNode;

            }
            else if( currentNode->next == nullptr)
            {
                return;
            }
            else if( (*(currentNode->next)->value) == *sourcePoint )
            {
                if(currentNode == head)
                {
                    deleteNode = currentNode->next;
                    head = ((currentNode->next)->next);
                    delete deleteNode;
                    size--;
                }
                else
                {
                    deleteNode = currentNode->next;
                    (currentNode->next) = ((currentNode->next)->next);
                    delete deleteNode;
                    size--;
                }
            }

        }

    }

    std::ostream &operator<<(std::ostream &os, Cluster &cluster) {
        cluster.currentNode = cluster.head;
        for (int i = 0; i < cluster.size; i++) {
            for (int j = 0; j < (((cluster.currentNode)->value)->getDim()); j++) {
                os << (((cluster.currentNode)->value)->getValue(j)) << " ";
            }
            std::cout << std::endl;
            cluster.currentNode = cluster.currentNode->next;
        }

        return os;
    }

    std::istream &operator>>(std::istream &is, Cluster &cluster) {
        int dim;
        double value = 0;

        std::cout << "How many dimensions does your point have" << std::endl;
        std::cin >> dim;

        pointPtr myPoint;
        myPoint = new Point;
        myPoint->resize(dim);

        for (int i = 0; i < dim; i++) {
            std::cout << "Please enter the values of that point" << std::endl;
            std::cin >> value;
            myPoint->setValue(i,value);
        }


        cluster.add(myPoint);


        return is;
    }

    bool operator==(const Cluster &lhs, const Cluster &rhs) {
        bool checking = true;

        nodePtr lhsPtr;
        nodePtr rhsPtr;

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

        nodePtr lhsPtr;
        nodePtr rhsPtr;

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
        bool checkinglhs = true;
        bool checkingrhs = true;
        currentNode = head;
        nodePtr rhsPtr;
        rhsPtr = rhs.head;


        while (checkinglhs) {

            while (checkingrhs) {
                if (((rhsPtr->next)->value) == ((currentNode->next)->value)) {
                    currentNode = (currentNode->next);
                    checkingrhs = true;
                }
                else if (((currentNode->next) = nullptr)) {
                    checkingrhs = false;
                }
                else {
                    this->add((rhs.currentNode)->value);
                    checkingrhs = false;
                }

            }

            if ((rhsPtr->next) == nullptr) {
                checkinglhs = false;
            }
            rhsPtr = (rhsPtr->next);
        }

        return *this;
    }


    Cluster &Cluster::operator-=(const Cluster &rhs) {
        bool checkinglhs = true;
        bool checkingrhs = true;
        currentNode = head;
        nodePtr rhsPtr;
        rhsPtr = rhs.head;


        while (checkinglhs) {

            while (checkingrhs) {
                if (((rhsPtr->next)->value) == ((currentNode->next)->value)) {
                    currentNode = (currentNode->next);
                    checkingrhs = true;
                }
                else if (((currentNode->next) = nullptr)) {
                    checkingrhs = false;
                }
                else {
                    this->remove((rhs.currentNode)->value);
                    checkingrhs = false;
                }

            }

            if ((rhsPtr->next) == nullptr) {
                checkinglhs = false;
            }
            rhsPtr = (rhsPtr->next);
        }

        return *this;
    }

    const Cluster operator+(const Cluster &lhs, const Cluster &rhs) {
        bool checkinglhs = true;
        bool checkingrhs = true;
        nodePtr rhsPtr;
        rhsPtr = rhs.head;

        nodePtr lhsPtr;
        lhsPtr = lhs.head;
        Cluster *clusterPtr;
        clusterPtr = new Cluster;


        while (checkinglhs) {

            while (checkingrhs) {
                if (((rhsPtr->next)->value) == ((lhsPtr->next)->value)) {
                    lhsPtr = (lhsPtr->next);
                    checkingrhs = true;
                }
                else if (((lhsPtr->next) = nullptr)) {
                    checkingrhs = false;
                }
                else {
                    clusterPtr->add((rhs.currentNode)->value);
                    checkingrhs = false;
                }

            }

            if ((rhsPtr->next) == nullptr) {
                checkinglhs = false;
            }
            rhsPtr = (rhsPtr->next);
        }

        return *clusterPtr;
    }

    const Cluster operator-(const Cluster &lhs, const Cluster &rhs) {
        bool checkinglhs = true;
        bool checkingrhs = true;
        nodePtr rhsPtr;
        rhsPtr = rhs.head;

        nodePtr lhsPtr;
        lhsPtr = lhs.head;
        Cluster *clusterPtr;
        clusterPtr = new Cluster;


        while (checkinglhs) {

            while (checkingrhs) {
                if (((rhsPtr->next)->value) == ((lhsPtr->next)->value)) {
                    lhsPtr = (lhsPtr->next);
                    checkingrhs = true;
                }
                else if (((lhsPtr->next) = nullptr)) {
                    checkingrhs = false;
                }
                else {
                    clusterPtr->remove((rhs.currentNode)->value);
                    checkingrhs = false;
                }

            }

            if ((rhsPtr->next) == nullptr) {
                checkinglhs = false;
            }
            rhsPtr = (rhsPtr->next);
        }

        return *clusterPtr;
    }


    const Cluster Clustering::operator+( const Cluster &lhs, const pointPtr &rhs)
    {
        Cluster *clusterPointer;
        clusterPointer = new Cluster();

        (*clusterPointer)=lhs;

        clusterPointer->add(rhs);

        return Cluster();
    }

    const Cluster Clustering::operator-( const Cluster &lhs, const pointPtr &rhs)
    {
        Cluster *clusterPointer;
        clusterPointer = new Cluster();

        (*clusterPointer)=lhs;

        clusterPointer->remove(rhs);

        return Cluster();
    }

    Cluster::~Cluster()
    {


    }
};


