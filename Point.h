//
// Created by Madeline Leonard on 9/20/15.
//

#ifndef POINT_H
#define POINT_H
#include <iostream>

namespace Clustering {

    class Point {
        typedef int size_type;
        typedef double value_type;
        int dim;
        size_type DEFAULT_DIM;
        value_type *valuesArray;

    public:
        //default constructor
        Point();

        //constructor
        Point(size_type);

        Point(size_type, value_type);

        //copy constructor;
        Point(const Point &);

        //Overloaded operator=
        Point &operator=(const Point&);

        //destructor
        ~Point();

        //member functions for dArray
        //size_type getDEFAULT_DIM() const { return DEFAULT_DIM; }

        size_type getDim() const { return dim; }

        value_type getValue(size_type i) const { return valuesArray[i]; }

        void insert(const value_type entry);

        void resize(int);

        //bool isEmpty() const { return dim == 0; }

        //bool isFull() const { return dim == DEFAULT_DIM; }

        //member functions for Point class

        double distanceTo(Point &);

        Point &operator*=(double);

        Point &operator/=(double);

        const Point operator*(double) const;

        const Point operator/(double);

        double &operator[](int index) { return valuesArray[index - 1]; }

        //friends!

        friend Point &operator+=(Point &, const Point &);

        friend Point &operator-=(Point &, const Point &);

        friend const Point operator+(const Point &, const Point &);

        friend const Point operator-(const Point &, const Point &);

        //comparison overloaded operators
        friend bool operator==(const Point &, const Point &);

        friend bool operator!=(const Point &, const Point &);

        friend bool operator<(const Point &, const Point &);

        friend bool operator>(const Point &, const Point &);

        friend bool operator<=(const Point &, const Point &);

        friend bool operator>=(const Point &, const Point &);

        friend std::ostream &operator<<(std::ostream &, const Point &);

        friend std::istream &operator>>(std::istream &is, Point &point);


    };

};
#endif
