//
// Created by Madeline Leonard on 9/18/15.
//

#include "Point.h"
using namespace Clustering;

Point::Point(int m_dim)
{
    dim = m_dim;
}

Point::Point(int m_dim, double * m_values[])
{
    dim = m_dim;

    for (int i = 0; i<m_dim; i++)
    {
        values[i] = m_values[i];
    }

}

Point::Point(const Point & source)
{

    dim = source.getDim();

    for (int i = 0; i < dim; i++)
    {
        *(values+i) = source.getValue(dim);
    }

}

Point double* getValue(int dim)
{

}