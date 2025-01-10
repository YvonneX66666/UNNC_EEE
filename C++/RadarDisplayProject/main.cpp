//  Coursework3 RadarDisplayProject
//  Student Name: Kexin Yu      Student id: 20320941


#include <iostream>
using namespace std;


//---------------------------------------------------------------------------
// There exists these things called pixel
// Each of those pixel things has three member variables:
// Two float variables for coordinates and one short for brightness
// These three variables of pixel are all public
//---------------------------------------------------------------------------
class pixel;


//---------------------------------------------------------------------------
// There exists these things called icon
// Each of those icon things has two member variables:
// An integer to represent the icon id number and an array to hold the pixels (Up to 16)
// These two variables of icon are all public
//---------------------------------------------------------------------------
class icon;


//---------------------------------------------------------------------------
// There exists these things called displayObject
// Each of those displayObject things has two member variables:
// An pointer array to hold icons (Up to 100)
// An integer to hold the number of active icons in the radar display object
// These two variables of displayObject are all public
//---------------------------------------------------------------------------
class displayObject;


//---------------------------------------------------------------------------
// Print out the pixel details
// Input argument: A pixel instance
// Use reference to pass an instance of a pixel
//---------------------------------------------------------------------------
void showpixelDetail (pixel& aPixel);


//---------------------------------------------------------------------------
// Print out the pixel details of the icons
// Input argument: An icon instance
// Use reference to pass an instance of a icon
//---------------------------------------------------------------------------
void showIconDetail (icon& anIcon);


//---------------------------------------------------------------------------
// To initialise the variables of the icon
// Input argument: An icon instance
// Use reference to pass an instance of a icon
// Four equations are approximately the same in content
// Each equation has different values for the variables of the icon
//---------------------------------------------------------------------------
void initialiseAsDefaultDiagonalLine (icon& anIcon);
void initialiseRedPlaneIcon(icon& anIcon);
void initialiseYellowHeliIcon (icon& anIcon);
void initialisepurpleRocket(icon& anIcon);


//---------------------------------------------------------------------------
// Print out the pixel details of all the icons in a radardisplay
// Input argument: A displayObject instance
// Use reference to pass an instance of a radarDisplay
//---------------------------------------------------------------------------
void radarDisplay(displayObject& aDisplay);


//---------------------------------------------------------------------------
// Definition of the details of pixel
//---------------------------------------------------------------------------
class pixel{

public: //public variables

    float x_coordinate; // Horizontal coordinate variables for pixels
    float y_coordinate; // Vertical coordinate variables for pixels
    short brightness_value; // Brightness variables for pixels (Range 0-20)
   // "short" takes up 2 bytes of storage and "int" takes up 4 bytes
   // Using "short" is more memory efficient
};
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Definition of the details of icon
//---------------------------------------------------------------------------
class icon{

public: //public variables

      int id_number; // The id number for an icon
      pixel thePixels[16]; // An icon can have 16 pixel variable points
};
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Definition of the details of displayObject
//---------------------------------------------------------------------------
class displayObject {

public: //public variables

