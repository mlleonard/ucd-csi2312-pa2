#include <iostream>
#include "point.h"
#include "cluster.h"

using namespace std;


int main() {

    //**************Testing general with While Loop*******************
/*
    int numOfPoints;    // number of points being input by the user
    int count = 0;          // counter for while loop
    int dim;
    double value;

    cout << "Please enter how many points you would like to create" << endl;

    cin >> numOfPoints;

    while( count < numOfPoints)
    {
        Point point;


        cout << "Please enter the number of dimensions" << endl;
        cin >> dim;

        point.resize(dim);

        cout << point.getDEFAULT_DIM();

        cout << "Now please enter the values for those points" << endl;

        for( int i = 0; i < dim; i++)
        {
            cin >> value;
            point.insert(value);
        }

        for ( int i = 0; i < dim; i++)
        {
            cout << point.getValue(i) << endl;
        }
        count++;


    }*/
    //******************Testing two Points****************

    int userDim = 0;
    double value;


    cout << "Please enter the dimensions of the first point" << endl;
    cin >> userDim;

    Point a;

    a.resize(userDim);

    cout << "Please enter the values of those dimensions" << endl;

    for ( int i = 0; i < userDim; i++)
    {
        cin >> value;
        a.insert(value);
    }

    pointPtr myPointa;
    myPointa = &a;

    Cluster cluster1;

    cluster1.add(myPointa);

    cout << "Please enter the dimensions of the second point" << endl;
    cin >> userDim;

    Point b;

    b.resize(userDim);

    cout << "Please enter the values of those dimensions" << endl;

    for ( int i = 0; i < userDim; i++)
    {
        cin >> value;
        b.insert(value);
    }

    pointPtr myPointb;
    myPointb = &b;

    Cluster cluster2;

    cluster2.add(myPointb);




    cout << (cluster1 != cluster2);





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


