//
// Created by Madeline Leonard on 9/19/15.
//

#ifndef UCD_CSI2312_PA2_DARRAY_H
#define UCD_CSI2312_PA2_DARRAY_H
#include <iostream>
#include "cluster.h"
#include "point.h"
using namespace Clustering;
using namespace std;



class dArray {
    typedef double value_type;
    typedef int size_type;
    size_type DEFAULT_CAPACITY;
    int size;
    double *arrayPointer;

    dArray();
    //constructor
    dArray(size_type initial_capacity);

    //copy constructor
    dArray(const dArray&);
    //destructor
    ~dArray();

    void resize();
    size_type getDEFAULT_CAPACITY() const {return DEFAULT_CAPACITY;}
    size_type getSize() const {return size;}
    bool isEmpty() const { return size == 0;}
    bool isFull() const { return size == DEFAULT_CAPACITY;}










};


#endif //UCD_CSI2312_PA2_DARRAY_H
