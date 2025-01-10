#ifndef INTERVALCLASS_H_INCLUDED
#define INTERVALCLASS_H_INCLUDED

#endif // INTERVALCLASS_H_INCLUDED

#include <iostream>
#include <algorithm>
using namespace std;

//This document includes the interface design for the interval arithmetic class

// This class represents an interval with a minimum and maximum value and some operator overloading
class interval
{
private:
  // The minimum value of the interval
  float min;

  // The maximum value of the interval
  float max;

public:

  // Constructor for creating an interval with default min and max values of 0
  interval();

  // Constructor for initializing the interval with min and max values
  interval(float min, float max);

  // Constructor for initializing the interval with a single value
  interval(float val);

  // Deconstructor of the class
  ~interval();

  // Accessors for min and max
  float get_min() const { return min; }
  float get_max() const { return max; }


  // Overloading the = operator  to make two intervals equal
  interval& operator=(const interval& num);

  // Overloading the + operator for adding two intervals
  friend interval operator+(const interval& num1, const interval& num2);

  // Overloading the + operator for adding an interval value to a float
  friend interval operator+(const interval& num1, const float num2);

  // Overloading the + operator for adding a float value to an interval
  friend interval operator+(const float num1, const interval& num2);

  // Overloading the - operator for subtracting two intervals
  friend interval operator-(const interval& num1, const interval& num2);

  // Overloading the * operator for multiplying two intervals
  friend interval operator*(const interval& num1, const interval& num2);

  // Overloading the / operator for dividing two intervals
  friend interval operator/(const interval& num1, const interval& num2);

  // Overloading the += operator for adding two intervals
  friend void operator+=(interval& num1, const interval& num2);

  // Overloading the << operator for outputting an interval
  friend ostream& operator<<(ostream& , interval& );

  // Overloading the >> operator for inputting an interval
  friend istream& operator>>(istream& , interval& );
};


