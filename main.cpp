//#include "Point.h"
//#include "Cluster.h"
#include <iostream>
//#include <stdlib.h>

//using namespace Clustering;
using namespace std;

int main() {
    int userDim=0;
    double userValues[userDim];

    cout << "Please enter the number of dimensions" << endl;
    cin >> userDim;

    cout << "Now please enter the values of your dimension" << endl;
    for (int i = 0; i < userDim; i++)
    {
        cin >> userValues[i];

    }
    for (int i = 0; i < userDim; i++) {
        cout << userValues[i] << endl;
    }
    return 0;
}