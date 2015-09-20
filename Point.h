//
// Created by Madeline Leonard on 9/18/15.
//

#ifndef UCD_CSI2312_PA2_POINT_H
#define UCD_CSI2312_PA2_POINT_H

#include <iostream>


namespace Clustering {

    class dArray;

    class Point{

        int dim;    //number of dimensons of point
        double values[];
         //values associated with dimensions


    public:

        Point(int);             //Constructor created with just dimensions
        Point(int, dArray);   //Constructor created with dimensions and values

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

        friend bool operator>(const Point &a, const Point &b)
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

        friend bool operator<(const Point &a, const Point &b)
        {

            if(a.getDim() == b.getDim())
            {
                bool myBool = false;
                for(int i = 0; i < a.getDim(); i++)
                {
                    if(a.getValue(i) < b.getValue(i))
                    {
                        myBool = true ;
                    }
                }
                return myBool;
            }
            else if(a.getDim() > b.getDim())
            {
                bool aBigger = false;
                for(int i = 0; i < b.getDim(); i++)
                {
                    if(a.getValue(i) < b.getValue(i))
                    {
                        aBigger = true;
                    }
                }
                return aBigger;
            }
            else
            {
                bool aBigger = false;
                for(int i = 0; i < a.getDim(); i++)
                {
                    if(a.getValue(i) < b.getValue(i))
                    {
                        aBigger = true;
                    }
                }
                return aBigger;
            }



















            /*
            bool checking=true;
            int biggerDim = 0;
            int smallerDim = 0;
            int count = 0;
            int aDim = a.getDim();
            int bDim = b.getDim();


            if (bDim > aDim)
            {

                biggerDim = bDim;
                smallerDim = aDim;
                while (checking && count < biggerDim) {


                    if((a.getValue(count) == b.getValue(count)) && (count < smallerDim))
                    {
                        checking == true;
                        count++;
                    }
                    if (a.getValue(count) == b.getValue(count) && count == smallerDim)
                    {
                        checking == false;
                    }
                    else if (a.getValue(count) > b.getValue(count))
                    {
                        return false;
                    }

                    else
                    {
                        checking == false;
                    }

                }
                return true;
            }

            else
            {
                biggerDim = aDim;
                smallerDim = bDim;

                while (checking && count < biggerDim)
                {
                    std::cout << "also made it here";
                    if((a.getValue(count) == b.getValue(count)) && (count < smallerDim)) {
                        std::cout<< "I even made it here";
                        checking == true;
                        count++;
                    }


                    if (a.getValue(count) == b.getValue(count) && count == smallerDim)
                    {
                        checking == false;
                    }
                    else if (a.getValue(count) < b.getValue(count))
                    {
                        return true;
                    }
                    else
                    {
                        checking == false;
                    }
                }

                return false;
            }
        */}









    };
}



#endif //UCD_CSI2312_PA2_POINT_H
