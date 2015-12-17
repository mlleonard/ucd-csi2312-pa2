//
// Created by Madeline Leonard on 9/20/15.
//

#include "Point.h"
#include "Exception.h"
#include <cmath>
#include <fstream>
#include <sstream>


using std::stringstream;
using std::string;
using std::ifstream;

using namespace std;

namespace Clustering {

//***************CONSTRUCTORS**************
    Point::Point() {
        DEFAULT_DIM = 1;
        dim = 0;
        //valuesArray = new value_type[DEFAULT_DIM];
        _idgenerator();
    }

    Point::Point(size_type initial_capacity) {
        DEFAULT_DIM = initial_capacity;
        dim = 0;
        //valuesArray = new value_type[DEFAULT_DIM];
        _idgenerator();

    }

    Point::Point(size_type initial_capacity, value_type valuesArray) {

        DEFAULT_DIM = initial_capacity;
        dim = 0;
        _idgenerator();

    }


// **************COPY_CONSTRUCTOR************
    Point::Point(const Point &source) {
        dim = source.getDim();
        DEFAULT_DIM = source.DEFAULT_DIM;
        //valuesArray = new value_type[DEFAULT_DIM];


        for ( int i = 0; i < dim; i++)
        {
            _values.push_back(source.getValue(i));
        }


//        for (int i = 0; i < source.getDim(); i++) {
//            valuesArray[i] = source.valuesArray[i];
//        }

        //dim = source.getDim();

    }

// ************Destructor*******************

    Point::~Point() {
        //delete _values;
        //delete[] valuesArray;
        //delete this;
    }

//***********Dynamic Member variables**************

/*Point::value_type Point::getValue(size_type i)
{
    return valuesArray[i];
}*/

    void Point::setValue(int dimEntry, double valueEntry )
    {
        if ( dimEntry > dim)
        {
            _values.push_back(valueEntry);
        }
        else {
            _values[dimEntry] = valueEntry;
        }
//        if (dim == DEFAULT_DIM) {
//
//            resize(dim + 1);
//        }
//        valuesArray[dimEntry] = valueEntry;
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

        for ( int i = 0; i < this->getDim(); i++)
        {
            sum+= pow((other.getValue(i)-_values[i]), 2);
        }

        distance = sqrt(sum);

        return distance;


//        value_type sum = 0;
//        value_type distance = 0;
//
//        for (int i = 0; i < this->getDim(); i++)
//        {
//            //cout << other.getValue(i) << " ";
//            //cout << valuesArray[i] << endl;
//            sum += pow((other.getValue(i) - valuesArray[i]), 2);
//        }
//
//        distance = sqrt(sum);
//
//        //cout << distance << endl;
//        return distance;
    }

    Point &Point::operator*=(double digit) {

        for (int i = 0; i< dim; i++)
        {
            this->_values[i] = (this->getValue(i) * digit );
        }

//        for (int i = 0; i < dim; i++) {
//            this->valuesArray[i] = (this->getValue(i) * digit);
//        }

        return *this;

    }

    Point &Point::operator/=(double digit) {

        for (int i = 0; i < dim; i++)
        {
            this->_values[i] = (this->getValue(i) / digit);
        }

//        for (int i = 0; i < dim; i++) {
//            this->valuesArray[i] = (this->getValue(i) / digit);
//        }

        return *this;
    }


    const Point Point::operator*(double digit) const {
        Point *productPoint;
        productPoint = new Point;

        for (int i = 0; i < dim; i++) {
            productPoint->setValue(dim, this->getValue(i) * digit);
        }


        return *productPoint;
    }

    const Point Point::operator/(double digit) {
        Point *productPoint;
        productPoint = new Point;

        for (int i = 0; i < dim; i++) {
            productPoint->setValue(dim, this->getValue(i) / digit);
        }

        return *productPoint;
    }


    Point &operator+=(Point &point1, const Point &point2) {

        int dim1 = point1.getDim();
        int dim2 = point2.getDim();

        try {
            if (dim1 != dim2) {
                throw DimensionalityMismatchEx("Point Compound Assignment += Error", dim1, dim2);
            }
        }catch(DimensionalityMismatchEx & cException)
        {
            std::cout<<cException;
        }

        for ( int i = 0;i < point1.getDim(); i++)
        {
            point1._values[i] = ((point1.getValue(i)) + (point2.getValue(i)));
        }
//        for (int i = 0; i < point1.getDim(); i++) {
//            point1.valuesArray[i] = ((point1.getValue(i)) + (point2.getValue(i)));
//        }

        return point1;
    }

    Point &operator-=(Point &point1, const Point &point2) {

        int dim1 = point1.getDim();
        int dim2 = point2.getDim();

        try {
            if (dim1 != dim2) {
                throw DimensionalityMismatchEx("Point Compount Assignment -= Error", dim1, dim2);
            }
        }catch(DimensionalityMismatchEx & cException)
        {
            std::cout<<cException;
        }

        for( int i = 0; i < point1.getDim(); i++)
        {
            point1._values[i] = (point1.getValue(i) - point2.getValue(i));
        }

//        for (int i = 0; i < point1.getDim(); i++) {
//            point1.valuesArray[i] = (point1.getValue(i) - point2.getValue(i));
//        }

        return point1;
    }


