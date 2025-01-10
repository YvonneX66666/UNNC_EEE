// Name: Kexin Yu   Student id: 20320941
// intervalArithmeticProject(Coursework4)

#include <iostream>
#include "IntervalClass.h"

using namespace std;

// The main function tests different things of the class "interval"
// The test results are at the bottom of the code.
// The interface of the class is in the "IntervalClass" header file
// Its implementations are in the "IntervalClass" cpp file

int main(){

    cout <<"***************************** Initial Overall Task ***************************\n" << endl;
     interval X; // Default initialisation
    // Check if the default constructor of the interval class is correct
    cout <<"The min value of X is:"<< X.get_min() << endl;
    cout <<"The max value of X is:"<< X.get_max() << "\n" <<endl;

    interval Y(3.0,3.1); // Initialisation from complete data
    // Check if the constructor for initializing the interval with min and max values is correct
    cout <<"The min value of Y is:"<< Y.get_min() << endl;
    cout <<"The max value of Y is:"<< Y.get_max() << "\n" <<endl;

    interval Z(7); // Initialisation from a single float
    // Check if the constructor for initializing the interval with a single value is correct
    cout <<"The min value of Z is:"<< Z.get_min() << endl;
    cout <<"The max value of Z is:"<< Z.get_max() << "\n" <<endl;

    interval A(X);
    cout <<"The min value of A is:"<< A.get_min() << endl;
    cout <<"The max value of A is:"<< A.get_max() << "\n" <<endl;

    A = X;
    // Check = operator
    cout <<"The min value of A is:"<< A.get_min() << endl;
    cout <<"The max value of A is:"<< A.get_max() << "\n" <<endl;

    interval *intptr = new interval[4]; // Allocate memory
    delete[] intptr; // Free up the dynamically allocated memory


    cout <<"\n******************************* Upgrade Task *******************************\n" << endl;
    interval x(3.0,3.1); // Initialisation from complete data
    cout <<"The min value of x is:"<< x.get_min() << endl;
    cout <<"The max value of x is:"<< x.get_max() << "\n" <<endl;

    interval y(7); // Initialisation from a single float
    cout <<"The min value of y is:"<< y.get_min() << endl;
    cout <<"The max value of y is:"<< y.get_max() << "\n" <<endl;

    interval a=x+y;
    // Check + operator for adding two intervals
    cout <<"The min value of a (x+y) is:"<< a.get_min() << endl;
    cout <<"The max value of a (x+y) is:"<< a.get_max() << "\n" <<endl;

    interval b=x-y;
    // Check - operator for subtracting two intervals
    cout <<"The min value of b (x-y) is:"<< b.get_min() << endl;
    cout <<"The max value of b (x-y) is:"<< b.get_max() << "\n" <<endl;

    interval c=x*y;
    // Check * operator for multiplying two intervals
    cout <<"The min value of c (x*y) is:"<< c.get_min() << endl;
    cout <<"The max value of c (x*y) is:"<< c.get_max() << "\n" <<endl;

    interval d=x/y;
    // Check / operator for dividing two intervals
    cout <<"The min value of d (x/y) is:"<< d.get_min() << endl;
    cout <<"The max value of d (x/y) is:"<< d.get_max() << "\n" <<endl;

    interval p(x);
    cout << "The min value of p(x) is: " <<  p.get_min() << endl;
    cout << "The max value of p(x) is: " <<  p.get_max() << "\n" <<endl;

    p += a;
    // Check += operator for adding an interval to another interval
    cout << "The min value of p(x) after add a is: " <<  p.get_min() << endl;
    cout << "The max value of p(x) after add a is: " <<  p.get_max() << "\n" <<endl;

    // Check << operator for outputting an interval to the output stream
    cout << "Here is the test for output an interval to the output stream:"<<endl;
    cout<<d;

    // Check >> operator for inputting an interval from the input stream
    cout << "\nHere is the test for input an interval to the input stream:"<<endl;
    cout << "Please enter new min and max value of a:"<< endl;
    cin >> a;


    float f(5.);

    interval g = a + f;
    // Check + operator for adding an interval and a float
    cout <<"The min value of g (a + f) is:"<< g.get_min() << endl;
    cout <<"The max value of g (a + f) is:"<< g.get_max() << "\n" <<endl;

    interval h = f + a;
    // Check + operator for adding a float and an interval
    cout <<"The min value of h (f + a) is:"<< h.get_min() << endl;
    cout <<"The max value of h (f + a) is:"<< h.get_max() << "\n" <<endl;

    return 0;
}



/* Test Result is shown here:

***************************** Initial Overall Task ***************************

The min value of X is:0
The max value of X is:1

The min value of Y is:3
The max value of Y is:3.1

The min value of Z is:7
The max value of Z is:7

The min value of A is:0
The max value of A is:1

The min value of A is:0
The max value of A is:1


******************************* Upgrade Task *******************************

The min value of x is:3
The max value of x is:3.1

The min value of y is:7
The max value of y is:7

The min value of a (x+y) is:10
The max value of a (x+y) is:10.1

The min value of b (x-y) is:-4
The max value of b (x-y) is:10.1

The min value of c (x*y) is:21
The max value of c (x*y) is:21.7

The min value of d (x/y) is:0.428571
The max value of d (x/y) is:0.442857

The min value of p(x) is: 3
The max value of p(x) is: 3.1

The min value of p(x) after add a is: 13
The max value of p(x) after add a is: 13.2

Here is the test for output an interval to the output stream:
Min: 0.428571   Max: 0.442857

Here is the test for input an interval to the input stream:
Please enter new min and max value of a:
3
3
Error! The minimum value is greater or equal to the maximum value. PLease try again
3
2
Error! The minimum value is greater or equal to the maximum value. PLease try again
4
5
The min value of g (a + f) is:9
The max value of g (a + f) is:10

The min value of h (f + a) is:9
The max value of h (f + a) is:10
*/
