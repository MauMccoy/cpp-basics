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
#include <math.h>
using namespace std;

int main(){         //-Main function                               

    int usrInput;           //-variable definition for interger
    int usrInput2;          //-variable definition for interger

    // input 
    cout << "Enter 2 numbers\n";            //-Program output requesting user interaction.
    cout << "\nNumber1:\n";         //-User input request 1
    cin >> usrInput;            //-User keyboard input
    cout << "\nNumber2:\n";         //-User iput request 2
    cin >> usrInput2;           //-User keyboard input 2

    // objective 1
    int sum = (usrInput + usrInput2);           //-Sum of user input
    cout << "\n SUM: " << sum << " \n";         //-Display of Sum    

    // objective 2
    int product = (usrInput * usrInput2);               //-Product(multiplication) of user input
    cout << "\n PRODUCT: " << product << "\n";          //-Display of Product

    // objective 3
    int intQuo = usrInput / usrInput2;          //-Interger Quotient(division) of user input
    cout << "\n INT QUOTIENT: "<< intQuo << "\n";           //-Display of Interger Quotient

    // objective 4
    double intRem = usrInput % usrInput2;           //-Remainder of user input
    cout << "\n INT REMAINDER: " << intRem << "\n";         //-Display of interger remainder

    // updated variables
    float usrInputUpdated = (float) usrInput ;          //-Interger to Float type conversion
    float usrInputUpdated2 = (float) usrInput2;         //- used to accomplish decimal point calculations

    // objective 5
    float floQuo = usrInputUpdated / usrInputUpdated2;          //-Floating type quotient of user input
    cout << "\n FLOAT QUOTIENT: " << floQuo << "\n";            //-Display of float type quotient

    // objective 6
    float average = (usrInputUpdated + usrInputUpdated2)/2;         //-Float type average of user input
    cout << "\n FLOAT AVERAGE: " << average << "\n";            //-Display of float type average

    cout << "\nthe end\n";          //-Visual description of end of program.    
}