    const Point operator-(const Point &point1, const Point &point2) {
        Point *differencePoint;
        differencePoint = new Point;

        for (int i = 0; i < point1.getDim(); i++) {
            differencePoint->setValue((point1.getDim()), (point1.getValue(i) - point2.getValue(i)));
        }

        return *differencePoint;
    }

    const Point operator+(const Point &point1, const Point &point2) {
        Point *sumPoint;
        sumPoint = new Point;

        sumPoint->resize(point1.getDim());

        for (int i = 0; i < point1.getDim(); i++) {
            sumPoint->setValue((point1.getDim()), ((point1.getValue(i)) + (point2.getValue(i))));
        }


        return *sumPoint;
    }

    bool operator==(const Point &point1, const Point &point2) {

        for (int i = 0; i<point1.getDim(); i++)
        {
            if(point1.getValue(i) != point2.getValue(i) && point1._id != point2._id)
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
            if (point1.getValue(i) != point2.getValue(i) && point1._id != point2._id)
            {
                return true;
            }
        }
        return false;
    }

    bool operator<(const Point &point1, const Point &point2) {

        int dim1 = point1.getDim();
        int dim2 = point2.getDim();

        try {
            if (dim1 != dim2) {
                throw DimensionalityMismatchEx("Point Comparison Operator < Error", dim1, dim2);
            }
        }catch(DimensionalityMismatchEx & cException)
        {
            std::cout<<cException;
        }

        for (int i = 0; i < point1.getDim(); i++)
        {
            if (point1.getValue(i) >= point2.getValue(i)) {
                return false;
            }
        }

        return true;
    }

    bool operator>(const Point &point1, const Point &point2)
    {

        int dim1 = point1.getDim();
        int dim2 = point2.getDim();

        try {
            if (dim1 != dim2) {
                throw DimensionalityMismatchEx("Point Comparison Operator < Error", dim1, dim2);
            }
        }catch(DimensionalityMismatchEx & cException)
        {
            std::cout<<cException;
        }

        for (int i = 0; i < point1.getDim(); i++) {

            if (point1.getValue(i) <= point2.getValue(i))
            {
                return false;
            }

        }
        return true;
    }

    bool operator<=(const Point &point1, const Point &point2) {


        for (int i = 0; i < point1.getDim(); i++) {
            if (point1.getValue(i) > point2.getValue(i)) {
                return false;
            }
        }

        return true;
    }

    bool operator>=(const Point &point1, const Point &point2) {

        for (int i = 0; i <= point1.getDim(); i++) {
            if (point1.getValue(i) < point2.getValue(i)) {
                return false;
            }
        }

        return true;
    }

    std::ostream &operator<<(ostream &os, const Point &point) {


        for (int i = 0; i < point.getDim(); i++) {

            int tempVar = point.getValue(i);


            if (point.getValue(i) == tempVar)
            {

                os << tempVar << ".0" << ",";
            }

            else
            {

                os << point.getValue(i) << ",";
            }

        }
        return os;
    }



    std::istream &operator>>(istream &is, Point &point) {

        string value;
        double d;
        int i = 0;

        //Point p;

        while (getline(is, value, ',')) {
            d = stod(value);

            point.setValue(i++, d);
        }

        int dim1 = i;
        int dim2 = point.getDim();

        try {
            if (dim1 != dim2) {
                throw DimensionalityMismatchEx("Point Extraction Operator >> Error", dim1, dim2);
            }
        }catch(DimensionalityMismatchEx & cException)
        {
            std::cout<<cException;
        }
        /* for ( int i = 0; i < point.getDim(); i++)
         {
             cout << point.getValue(i) << "  ";
         }*/


        //cout << endl;

        return is;

    }



    Point &Point::operator=(const Point &point) {

        int dim1 = this->getDim();
        int dim2 = point.getDim();

        try {
            if (dim1 != dim2) {
                throw DimensionalityMismatchEx("Point Assignment Operator Error", dim1, dim2);
            }
        }catch(DimensionalityMismatchEx & cException)
        {
            std::cout<<cException;
        }
        for( int i = 1; i<point.getDim(); i++)
        {
            this->_values[i] = point.getValue(i);
        }
        this->dim = point.getDim();


        return *this;
    }

    double &Point::operator[](int index)
    {
        try {
            if (index > dim) {
                throw OutOfBoundsEx("Point index 0 Error", index);
            }
        }catch(OutOfBoundsEx &cException)
        {
            std::cout<<cException;
        }
        return _values[index];
    }

    unsigned int Point::_idgenerator()
    {
        static unsigned int id = 0;

        id++;

        return id;

    }

    void Point::rewindIdGen()
    {
        _id = _id--;
    }
};





