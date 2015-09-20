//
// Created by Madeline Leonard on 9/19/15.
//

#include "darray.h"
#include <iostream>
using namespace Clustering;
using namespace std;

dArray::dArray()
{
    DEFAULT_CAPACITY = 10;
    size = 0;
    arrayPointer = new value_type[DEFAULT_CAPACITY];
}

dArray::dArray(size_type initial_capacity)
{
    DEFAULT_CAPACITY = initial_capacity;
    size = 0;
    arrayPointer = new value_type[DEFAULT_CAPACITY];
}

dArray::dArray(const dArray& source)
{
    DEFAULT_CAPACITY = source.getDEFAULT_CAPACITY();
    arrayPointer = new value_type[DEFAULT_CAPACITY];

    for( int i = 0; i < source.getSize(); i++)
    {

        arrayPointer[i] = source.arrayPointer[i];
    }

    size = source.getSize();

}

dArray::~dArray()
{
    delete [] dArray;
}


        








