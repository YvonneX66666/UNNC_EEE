#include "IntervalClass.h"
#include <iostream>

// This file contains the details of the interval arithmetic class design in the "IntervalClass.h" file
// Head file: <algorithm> is used for std::min, std::max,
// which is used to find the minimum number passed to it

  // Default constructor for interval class
  interval::interval(){
    min = 0;
    max = 1;
  }

  // Constructor for initializing the interval with min and max values
  interval::interval(float MIN, float MAX): min(MIN), max(MAX){}

  // Constructor for initializing the interval with a single value
  interval::interval(float val): min(val), max(val){}

  // Deconstructor of the class
  interval::~interval(){}

  // Overloading the = operator to make two intervals equal
  interval& interval::operator=(const interval& num) {

     min = num.min;
     max = num.max;

    return *this; // Enables concatenation
}

  // Overloading the + operator for adding two intervals
  interval operator+(const interval& num1, const interval& num2) {

      // Create a new interval object with lower and upper bounds for the sum of two interval objects
      interval add1;

      // Add the minimum and maximum values of the two intervals
      add1.min = num1.min + num2.min;
      add1.max = num1.max + num2.max;

    return add1;
}

  // Overloading the + operator for adding an interval and a float
    interval operator+(const interval& num1, const float num2) {

      // Create a new interval object with lower and upper bounds for adding an interval and a float
      interval add2;

      // Add the minimum and maximum values of the interval to the float
      add2.min = num1.min + num2;
      add2.max = num1.max + num2;

      return add2;
}


 // Overloading the + operator for adding a float and an interval
  interval operator+(const float num1, const interval& num2){

      // Create a new interval object with lower and upper bounds for adding a float and an interval
      interval add3;

      // Add the float to the minimum and maximum values of the interval
      add3.min = num1 + num2.min;
      add3.max = num1 + num2.max;

     return add3;
}

  // Overloading the - operator for subtracting two intervals
  interval operator-(const interval& num1, const interval& num2) {

      // Create a new interval object with lower and upper bounds for subtracting two intervals
      interval subtract;

      // Subtract the maximum value of the second interval from the minimum value of the first interval
      // Add the minimum value of the second interval to the maximum value of the first interval
      subtract.min = num1.min - num2.max;
      subtract.max = num1.max + num2.min;

    return subtract;
}

  // Overloading the * operator for multiplying two intervals
  interval operator*(const interval& num1, const interval& num2) {

      // Create a new interval object with lower and upper bounds for multiplying two intervals
      interval multiply;

      // Find the minimum and maximum values of the product of the two intervals by evaluating all possible combinations
      multiply.min = std::min({num1.min * num2.min, num1.min * num2.max, num1.max * num2.min, num1.max * num2.max});
      multiply.max = std::max({num1.min * num2.min, num1.min * num2.max, num1.max * num2.min, num1.max * num2.max});

    return multiply;
}


  // Overloading the / operator for dividing two intervals
  interval operator/(const interval& num1, const interval& num2) {

    if (num2.min <= 0 && num2.max >= 0) {
      // Throw an error if the interval includes zero, as division by zero is not allowed
      throw std::runtime_error("Division by zero");
    }
      // Create a new interval object with lower and upper bounds for dividing two intervals
      interval division;

      // Find the minimum and maximum values of the division of the two intervals by evaluating all possible combinations
      division.min = std::min({num1.min / num2.min, num1.min / num2.max, num1.max / num2.min, num1.max / num2.max});
      division.max = std::max({num1.min / num2.min, num1.min / num2.max, num1.max / num2.min, num1.max / num2.max});

    return division;
}


  // Overloading the += operator for adding an interval to another interval
  void operator+=(interval& num1, const interval& num2){
      // Add the minimum and maximum values of the second interval to the first interval
      num1.min = num1.min + num2.min;
      num1.max = num1.max + num2.max;
}


  // Overloading the >> operator for inputting an interval from the input stream
  istream& operator>>(istream& in, interval& i){

      do{
            in >> i.min >> i.max;// Input the minimum and maximum values of the interval in order

            if(i.min >= i.max){
                cout << "Error! The minimum value is greater or equal to the maximum value. PLease try again" << endl;
            }//end if

        }while(i.min >= i.max);//make sure the input min value is smaller than input max value, otherwise ask input again

    return(in);
}


  // Overloading the << operator for outputting an interval to the output stream
  ostream& operator<<(ostream& out, interval& i){
    // Output the minimum and maximum values of the interval
    out << "Min: "<< i.min << "   Max: " << i.max << endl;
    return(out);
}
