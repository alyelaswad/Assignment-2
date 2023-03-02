#include <iostream>
#include <math.h>
#include "point.h"
#include "point.cpp"
#include <time.h>
using namespace std;
int main()
{
    srand(time(NULL));

    int nA = 200; // initializing number of points to form cluster A.
    float x, y;
    point *A = new point[nA]; // creates a 1d dynamic array of points.
    for (int i = 0; i < nA; i++)
    {
        x = ((float(rand()) / RAND_MAX) * 20) + 70.0; // generates a random float ranging from 70 to 90.
        (A + i)->setX(x);                             // gives that value to the x coordinate
        y = ((float(rand()) / RAND_MAX) * 20) + 70.0; // generates a random float ranging from 70 to 90.
        (A + i)->setY(y);                             // gives that value to the y coordinate.
    }
    point centera = Center(A, nA); // calculates the center of cluster A
    int nB = 200;                  // initializing number of points to form cluster B.
    point *B = new point[nB];      // creates a 1d dynamic array of points.
    x = 0;
    y = 0;
    for (int i = 0; i < nB; i++) // populates points to form cluster by the method used in cluster A.
    {
        x = ((float(rand()) / RAND_MAX) * 20) + 20.0;
        (B + i)->setX(x);
        y = ((float(rand()) / RAND_MAX) * 20) + 20.0;
        (B + i)->setY(y);
    }
    point centerb = Center(B, nA); // calculates the center of cluster A
    int m = 20;                    // 20 points to check which clusters are they closer to.
    point p[m];
    for (int i = 0; i < m; i++)
    {
        p[i].setX(((float(rand()) / RAND_MAX) * 95) + 5.0); // random floats from 5 to 100.
        p[i].setY(((float(rand()) / RAND_MAX) * 95) + 5.0);
        cout << "Point " << i + 1;
        p[i].display();
        closest(A, nA, B, nB, p[i]);
    }
    A = nullptr; // directs the pointers to point at zero.
    B = nullptr;
    delete[] A; // frees the memory.
    delete[] B;
    return 0;
}