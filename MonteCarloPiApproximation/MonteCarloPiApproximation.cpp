// MonteCarloPiApproximation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <chrono>
#include <time.h>

/* 
|-----2xR-----|

|----x-x-x----|
|  x       x  |
| x         x | Area(Circle)=PIxR^2
|x           x| Area(Square)=4xR^2
|x     0-----x|
|x        R  x| Choose a Radius of 16 for simplicity
| x         x |
|  x       x  | 
|----x-x-x----| Ratio of Areas is: PI/4, multiply by 4 to arrive at ~PI

We can approximate the value of PI using the monte carlo method.  
The circle above has radius R=1, and the square has a side of length 2xR

Our approach will be to generate random (x,y) coordinates and determine if
they are inside or ourside of the circle.  If not in the circle then it is 
inside the square.

Based on Equation for a circle z^2=x^2+y^2 => z=sqrt(x^2+y^2)
z <= sqrt(16) then (x,y) in the circle
z > sqrt(16) then  (x,y) outside the circle

*/
using namespace std;

typedef struct _Point_t_ {
    double x;
    double y;
} Point_t;

const long iter = 100000000L;

int main()
{
    long insideCounter = 0;
    default_random_engine dre(time(NULL));
    uniform_real_distribution<double> uni_double_di(0,1); //16 is included in generated numbers

    for (long i = 0; i < iter; i++) {
        double x = uni_double_di(dre);
        double y = uni_double_di(dre);
        
        double z = x * x + y * y;
        string in = "out";
        if (z <= 1) {
            insideCounter++;
            in = "in";
        }
        if (i % 100000 == 0) cout << i << endl;
        //cout << "(" << x << ", " << y << ")" << " - " << in << endl;
    }

    cout << "--------------" << endl << endl;
    cout << insideCounter << " of " << iter << " points inside circle:" << endl;

    cout << endl << insideCounter << " * 4" << endl << "------------ = " << (double)((double)insideCounter / (double)iter)*4.0 << endl << iter << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
