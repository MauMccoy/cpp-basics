/*

// Programming Assignment 1
// Author: Mauricio McCoy
// Completed: 01 / 27 / 21
// Status: Polishing last details
// 
// This program reads 2 inputs from a keyboard entry, then calculates 
// the sum, product, remainder after dividing the first integer by the 
// second (integer remainder), the result of dividing the first integer
// by the second using floating-point division (floating-point quotient)
// and the average of the intergers(usign floating-point division).

*/

#include <iostream>         //-input/output library
#include <iomanip>          //-i/o manipulation library
#include <math.h>           //-include math library 

using namespace std;

int main(){         //-Main function                               

    int usrInput;           //-variable definition for interger
    int usrInput2;          //-variable definition for interger --

    /* INPUT 
        I- This input section acquires the numbers from the user.
        Which are then used by the program to performe operations.
        There is a promt to the user requesting information, then 
        both of the inputs requested are saved in the variables:
        usrINput and usrInput2.
    */
    cout << "Enter 2 numbers\n";            //-Program output requesting user interaction.
    cout << "\nNumber1:\n";         //-User input request 1
    cin >> usrInput;            //-User keyboard input
    cout << "\nNumber2:\n";         //-User iput request 2
    cin >> usrInput2;           //-User keyboard input 2

    /* OBEJCTIVE 1 
        I- This part of the program performs the sum of the two
        input variables (usrInput & usrInput2). Then prints its result.
    */
    int sum = (usrInput + usrInput2);           //-Sum of user input
    cout << "\n SUM: " << sum << " \n";         //-Display of Sum    

    /* OBJECTIVE 2 
        I- This part of the program performs a multipication of the two
         input variables (usrInput & usrInput2). Then prints its results.
    */
    int product = (usrInput * usrInput2);               //-Product(multiplication) of user input
    cout << "\n PRODUCT: " << product << "\n";          //-Display of Product

    /* OBJECTIVE 3 
        I- This part of the program performs a interger quotient division
        of the two input variables (usrInput & usrInput2). Then prints its results.
    */
    int intQuo = usrInput / usrInput2;          //-Interger Quotient(division) of user input
    cout << "\n INT QUOTIENT: "<< intQuo << "\n";           //-Display of Interger Quotient

    /* OBJECTIVE 4 
        I- This part of the program gets the interger remainder of the usrInput variable
        and usrInput2 variable. Then prints its results.
    */
    double intRem = usrInput % usrInput2;           //-Remainder of user input
    cout << "\n INT REMAINDER: " << intRem << "\n";         //-Display of interger remainder

    /* UPDATED VARIABLES 
        I- Here the program assigns a float conversion of both of the input variables(usrInput
        & usrInput2). 
    */
    float usrInputUpdated = (float) usrInput ;          //-Interger to Float type conversion
    float usrInputUpdated2 = (float) usrInput2;         //- used to accomplish decimal point calculations

    /* OBJECTIVE 5 
        I- This part of the program performs a float type division of the two
        input variables (usrInputUpadated & usrInputUpdated2). Then prints its results.
    */
    float floQuo = usrInputUpdated / usrInputUpdated2;          //-Floating type quotient of user input
    cout << "\n FLOAT QUOTIENT: " << floQuo << "\n";            //-Display of float type quotient

    /* OBJECTIVE 6 
        I- This part of the program performs a float type average of the two
        input variables (usrInpuUpdatedt & usrInputUpdated2). Then prints its results.
    */
    float average = (usrInputUpdated + usrInputUpdated2)/2;         //-Float type average of user input
    cout << "\n FLOAT AVERAGE: " << average << "\n";            //-Display of float type average

    /*  END... */
    cout << "\nthe end\n";          //-Visual description of end of program.    
}