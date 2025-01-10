//  Coursework2 routePlanningProject
// Student Name: Kexin Yu      Student id: 20320941

//-------------------------------------------------------------
// Test data Result:

// When the user enters a location of 1 2 3
// The program outputs a shortest route order of 1 3 2 and a shortest distance of 25.041595

// When the user enters a location of 3 2 1
// The program outputs a shortest route order of 2 3 1 and a shortest distance of 25.041595

// When the user enters a location of 1 2 3 4
// The program outputs a shortest route order of 2 3 1 4 and a shortest distance of 25.044359

// When the user enters a location of 9 1 7 4
// The program outputs a shortest route order of 1 7 9 4 and a shortest distance of 31.203493
//-------------------------------------------------------------



#include <stdio.h>
#include  <math.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

//-------------------------------------------------------------
// Function to calculate the distance between two known points
//-------------------------------------------------------------

// Copyright Kexin Yu

// Input argument: Coordinates of the two points for which distances are to be calculated

// Return value  : The distance between two points

// Required header files: math.h (for sqrt£¨£©)

//The contents of this function is below the main function

float distanceBetweenLocations (float firstLocationsXCoordinate, float firstLocationsYCoordinate, float secondLocationsXCoordinate, float secondLocationsYCoordinate);



//-------------------------------------------------------------
// Function to calculate the total distance of the route
//-------------------------------------------------------------

// Copyright Kexin Yu

// Input argument: Location point coordinates, route order and number of locations contained in the route

// Return value  : The total distance of the route

// Required header files: None

// Function used:'distanceBetweenLocations'(To calculate the distance between two locations)

//The contents of this function is below the main function

float totalDistanceOfRoute(float *xCoordOfPossibleLocations, float *yCoordsOfPossibleLocations, int *orderedLocationsVisitedOnThisRoute, int numberOfLocations );



//---------------------------------------------------------------------------------
// Function to arrange the order of the shortest paths and calculate the distances
//---------------------------------------------------------------------------------

// Copyright Kexin Yu

// Input argument: Position point coordinates, array to hold the input route, array to hold the shortest route, subscript of the array to start permutation£¬number of positions in the route, shortest distance of the route

// Return value: The shortest distance for the input route

// Required header files: stdlib.h (for calloc(),malloc()),string.h (for memcpy())

// Function used: 'totalDistanceOfRoute'(To calculate the total distance for each order route)

// The contents of this function is below the main function

float permutation(float *xCoordOfPossibleLocations, float *yCoordOfPossibleLocations, int *route, int **route2, int begin, int size, float *shortDistance);



//---------------------------------------------------------------------------------
// Main program to demonstrate the use of the permutation function
//---------------------------------------------------------------------------------

// Copyright Kexin Yu

// Return value: The shortest distance for the input route

// Required header files: stdlib.h (for calloc()), stdio.h (for printf())

int main() {

   // This program asks the user to select up to 5 of the 10 locations
   // The shortest distance order of the route and it distance size is displayed

   // Point coordinates of the locations that the user can select (Starting point included£©
   float xCoordOfPossibleLocations[11]={0,9,6,7,1,21,7,11,5,9,8};
   float yCoordOfPossibleLocations[11]={0,8,8,8,1,11,11,11,5,9,1};

    int *positionofLocation = 0; // To store the order of the route entered by the user
    int *shortrouteoflocation = 0; // To store the shortest order of the route

    int numofLocation = 0; // Number of locations selected by the user
    float shortDistance= FLT_MAX; // Initialisation of the shortest distance of the route


    // Show the locations that user can choose
    printf("Ten locations that user can choose are:\n");
    for(int i=1; i<11;i++){
        printf(" x%d:%2.f  y%d:%2.f\n",i,xCoordOfPossibleLocations[i],i,yCoordOfPossibleLocations[i]);
    }

    // Ask user to select the number of locations
    printf("Please select the number of the locations (Up to 5):\n");
    scanf("%d", &numofLocation);
    positionofLocation = (int*)calloc(numofLocation, sizeof(int)); // Dynamic array
    shortrouteoflocation = (int*)calloc(numofLocation, sizeof(int)); // Dynamic array

    // Ask user to select the exact locations they want
    for (int i = 1;i <=numofLocation ; i++) {
        printf("Please enter the location %d:\n",i);
        scanf("%d",&positionofLocation[i]);
    }

    // Use this function to rank the shortest order of the route and calculate the distances
    shortDistance = permutation(xCoordOfPossibleLocations,yCoordOfPossibleLocations,positionofLocation,&shortrouteoflocation, 1, numofLocation,&shortDistance);

    // Print the shortest route order
    printf("The shortest route order is: ");
    for(int i = 1;i <= numofLocation; i++) {
      printf("%d ",shortrouteoflocation[i]);
    }

    // Print the shortest distance
    printf("\nThe shortest distance is: %f\n",shortDistance);

    return 0;
}
//------------------------------------------------------------------
//------------------------------------------------------------------


