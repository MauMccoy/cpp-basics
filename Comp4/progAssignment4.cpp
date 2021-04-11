/* 
// Programming Assignment 4 "Robot Speed Estimator"
// Author: Mauricio McCoy
// Completed: 03 - 11 - 2021
// Status: In Progress -> Pending Validation (character input generates infinite loop)
// 
// This is a program to estimate the speed of a robot. It uses a class called Robot to represent a robot.
// 
// Formulas and values needed:
// pi = 3.14159
// speedI (in inches x minute) = rpm * wheelDiameter * pi
// speedF (in feet x minute) = speedI / 12
//
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "robot.cpp"
#include "robot.h"

using namespace std;

/* variables */
double usrSpeed = 0;
double usrWheelDiameter = 0;

/* main function */
int main(){

    /* MENU */
    cout << "\n\tOPTIONS:";
    cout << "\n\t1) 75rpm";
    cout << "\n\t2) 190rpm";
    cout << "\n\t3) 265rpm";
    cout << "\n\tPress enter to continue... ";

    while (usrSpeed < 1 || usrSpeed > 3){
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignoring input characters up to newline
      cout << "\n\tEnter a User Speed Option: ";
      cin >> usrSpeed;
      cin.clear(); //Clearing any error flags
    }

    cout << "\n\t";
    
    while (usrWheelDiameter < 1 || usrWheelDiameter > 6 ){
      cin.clear(); //Clearing any error flags
      cin.ignore(numeric_limits<streamsize>::max(), '\n');  //Ignoring input characters up to newline
      cout << "\n\tEnter a Diameter between 1 and 6 inches: ";
      cin >> usrWheelDiameter;
    }

    cout << "-------------------------------------------------------------------\n";
    cout << "\n\tRESULTS:\n";
    /* initiate instance of robot */
    Robot android;
    android.setRPM(usrSpeed);
    android.setDiameter(usrWheelDiameter);
    cout << "\n\tWheel Diameter Now: " << android.getDiameter() << "\n";
    cout << "\n\tRobot Speed Option: " << usrSpeed << "\n";
    cout << "\n\tUsing getRPM (rpm * wheelDiameter * pi): " << android.getRPM() << "(inches x minute)\n";
    cout << "\n\tUsing getSpeed (rpm / 12): " << android.getSpeed() << "(feet x minute)\n";
    cout << "\n-------------------------------------------------------------------\n";
    return 0;
}

/* 
// SPECIFICATIONS:{
//    DONE    + Default constructor called Robot, initializes gearMoSpeed = 74 and wheelDiameter = 1;
//    DONE    + setRPM. Allows user to change gearMoSpeed of robot. has parameter newRPM that contains the new speed
//              ->new possible speeds: 74, 190, 265 (RPM's)
//    DONE    + setDiameter. Allows the member variable that stores the wheelDiameter to be updated.
//              ->New diameter must be greater than 1 inch and smaller than 6 inches
//                      newDiameter > 1 || newDiameter < 6
//    DONE    + getRPM. this function should return the speed of the gear motor in RPM's
//    DONE    + getDiameter. this function returns the diameter of the robots wheel in inches
//    DONE    + getSpeed. this function returns the speed of the robot in feet perminute
//    DONE    + Validation of input
//
//    TESTING:
//    DONE    + Constructor initializes a Robot object.
//    DONE    + setRPM must work correct with both valid and invalid values provided by the parameter
//    DONE    + setDiameter must be tested for both valid and invalid values provided by the parameter
//    DONE    + getRPM, getDiameter, getSpeed must return correct values.
// }
*/