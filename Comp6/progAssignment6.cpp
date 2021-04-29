/* 
//      Programming Assignment 6.0 "Monkey Food"
//      Author: Mauricio McCoy
//      Completed: 04 - 09 - 2021 
// 
//      Preview:
//      This program uses functions to read user input into a 2 dimensional array (3x7) that contains amounts of food eaten by 3 monkeys
//      everyday of the week. The it prints it results in a tabulated char. Finally it calculates the average food eaten by every monkey,
//      the least and most food eaten by any monkey throughout the week.
// 
*/
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

const int monkeys = 3;
const int days = 7;

/* Prototypes */
void getInfo(struct MonkeyFood monkeyChart[][days], int numMonkeys);                /* Input */
void printInfo(struct MonkeyFood monkeyChart[][days], int numMonkeys);              /* Output */
void foodCalculations(struct MonkeyFood monkeyChart[][days], int numMonkeys);       /* Calculations */

/* Food information STRUCTURE */
struct MonkeyFood
{
    float food;
};

/* MAIN FUNCTION */
int main(){

    /* Program general variables */
    MonkeyFood monkeyChart[monkeys][days];      /* (Initialization) Array of struct's */

	// Ask user to input data for each monkey
	cout << "Input how many pounds of food each monkey ate each day.\n";

    /* function calls */
    getInfo(monkeyChart, monkeys);  
    printInfo(monkeyChart, monkeys);
    foodCalculations(monkeyChart, monkeys);

	return 0;
}

/* USR INPUT FUNCTION 
// This function iterates through the 2 dimensional array and assigns the user input value to memory
*/
void getInfo(struct MonkeyFood monkeyChart[][days], int numMonkeys){
    for (int i = 0; i < numMonkeys; i++)
    {
        for (int j = 0; j < days; j++)
        {
            cout << "How much did monkey " << (i+1) << " Eat on day " << (j+1) << ": ";
            cin >> monkeyChart[i][j].food;
            if (monkeyChart[i][j].food < 0)
            {
                while (monkeyChart[i][j].food < 0)
                {
                    cout << "How much did monkey " << (i+1) << " Eat on day " << (j+1) << ": ";
                    cin >> monkeyChart[i][j].food;
                }   
            }
        }   
    }
}


/* RESULT OUTPUT FUNCTION 
// This function prints a tabulated chart of the 2 dimensional array after acquiring user input
*/
void printInfo(struct MonkeyFood monkeyChart[][days], int numMonkeys){
    /* Values for Controlling Format */
    int name_width = 20 ;
    int dbl_width = 12 ;
    string sep = " |" ;

    cout << '\n' << sep
              << setw(name_width) << "Monkey" << sep << setw(dbl_width) << "Sun" << sep
              << setw(dbl_width) << "Mon" << sep << setw(dbl_width) << "Tue" << sep
              << setw(dbl_width) << "Wed" << sep << setw(dbl_width) << "Thu" << sep
              << setw(dbl_width) << "Fri" << sep << setw(dbl_width) << "Sat" << sep
              << '\n' << '\n' ;

    for( int i = 0 ; i < numMonkeys ; i++ )
    {
                cout << sep
                     << setw(name_width) << (i+1)
                     << sep 
                     << setw(dbl_width) << monkeyChart[i][0].food << sep << setw(dbl_width) << monkeyChart[i][1].food << sep
                     << setw(dbl_width) << monkeyChart[i][2].food << sep << setw(dbl_width) << monkeyChart[i][3].food << sep
                     << setw(dbl_width) << monkeyChart[i][4].food << sep << setw(dbl_width) << monkeyChart[i][5].food << sep
                     << setw(dbl_width) << monkeyChart[i][6].food << sep << '\n' ;
    }
    
    cout << '\n' ;
}

/* CALCULATIONS FUNCTION 
// This function calculates an average, finds minimum, maximum and prints calculations using setw()
*/
void foodCalculations(struct MonkeyFood monkeyChart[][days], int numMonkeys){
    /* variables */
    float sum;
    float average;
    float minimum = monkeyChart[0][0].food;
    float maximum = monkeyChart[0][0].food;

    /* * * * * * Average * * * * * * * * * * * * */
    for (int i = 0; i < numMonkeys; i++)
    {
        for (int j = 0; j < days; j++)
        {
            sum += monkeyChart[i][j].food;
        } 
    }
    average = sum / 21;   
    /* * * * * * * * * * * * * * * * * * * * * * */

    /* * * * * * Least * * * * * Most * * * * * */
    for (int i = 0; i < numMonkeys; i++)
    {
        for (int j = 0; j < days; j++)
        {
            if (monkeyChart[i][j].food < minimum + 1)
            {
                minimum = monkeyChart[i][j].food;
            } else if (monkeyChart[i][j].food > maximum) {
                maximum = monkeyChart[i][j].food;
            }            
        }
    }
    /* * * * * * * * * * * * * * * * * * * * * * */

    /* * * * * CALCULATION OUTPUT * * * * * * * */
    cout << "\n";
    cout << setw(36) << "\n\tAverage food eaten by all monkeys: " << setw(8)  << right << average;
    cout << setw(40) << "\n\tLeast food eaten by any monkey: " << setw(11) << right << minimum;
    cout << setw(40) << "\n\tMost food eaten by any monkey: " << setw(12) << right << maximum;
    cout << "\n";

    
}