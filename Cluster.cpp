//
// Created by Madeline Leonard on 9/20/15.
//

#include "Cluster.h"
//commenting thingssssss
namespace Clustering {
Cluster::Cluster(const Cluster &cluster)
{
    head = cluster.head;
    currentNode = cluster.currentNode;
    size = cluster.size;
}
    void Cluster::add(const pointPtr sourcePoint) {
        node *newNode;
        currentNode = head;

        if (size == 0) {
            newNode = new node;
            (newNode->value) = sourcePoint;

            (newNode->next) = head;
            head = newNode;
            size++;
            currentNode = nullptr;
        }

        if ((currentNode->value) > sourcePoint)
        {
            newNode = new node;
            (newNode->value) = sourcePoint;
            (newNode->next) = head;
            head = newNode;

            size++;
            currentNode = nullptr;
        }
        for(currentNode = head; currentNode!= nullptr; currentNode = currentNode->next)
        {
            if (((currentNode->next)->value) > sourcePoint)
            {
                newNode = new node;     //create new node

                (newNode->value) = sourcePoint;   //set value in newNode to sourcePoint
                (newNode->next) = (currentNode->next);     //set tempNode Ptr to nex node
                (currentNode->next) = newNode;

                size++;

                return;
            }

            else if(((currentNode->next)->value) == nullptr)
            {
                newNode =  new node;

                (newNode->value) = sourcePoint;
                (newNode->next) = nullptr;
                (currentNode->next) = newNode;

                size++;

                return;
            }
        }


    }



    void Cluster::erase(const pointPtr sourcePoint) {
        bool searching = true;
        currentNode = head;

        while (searching == true) {
            if ((currentNode->value) == sourcePoint) {
                if (((currentNode->before) = nullptr)) {
                    head = (currentNode->next);
                    ((currentNode->next)->before) = nullptr;
                    delete[] currentNode;
                    size--;
                }
                else if (((currentNode->next) = nullptr)) {
                    ((currentNode->before)->next) = nullptr;
                    delete[] currentNode;
                    size--;
                }
                else {
                    ((currentNode->before)->next) = (currentNode->next);
                    ((currentNode->next)->before) = (currentNode->before);
                    delete[] currentNode;
                    size--;
                }
            }
            else {
                currentNode = (currentNode->next);
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
            myPoint->insert(value);
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
                    this->erase((rhs.currentNode)->value);
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
                    clusterPtr->erase((rhs.currentNode)->value);
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

        clusterPointer->erase(rhs);

        return Cluster();
    }
};

