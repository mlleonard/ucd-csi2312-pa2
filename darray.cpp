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

//**********Copy Constructor****************************

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
    delete [] arrayPointer;
}

void dArray::insert(const value_type& entry)
{
    if ( size == DEFAULT_CAPACITY )
    {
        resize(size+1);
    }
    arrayPointer[size] = entry;
    ++size;
}
void dArray::resize(size_type new_capacity)
{
    value_type *largerArray;

    largerArray = new value_type[new_capacity];
    copy(arrayPointer, arrayPointer+size, largerArray);
    delete [] arrayPointer;
    arrayPointer = largerArray;
    DEFAULT_CAPACITY = new_capacity;
}

Clustering::dArray::value_type dArray::getValue(size_type i)
{
    return arrayPointer[i];
}



        








