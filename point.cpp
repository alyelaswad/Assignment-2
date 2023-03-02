#include <iostream>
#include <math.h>
using namespace std;
point::point() // non-argument constructor sets x and y to zero.
{
    x = y = 0.0;
}
point::point(float X, float Y) // argument constructor sets passed values to x and y.
{
    x = X;
    y = Y;
}
void point::setX(float X) // setter for x.
{
    x = X;
}
void point::setY(float Y) // setter for y.
{
    y = Y;
}
float point::getX() { return x; } // getter for x.

float point::getY() { return y; }                                // getter for x.
void point::display() { cout << "(" << x << " , " << y << ")"; } // displays the coordinates.
float point::distance(point p)                                   // calculates distance between passed point and the object's point.
{
    return (sqrt((pow(x - p.getX(), 2)) + (pow(y - p.getY(), 2))));
}
point Center(point *C, int n) // calculates the center of x and y.
{
    float total_x = 0.0, total_y = 0.0;
    for (int i = 0; i < n; i++)
    {
        total_x += (C + i)->getX();
        total_y += (C + i)->getY();
    }
    point center(total_x / n, total_y / n);
    return center;
}
point *closest(point *A, int nA, point *B, int nB, point p) // checks which cluster is a point closer to.
{
    float x, y;
    float distA_p = Center(A, nA).distance(p);
    float distB_p = Center(B, nB).distance(p);
    if (distA_p < distB_p) // output statements.
    {
        cout << " is closer to cluster A.\n";
        return A;
    }
    else if (distB_p == distA_p)
    {
        cout << " is equidistant to the two clusters.\n";
        return A;
    }
    cout << " is closer to cluster B.\n";
    return B;
}