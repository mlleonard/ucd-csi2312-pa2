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

Point& Point::operator=(const Point& Source)
{
    dim = Source.getDim();

    for(int i = 0; i < dim; i++)
    {
        values[i] = Source.getValue(i);
    }

    return Point;
}
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
Point& Point::operator*=(const Point& source)
{
    double sum[];
    for(int i = 0; i<dim; i++)
    {
        sum[i] = values[i] * source.getValue(i);

    }

}