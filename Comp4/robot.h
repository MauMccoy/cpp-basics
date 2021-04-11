#ifndef ROBOT
#define ROBOT
/* Robot class */
class Robot
{
private:        
    float gearMoSpeed;     //- Measured in revolutions * min
    float wheelDiameter;        //- Measured in Inches"

public:     //-NOTE: no input and output in member functions
    /* 
        Robot constructor: 
             initializes geatMoSpeed to 74 and wheelDiameter to 1.
    */
    Robot();

    /* 
        setRPM:
            Allows users to change the gearMoSpeed.
            Containes a parameter newRPM that stores the new speed.
     */
    void setRPM(double newRPM);

    /* 
        setDiameter:
            Allows the member variable that stores the wheelDiameter to be updated.
            New diameter must be greater than 1 inch and smaller than 6 inches
                      newDiameter > 1 || newDiameter < 6
    */
    void setDiameter(double newDiameter);

    /*  
        getRPM: 
            Returns the speed of the gear motor in RPM's (using inches) 
    */
    double getRPM();

    /* getDiameter. this function returns the diameter of the robots wheel in inches */
    double getDiameter();

    /* getSpeed. this function returnsthe speed of the robot in feet perminute */
    double getSpeed();
}; 

#endif