//
// Created by Madeline Leonard on 9/20/15.
//

#include "Point.h"
#include <cmath>

using namespace std;

namespace Clustering {

//***************CONSTRUCTORS**************
    Point::Point() {
        DEFAULT_DIM = 1;
        dim = 0;
        valuesArray = new value_type[DEFAULT_DIM];
    }

    Point::Point(size_type initial_capacity) {
        DEFAULT_DIM = initial_capacity;
        dim = 0;
        valuesArray = new value_type[DEFAULT_DIM];

    }

    Point::Point(size_type initial_capacity, value_type valuesArray) {

        DEFAULT_DIM = initial_capacity;
        dim = 0;


    }


// **************COPY_CONSTRUCTOR************
    Point::Point(const Point &source) {
        DEFAULT_DIM = source.DEFAULT_DIM;
        valuesArray = new value_type[DEFAULT_DIM];

        for (int i = 0; i < source.getDim(); i++) {
            valuesArray[i] = source.valuesArray[i];
        }

        dim = source.getDim();

    }

// ************Destructor*******************

    Point::~Point() {
        delete[] valuesArray;
    }

//***********Dynamic Member variables**************

/*Point::value_type Point::getValue(size_type i)
{
    return valuesArray[i];
}*/

    void Point::insert(const value_type entry) {
        if (dim == DEFAULT_DIM) {

            resize(dim + 1);
        }
        valuesArray[dim] = entry;
        ++dim;
    }

    void Point::resize(int new_capacity) {
        value_type *largerValuesArray;

        largerValuesArray = new value_type[new_capacity];

        for (int i = 0; i < dim; i++) {
            largerValuesArray[i] = valuesArray[i];
        }
        delete[] valuesArray;

        DEFAULT_DIM = new_capacity;

        valuesArray = new value_type[DEFAULT_DIM];

        for (int i = 0; i < dim; i++) {
            valuesArray[i] = largerValuesArray[i];
        }

        delete[] largerValuesArray;

    }

//***********Point Member Functions*****************

    double Point::distanceTo(Point &other) {
        value_type sum = 0;
        value_type distance = 0;

        for (int i = 0; i < dim; i++) {
            sum += pow((other.getValue(i) - valuesArray[i]), 2);
        }

        distance = sqrt(sum);

        return distance;
    }

    Point &Point::operator*=(double digit) {

        for (int i = 0; i < dim; i++) {
            this->valuesArray[i] = (this->getValue(i) * digit);
        }

        return *this;

    }

    Point &Point::operator/=(double digit) {

        for (int i = 0; i < dim; i++) {
            this->valuesArray[i] = (this->getValue(i) / digit);
        }

        return *this;
    }


    const Point Point::operator*(double digit) const {
        Point *productPoint;
        productPoint = new Point;

        for (int i = 0; i < dim; i++) {
            productPoint->insert(this->getValue(i) * digit);
        }


        return *productPoint;
    }

    const Point Point::operator/(double digit) {
        Point *productPoint;
        productPoint = new Point;

        for (int i = 0; i < dim; i++) {
            productPoint->insert(this->getValue(i) / digit);
        }

        return *productPoint;
    }


    Point &operator+=(Point &point1, const Point &point2) {

        for (int i = 0; i < point1.getDim(); i++) {
            point1.valuesArray[i] = ((point1.getValue(i)) + (point2.getValue(i)));
        }

        return point1;
    }

    Point &operator-=(Point &point1, const Point &point2) {
        for (int i = 0; i < point1.getDim(); i++) {
            point1.valuesArray[i] = (point1.getValue(i) - point2.getValue(i));
        }

        return point1;
    }


    const Point operator-(const Point &point1, const Point &point2) {
        Point *differencePoint;
        differencePoint = new Point;

        for (int i = 0; i < point1.getDim(); i++) {
            differencePoint->insert(point1.getValue(i) - point2.getValue(i));
        }

        return *differencePoint;
    }

    const Point operator+(const Point &point1, const Point &point2) {
        Point *sumPoint;
        sumPoint = new Point;

        sumPoint->resize(point1.getDim());

        for (int i = 0; i < point1.getDim(); i++) {
            sumPoint->insert((point1.getValue(i)) + (point2.getValue(i)));
        }


        return *sumPoint;
    }

    bool operator==(const Point &point1, const Point &point2) {

        for (int i = 0; i<point1.getDim(); i++)
        {
            if(point1.getValue(i) != point2.getValue(i))
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Point &point1, const Point &point2) {

        if(point1.getDim() != point2.getDim())
        {
            return true;
        }
        for (int i = 0; i < point1.getDim(); i++)
        {
            if (point1.getValue(i) != point2.getValue(i))
            {
                return true;
            }
        }
        return false;
    }

    bool operator<(const Point &point1, const Point &point2) {
        bool checking = true;

        for (int i = 0; i < point1.getDim(); i++) {
            if (point1.getValue(i) < point2.getValue(i)) {
                checking = true;
            }
            else {
                checking = false;
            }
        }

        return checking;
    }

    bool operator>(const Point &point1, const Point &point2) {
        bool checking = true;

        for (int i = 0; i < point1.getDim(); i++) {
            if (point1.getValue(i) > point2.getValue(i)) {
                checking = true;
            }
            else {
                checking = false;
            }
        }
        return checking;
    }

    bool operator<=(const Point &point1, const Point &point2) {
        bool checking = true;

        for (int i = 0; i < point1.getDim(); i++) {
            if (point1.getValue(i) <= point2.getValue(i)) {
                checking = true;
            }
            else {
                checking = false;
            }
        }

        return checking;
    }

    bool operator>=(const Point &point1, const Point &point2) {
        bool checking = true;

        for (int i = 0; i <= point1.getDim(); i++) {
            if (point1.getValue(i) >= point2.getValue(i)) {
                checking = true;
            }
            else {
                checking = false;
            }
        }

        return checking;
    }

    std::ostream &operator<<(ostream &os, const Point &point) {
        for (int i = 0; i < point.getDim(); i++) {
            os << point.getValue(i) << " ";
        }
        return os;
    }


    std::istream &operator>>(istream &is, Point &point) {

        int numPoints;
        double values = 0;

        cout << "How many points would you like to enter" << endl;
        cin >> numPoints;

        for (int i = 0; i < numPoints; i++) {
            cout << "Please insert values";

            point.insert(values);
        }
        return is;
    }

    Point &Point::operator=(const Point &point)
    {
        for( int i = 0; i<point.getDim(); i++)
        {
            this->valuesArray[i] = point.getValue(i);
        }
        this->dim = point.getDim();


        return *this;
    }
};





