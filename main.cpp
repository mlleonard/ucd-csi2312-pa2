#include "Point.h"
//#include "Cluster.h"
#include <iostream>
//#include <stdlib.h>

using namespace Clustering;
using namespace std;


int main() {
    int *dimPointer;
    dimPointer = new userDim;
    double userValues[userDim];
    int arraySize = 0;
    int Points[arraySize];
    int count=0;
    int pdim=0;
    double pvalue;
    int qdim;
    double qvalue;

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


    return 0;}


