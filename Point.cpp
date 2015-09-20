//
// Created by Madeline Leonard on 9/18/15.
//
#include <iostream>
#include "Point.h"
#include <cmath>
using namespace Clustering;

//****************Constructors**********************

Point::Point(int m_dim)
{
    dim = m_dim;
}

Point::Point(int m_dim, double  m_values[])
{
    dim = m_dim;

    for (int i = 0; i<m_dim; i++)
    {
        values[i] = m_values[i];
    }

}

//***************Big3**********************************
//TODO fix copy constructor
Point::Point(const Point & source)
{
    int m_dim;

    //std::cout << "sourcegetdim is " << source.getDim() << std::endl;
    m_dim= source.getDim();
    dim = m_dim;
    //std::cout << "sourcegetdim is " << source.getDim() << std::endl;

    for (int i = 0; i < m_dim; i++)
    {
        values[i] = source.getValue(i);
        //std::cout << "sourcegetdim is " << source.getDim() << std::endl;
    }


}
//TODO overload operator, all is well here except the dynamic allocation of the point class which is needed
/*Point& Point::operator=(const Point& Source)
{
    dim = Source.getDim();

    for(int i = 0; i < dim; i++)
    {
        values[i] = Source.getValue(i);
    }

    return Point;
}*/
Point::~Point() {
}

void Point::setValue(int m_dim, double m_value) {

    values[m_dim] = m_value;

}

int Point::getDim() const
{
    //std::cout << dim;
    return dim;
}

double Point::getValue(int m_dim ) const
{
    return values[m_dim];
}

double Point::distanceTo(const Point& other)
{
    double sum=0;
    double distance=0;

    for(int i=0; i<dim; i++)
    {
        sum += pow((other.getValue(i)-values[i]),2);
    }
    distance = sqrt(sum);


    return distance;
}

//**********************Overlaoded operations**************
Point& Point::operator*=(const Point& source)
{

    double sum[dim];
    for(int i = 0; i<dim; i++)
    {
        sum[i] = values[i] * source.getValue(i);
    }

    Point product(dim, sum);

    return product;
}


//***********************Overloaded comparisons***************

bool operator>(const Point &a, const Point &b)
{

    bool checking;
    int biggerDim = 0;
    int smallerDim = 0;
    int aDim = a.getDim();
    int bDim = b.getDim();


    if (bDim > aDim)
    {
        biggerDim = bDim;
        smallerDim = aDim;
        while (checking) {
            int count = 0;

            if (a.getValue(count) == b.getValue(count) && count < smallerDim)
            {
                count++;
            }
            else if (a.getValue(count) == b.getValue(count) && count == smallerDim)
            {
                checking = false;
            }
            else if (a.getValue(count) > b.getValue(count))
            {
                return true;
            }

            else
            {
                checking = false;
            }

        }
        return false;
    }

    else
    {
        biggerDim = aDim;
        smallerDim = bDim;
        while (checking)
        {
            int count = 0;

            if (a.getValue(count) == b.getValue(count) && count < smallerDim)
            {
                count++;
            }
            else if (a.getValue(count) == b.getValue(count) && count == smallerDim)
            {
                 checking = false;
            }
            else if (a.getValue(count) < b.getValue(count))
            {
                return false;
            }
            else
            {
                checking = false;
            }
        }
        return true;
    }



}
