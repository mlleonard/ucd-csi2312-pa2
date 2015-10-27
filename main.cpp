#include <iostream>
#include "Point.h"
#include "KMeans.h"
#include "Cluster.h"
#include <sstream>
#include <fstream>
#include <vector>


using namespace std;
using namespace Clustering;


int main() {

    KMeans myK;
    int k;
    Cluster point_space;
    ifstream inFile("points.txt");
    inFile >> point_space;

    cout << "Please select a k" << endl;
    cin >> k;

    myK.setK(k);

    pointPtr pointArray[k+1];

    point_space.pickPoints(k, pointArray);

    //Cluster clusterArray[k];
    std::vector<Cluster> clusterArray;
    clusterArray.resize(k);
    clusterArray[0] = point_space;




    for ( int i = 1; i < k; i++)
    {

        Cluster *myCluster;
        myCluster = new Cluster;
        clusterArray[i] = *myCluster;

    }

    for (int i = 0; i < k; i++)
    {
        clusterArray[i].setCentroid(*pointArray[i]);
    }

    myK.computeAbsoluteDifference(clusterArray, myK);










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

/*
    Cluster *deleteCluster;
    deleteCluster = new Cluster;

    delete deleteCluster;

*/
/*
    Cluster myCluster1;
    Cluster myCluster2;

    stringstream myStream("1.2,3.4,5.5,90");

    myStream >> myCluster2;

    Point myPoint;
    myPoint.setValue(0,12.3);

    myCluster2.add(&myPoint);




    ifstream inFile("points.txt");

    inFile >> myCluster1;

    myCluster1.intraClusterDistance();



*/

    //cout << myCluster1;

    //cout << myCluster2;

    //Cluster::Move myMove(&myPoint, &myCluster2, &myCluster1);

    //myMove.Perform();

    //cout << myCluster1;
    //cout << myCluster2;






    /*cout << myCluster;

    myCluster.computeCentroid();

    cout << (myCluster.getCentroid());*/
































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
    return 0;
}