//Function used to calculate the distance between two points
float distanceBetweenLocations (float firstLocationsXCoordinate,float firstLocationsYCoordinate,float secondLocationsXCoordinate,float secondLocationsYCoordinate){

    float  Distance = 0;
    float  x = secondLocationsXCoordinate - firstLocationsXCoordinate;
    float  y = secondLocationsYCoordinate - firstLocationsYCoordinate;

    return (Distance = sqrt(x*x+y*y));
}
//------------------------------------------------------------------
//------------------------------------------------------------------


//Function used to calculate the total distance of the route
 float totalDistanceOfRoute(
                           float *xCoordOfPossibleLocations,
                           float *yCoordOfPossibleLocations,
                           int *orderedLocationsVisitedOnThisRoute,
                           int numberOfLocations ){

    float totalDistance = 0;

    for( int i=0;i<=numberOfLocations;i++){

       // Integer j be the ith location visited on this particular route
     int j = orderedLocationsVisitedOnThisRoute [i];

       // Integer k be the i+1th location visited on this particular route
     int k = orderedLocationsVisitedOnThisRoute [i+1];

     totalDistance += distanceBetweenLocations(xCoordOfPossibleLocations [j], yCoordOfPossibleLocations [j], xCoordOfPossibleLocations [k],yCoordOfPossibleLocations [k]);

    } //end for

    return (totalDistance);
}
//------------------------------------------------------------------
//------------------------------------------------------------------


// Function to permute and return the shortest distance
float permutation(float *xCoordOfPossibleLocations, float *yCoordOfPossibleLocations, int *route, int **route2, int begin, int size, float *shortDistance)
{
    float totalDistance = 0; // Total distance for each route
    int *shortroute = (int*)malloc(sizeof(int)*(size+2)); // Set the size of positions in the shortest route

    //Initialisation of the start and end points of the route
    route[0] = 0;
    route[size+1] = 0;

    if(begin == size) // A permutation is found
    {
      // Calculate the total distance of this permutation route
       totalDistance = totalDistanceOfRoute(xCoordOfPossibleLocations,yCoordOfPossibleLocations,route,size);

      // Find the shortest distance in each of the permute routes
      // Find the order of route corresponding to that shortest distance
      if (*shortDistance > totalDistance) {

          *shortDistance = totalDistance;

           memcpy(shortroute,route,sizeof(int)*(size+2)); // Copy the current 'route' to 'shortroute'

          *route2 = shortroute; // 'shortroute' storage to 'route2'

       } // end internal if
    } // end external if

     else {
          // Full permutation of elements from subscript from 'begin' to 'size'
             for(int i = begin; i <= size; i ++)
             {
          // Make element-by-element the first
                     int temp = route[begin];
                     route[begin] = route[i];
                     route[i] = temp;

         // Find the full permutation of the remaining elements
        permutation(xCoordOfPossibleLocations,yCoordOfPossibleLocations,route,route2,begin+1,size,shortDistance);

         // Swap the elements back, always keeping the original order
                     temp = route[begin];
                     route[begin] = route[i];
                     route[i] = temp;

        } // end for
     } // end else

    return(*shortDistance);
}
//------------------------------------------------------------------
//------------------------------------------------------------------
