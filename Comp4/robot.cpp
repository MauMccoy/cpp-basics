#include "robot.h"

using namespace std;
/* Constructor */
Robot::Robot(){
    gearMoSpeed = 74;
    wheelDiameter = 1;
}

/* 
    setRPM:
        Allows users to change the gearMoSpeed. -> According to their menu choice
        Contains a parameter newRPM that stores the new speed.
*/
void Robot::setRPM(double newRPM){
    if (newRPM == 1)
    {
        /* code */
        gearMoSpeed = 75;        
        
    } else if (newRPM == 2)
    {
        /* code */
        gearMoSpeed = 190;            
        
    } else if (newRPM == 3)
    {
        /* code */
        gearMoSpeed = 265;            
        
    }            
        
}
/* 
    setDiameter:

*/
void Robot::setDiameter(double newDiameter){
    wheelDiameter = newDiameter;
}

/*  
    getRPM: 
        Returns the speed of the gear motor in RPM's (using inches) 
*/
double Robot::getRPM(){
    gearMoSpeed = (gearMoSpeed * wheelDiameter * 3.1416);
    return gearMoSpeed;
}

/*  
    getDiameter:
        Returns the diameter of the robots wheel in inches 
*/
double Robot::getDiameter(){
    return wheelDiameter;
}

/* 
    getSpeed:

*/
double Robot::getSpeed(){
    gearMoSpeed = ( gearMoSpeed / 12);
    return gearMoSpeed;
}