   int noActiveIcons; // The number of active icons in the radar display object
   icon* iconsToDisplay[100]; // The radarDisplay object can have 100 icons to display
};
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Main function shows how the variable values of the pixels
// of the icons in the radar display are displayed
// The process is divided into 8 subtasks, each of which is tested.
// The results of the tests are shown at the end of the code
//---------------------------------------------------------------------------
int main() {

//-----------------The following code relates to subtask 1 and 2-------------------
//---------------------------------------------------------------------------
    pixel aPixel; // Create a instance using pixel object

    // Set different member variables for this instance
    aPixel.x_coordinate = 3.9;
    aPixel.y_coordinate = 4.1;
    aPixel.brightness_value = 7;

    // Print out the set variables to check
    cout << "The details of the data contained within aPixel:" << endl;
    cout << "X is:" << aPixel.x_coordinate;
    cout << "  Y is:" << aPixel.y_coordinate;
    cout << "  Brightness is:" << aPixel.brightness_value << "\n" <<endl;
//---------------------------------------------------------------------------


//-----------------The following code relates to subtask 3-------------------
//---------------------------------------------------------------------------
    // Print out the value of each variable of  "aPixel"
    cout << "The details of the data contained within aPixel (Print by 'showpixelDetail'):" << endl;
    showpixelDetail (aPixel);
//---------------------------------------------------------------------------


//-----------------The following code relates to subtask 4 and 5-------------------
//---------------------------------------------------------------------------
    pixel pixelOne; // Create a instance using pixel object

    // Set different member variables for this instance
    pixelOne.x_coordinate = 5.1;
    pixelOne.y_coordinate = 7.6;
    pixelOne.brightness_value = 9;

    // Print out the value of each variable of "pixelOne"
    cout << "\nThe details of the data contained within the pixelOne:" << endl;
    showpixelDetail (pixelOne);


    icon myIcon; // Create a instance using icon object

    // Set the first pixel of "myIcon" to have the same data as the "pixelOne" value.
    myIcon.thePixels[0] = pixelOne;

    // Print out the first pixel of "myIcon" to check if it has the same value as "pixelOne"
    cout << "\nThe details of the data contained within the first pixel of myIcon:" << endl;
    cout << "X is:" << myIcon.thePixels[0].x_coordinate;
    cout << "  Y is:" << myIcon.thePixels[0].y_coordinate;
    cout << "  Brightness is:" << myIcon.thePixels[0].brightness_value <<endl;
//---------------------------------------------------------------------------


//--------------The following code relates to subtask 6 and 7----------------
//---------------------------------------------------------------------------
    icon Icon_id_7; // Create a instance icon object

    // Initialise the value of each variable of pixel in this icon object
    initialiseAsDefaultDiagonalLine (Icon_id_7);

    // List the pixel details of this icon object
    cout << "\nThe details of the data contained within the DefaultDiagonalLine:" << endl;
    showIconDetail (Icon_id_7);
//---------------------------------------------------------------------------


//-----------------The following code relates to subtask 8-------------------
//---------------------------------------------------------------------------
    icon allTheIcons[500]; // Create a instance icon array object (Up to 500 icons)

    //Initialise the value of each pixel variable in this icon object
    initialiseRedPlaneIcon(allTheIcons[0]);

    //Initialise the value of each pixel variable in this icon object
    initialiseYellowHeliIcon(allTheIcons[1]);

    //Initialise the value of each pixel variable in this icon object
    initialisepurpleRocket(allTheIcons[2]);

    // Create two instance icon displayObject object
    displayObject displayOne;
    displayObject displayTwo;

    // Icons are assigned to the radar display
    // The number of active icons displayed on the radar has increased

    displayOne.iconsToDisplay[0] = &allTheIcons[0];
    displayOne.noActiveIcons++;
    displayOne.iconsToDisplay[1] = &allTheIcons[1];
    displayOne.noActiveIcons++;

    displayTwo.iconsToDisplay[0] = &allTheIcons[2];
    displayTwo.noActiveIcons++;
    displayTwo.iconsToDisplay[1] = &allTheIcons[0];
    displayTwo.noActiveIcons++;

    // Print out the pixel values of the icons active in the radar display
    cout << "\nThe details of the data contained within the radarDisplay1:" << endl;
    radarDisplay(displayOne);
    cout << "\nThe details of the data contained within the radarDisplay2:" << endl;
    radarDisplay(displayTwo);
//---------------------------------------------------------------------------

    return 0;
}// end main
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// A utility to display the details of a particular instance of a pixel object on the screen
//---------------------------------------------------------------------------
void showpixelDetail (pixel& aPixel){

    cout << "X is:" << aPixel.x_coordinate;
    cout << "  Y is:" << aPixel.y_coordinate;
    cout << "  Brightness is:" << aPixel.brightness_value << endl;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// A utility to display the details of a particular instance of a icon object on the screen
//----------------------------------------------------------------------------
void showIconDetail (icon& anIcon){

    cout << "The id number is:" <<  anIcon.id_number << endl;

    for(int i = 0; i <= 15; i++) {

        cout << "Pixel" << i+1 << ":" << endl;

        // Call the function showPixelDetail to display the pixel details.
        showpixelDetail(anIcon.thePixels[i]);
    } // end for
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// The function used to initialise an icon detail
//---------------------------------------------------------------------------
void initialiseAsDefaultDiagonalLine (icon& anIcon){

    anIcon.id_number = 7; // Set the id number of the icon

    // Assigning values to the 3 variables of the 16 pixels of the icon
    for(int i = 0; i < 16; i++) {
        anIcon.thePixels[i].x_coordinate = i+1;
        anIcon.thePixels[i].y_coordinate = i+1;
        anIcon.thePixels[i].brightness_value = 15;
   }
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// The function used to initialise an specific icon detail
//---------------------------------------------------------------------------
void initialiseRedPlaneIcon(icon& anIcon){

    anIcon.id_number = 1; // Set the id number for this icon

    // Assigning values to the 3 variables of the 16 pixels of RedPlaneIcon
    for(int i = 0; i <= 15; i++) {
        anIcon.thePixels[i].x_coordinate = 16-i;
        anIcon.thePixels[i].y_coordinate = 16-i;
        anIcon.thePixels[i].brightness_value = 5;
   }
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// The function used to initialise an specific icon detail
//---------------------------------------------------------------------------
void initialiseYellowHeliIcon(icon& anIcon){

    anIcon.id_number = 2; // Set the id number for this icon

    // Assigning values to the 3 variables of the 16 pixels of YellowHeliIcon
    for(int i = 0; i <= 15; i++) {
        anIcon.thePixels[i].x_coordinate = 16-i;
        anIcon.thePixels[i].y_coordinate = i+1;
        anIcon.thePixels[i].brightness_value = 10;
   } // end for
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// The function used to initialise an specific icon detail
//---------------------------------------------------------------------------
void initialisepurpleRocket(icon& anIcon){

    anIcon.id_number = 3; // Set the id number for this icon

    // Assigning values to the 3 variables of the 16 pixels of purpleRocket
    for(int i = 0; i <= 15; i++) {
        anIcon.thePixels[i].x_coordinate = i+1;
        anIcon.thePixels[i].y_coordinate = 16-i;
        anIcon.thePixels[i].brightness_value = 8;
   } // end for
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// The function used to display different number of active icons on the radar
//---------------------------------------------------------------------------
void radarDisplay(displayObject& aDisplay) {

    for(int i = 0; i < aDisplay.noActiveIcons; i++){

        cout << "This is the detail of the " << i + 1 << "th icon in this radardisplay:" << endl;
        showIconDetail(*aDisplay.iconsToDisplay[i]);
    } // end for
}
//---------------------------------------------------------------------------


//-------------------- Test Result for different subtasks ----------------------
/*
For subtask 1 and 2:
The details of the data contained within aPixel:
X is:3.9  Y is:4.1  Brightness is:7

For subtask 3:
The details of the data contained within aPixel (Print by 'showpixelDetail'):
X is:3.9  Y is:4.1  Brightness is:7

For subtask 4 and 5:
The details of the data contained within the pixelOne:
X is:5.1  Y is:7.6  Brightness is:9

The details of the data contained within the first pixel of myIcon:
X is:5.1  Y is:7.6  Brightness is:9


For subtask 6 and 7:
The details of the data contained within the DefaultDiagonalLine:
The id number is:7
Pixel1:
X is:1  Y is:1  Brightness is:15
Pixel2:
X is:2  Y is:2  Brightness is:15
Pixel3:
X is:3  Y is:3  Brightness is:15
Pixel4:
X is:4  Y is:4  Brightness is:15
Pixel5:
X is:5  Y is:5  Brightness is:15
Pixel6:
X is:6  Y is:6  Brightness is:15
Pixel7:
X is:7  Y is:7  Brightness is:15
Pixel8:
X is:8  Y is:8  Brightness is:15
Pixel9:
X is:9  Y is:9  Brightness is:15
Pixel10:
X is:10  Y is:10  Brightness is:15
Pixel11:
X is:11  Y is:11  Brightness is:15
Pixel12:
X is:12  Y is:12  Brightness is:15
Pixel13:
X is:13  Y is:13  Brightness is:15
Pixel14:
X is:14  Y is:14  Brightness is:15
Pixel15:
X is:15  Y is:15  Brightness is:15
Pixel16:
X is:16  Y is:16  Brightness is:15

For subtask 8: ( The first radardisplay contains RedPlaneIcon and yellowHeliIcon, the second radardisplay contains  RedPlaneIcon and purpleRocket)

The details of the data contained within the radarDisplay1:
This is the detail of the 1th icon in this radardisplay:
The id number is:1
Pixel1:
X is:16  Y is:16  Brightness is:5
Pixel2:
X is:15  Y is:15  Brightness is:5
Pixel3:
X is:14  Y is:14  Brightness is:5
Pixel4:
X is:13  Y is:13  Brightness is:5
Pixel5:
X is:12  Y is:12  Brightness is:5
Pixel6:
X is:11  Y is:11  Brightness is:5
Pixel7:
X is:10  Y is:10  Brightness is:5
Pixel8:
X is:9  Y is:9  Brightness is:5
Pixel9:
X is:8  Y is:8  Brightness is:5
Pixel10:
X is:7  Y is:7  Brightness is:5
Pixel11:
X is:6  Y is:6  Brightness is:5
Pixel12:
X is:5  Y is:5  Brightness is:5
Pixel13:
X is:4  Y is:4  Brightness is:5
Pixel14:
X is:3  Y is:3  Brightness is:5
Pixel15:
X is:2  Y is:2  Brightness is:5
Pixel16:
X is:1  Y is:1  Brightness is:5
This is the detail of the 2th icon in this radardisplay:
The id number is:2
Pixel1:
X is:16  Y is:1  Brightness is:10
Pixel2:
X is:15  Y is:2  Brightness is:10
Pixel3:
X is:14  Y is:3  Brightness is:10
Pixel4:
X is:13  Y is:4  Brightness is:10
Pixel5:
X is:12  Y is:5  Brightness is:10
Pixel6:
X is:11  Y is:6  Brightness is:10
Pixel7:
X is:10  Y is:7  Brightness is:10
Pixel8:
X is:9  Y is:8  Brightness is:10
Pixel9:
X is:8  Y is:9  Brightness is:10
Pixel10:
X is:7  Y is:10  Brightness is:10
Pixel11:
X is:6  Y is:11  Brightness is:10
Pixel12:
X is:5  Y is:12  Brightness is:10
Pixel13:
X is:4  Y is:13  Brightness is:10
Pixel14:
X is:3  Y is:14  Brightness is:10
Pixel15:
X is:2  Y is:15  Brightness is:10
Pixel16:
X is:1  Y is:16  Brightness is:10

The details of the data contained within the radarDisplay2:
This is the detail of the 1th icon in this radardisplay:
The id number is:3
Pixel1:
X is:1  Y is:16  Brightness is:8
Pixel2:
X is:2  Y is:15  Brightness is:8
Pixel3:
X is:3  Y is:14  Brightness is:8
Pixel4:
X is:4  Y is:13  Brightness is:8
Pixel5:
X is:5  Y is:12  Brightness is:8
Pixel6:
X is:6  Y is:11  Brightness is:8
Pixel7:
X is:7  Y is:10  Brightness is:8
Pixel8:
X is:8  Y is:9  Brightness is:8
Pixel9:
X is:9  Y is:8  Brightness is:8
Pixel10:
X is:10  Y is:7  Brightness is:8
Pixel11:
X is:11  Y is:6  Brightness is:8
Pixel12:
X is:12  Y is:5  Brightness is:8
Pixel13:
X is:13  Y is:4  Brightness is:8
Pixel14:
X is:14  Y is:3  Brightness is:8
Pixel15:
X is:15  Y is:2  Brightness is:8
Pixel16:
X is:16  Y is:1  Brightness is:8
This is the detail of the 2th icon in this radardisplay:
The id number is:1
Pixel1:
X is:16  Y is:16  Brightness is:5
Pixel2:
X is:15  Y is:15  Brightness is:5
Pixel3:
X is:14  Y is:14  Brightness is:5
Pixel4:
X is:13  Y is:13  Brightness is:5
Pixel5:
X is:12  Y is:12  Brightness is:5
Pixel6:
X is:11  Y is:11  Brightness is:5
Pixel7:
X is:10  Y is:10  Brightness is:5
Pixel8:
X is:9  Y is:9  Brightness is:5
Pixel9:
X is:8  Y is:8  Brightness is:5
Pixel10:
X is:7  Y is:7  Brightness is:5
Pixel11:
X is:6  Y is:6  Brightness is:5
Pixel12:
X is:5  Y is:5  Brightness is:5
Pixel13:
X is:4  Y is:4  Brightness is:5
Pixel14:
X is:3  Y is:3  Brightness is:5
Pixel15:
X is:2  Y is:2  Brightness is:5
Pixel16:
X is:1  Y is:1  Brightness is:5
 */
//-----------------------------------------------------------------------------
