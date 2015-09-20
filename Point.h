//
// Created by Madeline Leonard on 9/18/15.
//

#ifndef UCD_CSI2312_PA2_POINT_H
#define UCD_CSI2312_PA2_POINT_H

#include <iostream>

namespace Clustering {


    class Point{

        int dim;        //number of dimensons of point
        double values[];  //values associated with dimensions


    public:

        Point(int);             //Constructor created with just dimensions
        Point(int, double []);   //Constructor created with dimensions and values

        Point(const Point&);    //Copy Constructor
        Point &operator=(const Point&);     //Overloaded = operator
        ~Point();               //Destructor for Point

        //Accessors and Mutators

        int getDim() const;
        void setValue(int, double);
        double getValue(int) const;

        double distanceTo(const Point&);

        Point &operator*=(const Point&);
        Point &operator/=(const Point&);
        const Point operator*(double) const;
        const Point operator/(double) const;

        double &operator[](int index) {return values[index-1];}

        //Friends

        friend bool operator>(const Point&, const Point&);








    };
}



#endif //UCD_CSI2312_PA2_POINT_H
