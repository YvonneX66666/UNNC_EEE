//  Coursework1 task B
// Student Name: Kexin Yu      Student id: 20320941

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//-------------------------------------------------------------
// Function to evaluate pi to a given accuracy
//-------------------------------------------------------------

// Copyright Kexin Yu

// Input argument: The required accuracy defined so that the returned
//                 value is ESTIMATED to be pi +/- accuracy required

// Return value  : The estimate of pi

// Methodology: Monte Carlo approach

// Required header files: None

// Warning: There is no check on whether the function can acheive a
//          very demanding accuracy, e.g. 10^(-99)
// The maximum accuracy that can be displayed is 10^(-10).

  double get_pi(double accuracy);

//The contents of this function is below the main funtion



//-------------------------------------------------------------
// Main program to demonstrate the use of the get_pi function
//-------------------------------------------------------------

// This testing code is referred to theSuggestedSolutionOfTaskA (Copyright Phil Sewell)
// Required header files: stdio.h (for printf), time.h ( for clock() etc)

int main() {

    // This code shows use of the get_pi function and assesses its
    // ability to correctly function with a range of accuracy demands

    float EstimateOfPi = 0; //The pi value need to be calculated
    double AccuraryRequired = 1;
    double ComputationTime = 0; //Time to calculate the pi value from accuracy

    for(AccuraryRequired=1;AccuraryRequired>1e-10;AccuraryRequired/=10.){

          clock_t begin = clock(); // Time before calculation of pi value

          EstimateOfPi = get_pi(AccuraryRequired); // Obtain pi value

          clock_t end = clock(); // Time after calculation of pi value

          ComputationTime = (double)(end - begin)/CLOCKS_PER_SEC; // Time taken to obtain pi value

          printf("\nThe estimate of pi= %4.12f when the accuracy demand=%4.10f: Computation time=%3.4f seconds\n",EstimateOfPi,AccuraryRequired,ComputationTime);

    } //end for

    return (0);
 } //end main

//-------------------------------------------------------------
//-------------------------------------------------------------



// The contents of the get_pi(double accuracy) function
double get_pi(double accuracy) {

    double N = 0; //The number darts in circle
    double D = 0; //The number darts thrown
    double x,y;  //Random horizontal and vertical coordinates of the dart shot to the Frisbee
    float error = 0; //Error measure

    do {
        error = (float)4/(N+1);
        //Due to the pi can be calculated as: 4D/N.
        //The calculation of error can be presented as: 4(D+1)/(N+1)-4D/(N+1) = 4/(N+1)

        //Generate random numbers between -1 and 1 in horizontal and vertical coordinates
        x = -1+2*((float)rand())/RAND_MAX;
        y = -1+2*((float)rand())/RAND_MAX;

        N++;

        if ((x*x+y*y) <= 1.0) //When the random number coordinates are inside the circle
             D++;

    }while(error > accuracy); //¡°do¡± ends when the error is less than or equal to the required                               accuracy.
  //  printf("nnnnnnn:%lf",N);
    return (4*(float)D/N); //Return the calculated pi value
}

//-------------------------------------------------------------
//-------------------------------------------------------------
