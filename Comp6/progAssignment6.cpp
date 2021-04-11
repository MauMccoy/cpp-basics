/* 
//      Programming Assignment 6.0 "Monkey Food"
//      Author: Mauricio McCoy
//      Completed: 00 - 00 - 2021
//      Status:
// 
//      Preview:
//      
//      Functions:
//      + Input function
//      + Output function
//      + Calculations: Average food eaten, Least food eaten, Most food eaten
*/
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

/* Function prototypes */
void usrInput(float &food);        /* User input function */
void resultOutput();                  /* Data output function */
float calculations();

/* USR INPUT FUNCTION */
void usrInput(float monkeyChart[][7], int n, int m){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << "How much did monkey" << (i+1) << "Eat on day " << (j+1);
            cin >> monkeyChart[i][j];
        }
        
    }
    
}

/* RESULT OUTPUT FUNCTION */

/* CALCULATIONS FUNCTION */
// float calculations(float &least, float &most, float monkeyChart[3][7]){
//     // Get least and greatest amount of food eaten by any one monkey.
//     least = most = monkeyChart[0][0];
//     for (int r = 0; r < 3; r++)
//     {
//         for (int c = 0; c < 7; c++)
//         {   
//             if (monkeyChart[r][c] < least)
//             { 
//                 least = monkeyChart[r][c];
//             }
//             if (monkeyChart[r][c] > most)
//             { 
//                 most = monkeyChart[r][c];
//             }
//         }
//     }
// }

/* MAIN FUNCTION */
int main(){

    /* Program general variables */
    int n = 3;
    int m = 7;
	int monkeyChart[n][m];
	float pounds, least, most, sum = 0;
	

	// Ask user to input data for each monkey
	cout << "Input how many pounds of food each monkey ate each day.\n";

    /* function calls */
    usrInput(monkeyChart, n, m);


	return 0;
    
}

