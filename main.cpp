#include "Point.h"
#include "darray.h"
#include "Cluster.h"
#include <iostream>
//#include <stdlib.h>

using namespace Clustering;
using namespace std;


int main() {

    int arraySize = 0;
    int userDim = 0;
    int Points[arraySize];
    int numberOfPoints;
    int count=0;
    int pdim=0;
    double pvalue;
    int qdim;
    double qvalue;

    Cluster myClust;

    cout << "Please input the number of points you will be entering" << endl;
    cin >> numberOfPoints;

    for(int i = 0; i < numberOfPoints; i++)
    {
        cout << "Please input the number of Dimensions of your point" << endl;
        cin >> userDim;

        dArray myArr(userDim);

        cout << "Please input the Values of those dimensions" << endl;

        for (int i = 0; i < userDim; i++) {
            double temp;
            cin >> temp;
            myArr.insert(temp);
        }

        Point myPoint(userDim, myArr);
        myClust.add(&myPoint);

    }






























    //cout << "Please enter how many points you would like to input" << endl;

    //cin >> arraySize;

/*    while (count < arraySize)
    {


        cout << "Please enter the number of dimensions" << endl;
        cin >> userDim;

        cout << "Now please enter the values of your dimension" << endl;
        for (int i = 0; i < userDim; i++) {
            cin >> userValues[i];
        }

        new Point(userDim, userValues);
    }*/

    /*cout << "Please enter the number of dimensions" << endl;
    cin >> userDim;

    cout << "Now please enter the values of your dimension" << endl;
    for (int i = 0; i < userDim; i++) {
        cin >> userValues[i];
    }

    Point p(userDim, userValues);
*/



/*    cout << "p.getdim is " << p.getDim() << endl;
    Point q(p);

    //pdim =  p.getDim();
    //qdim = q.getDim();
    cout << "p.getdim is " << p.getDim() << endl;
    for(int i = 0; i< p.getDim(); i++)
    {
        //cout << "made it inside the for loop" << endl;

       cout <<"p" << i << " is " << p.getValue(i) << endl;

    }
    cout << "q.getdim is " << q.getDim() << endl;
    for(int i = 0; i< q.getDim(); i++)
    {
        //cout << "made it inside the for loop" << endl;

        cout <<"q" << i << " is " << q.getValue(i) << endl;

    }

*/
    //*********************TEST FOR OVERLOADED OPERATORS******************************

/*
    cout << "Please enter the first dimension"<< endl;
    cin >> userDim;

    cout <<"Please enter the values" << endl;
    for(int i = 0; i < userDim; i++)
    {
        cin >> userValues[i];
    }


    Point a(userDim, userValues);

    cout << "Please enter the second dimension" << endl;
    cin >> userDim;

    cout << "Please enter the values" << endl;
    for(int i= 0; i < userDim; i++)
    {
        cin >> userValues[i];
    }

    Point b(userDim, userValues);

    cout << a.getDim();
    cout << a.getValue(0);
    cout << "made it here" << endl;


    if (a<b)
    {
        cout << "a is less than b" << endl;
    }
    else{
        cout << "a is greater than b" << endl;
    }

*/
    return 0;}


