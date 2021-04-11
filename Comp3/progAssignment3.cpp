/* 
// Programming Assignment 3
// Author: Mauricio McCoy
// Completed: 02 - 24 - 2021
// Status: Complete
// 
// This program performs basic addition and substraction tasks to a manage a monthly checkbook.
// It handles deposits (addition to the balance) as well as check transactions(substractions from the balance)
// using functions.
// Then provides a monthly total balance.
// It is also menu driven, provides user input validation and keeps track of a services charge fees.
*/

#include <iostream>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

/* 
    FUNCTION PROTOTYPES
 */
void initialBalance(float &balance);     //-Initial balance prototype
void usrChoice(char &transactionType);
float checkProcess(float &balance, float &transactionAmount);
float deposit(float &balance, float &transactionAmount);

int main(){

    /* PROGRAM VARIABLES */
    float balance;
    float charges = 0;
    float serviceCharge = .35;
    float lowFundCharge = 0;
    float negativeBalanceCharge = 30;
    float transactionAmount;
    char transactionType;


    /* Function call to get initial balance */
    initialBalance(balance);
    cout << "\n\tYour initial balance is: " << balance << "\n" << endl;                 //- Initial Balanace print out

    /* Insuficient fund charge */
    if (balance < 1000 && lowFundCharge != 10)
    {
        /* code */
        lowFundCharge = 10;
    } 

    do
    {
        /* MENU */
        cout << "\n\n\tOPTIONS:";
        cout << "\n\tC (process check)";
        cout << "\n\tD (process deposit)";
        cout << "\n\tE (process end of month)";

        /* Function call to get transaction type */
        usrChoice(transactionType);

        /* Main if/else loop according to selection */
        if (transactionType == 'C')      //-Objective A) Process checks (-)
        {
                /* code */
                cout << "\t\t\t\t  $";
                cin >> transactionAmount;     //-transaction ammount input
                while (transactionAmount < 0)     //-input validation
                {
                    /* code */
                    cout << "\tplease enter a positive number: ";
                    cin >> transactionAmount;
                }

                /* Check function call */
                checkProcess(balance, transactionAmount);
                charges += serviceCharge;

                /* Insuficient fund charge */
                if (balance < 1000 && lowFundCharge != 10)
                {
                    /* code */
                    lowFundCharge = 10;
                } 
                
                if (balance < 0)
                {
                    /* code */
                    charges += negativeBalanceCharge;
                }
                
                

                /* check process information */
                cout << fixed;
                cout << "\n\tProcessing check for $" << setprecision(2)<< transactionAmount;
                cout << "\n\tBalance: $" << setprecision(2) << balance;
                cout << "\n\tService charge: $0.35 for a check";
                cout << "\n\tService charge: $10.00 balance below $1000.00";
                cout << "\n\tTotal service charges: " << setprecision(2) << (charges + lowFundCharge) ;
                
                
        }
        else if (transactionType == 'D') 
        {
                /* code */
                cout << "\t\t\t\t  $";
                cin >> transactionAmount;     //-transaction ammount input
                while (transactionAmount < 0)     //-input validation
                {
                    /* code */
                    cout << "\tplease enter a positive number: ";
                    cin >> transactionAmount;
                }

                /* Deposit function call */
                deposit(balance, transactionAmount);

                /* Insuficient fund charge */
                if (balance < 1000 && lowFundCharge != 10)
                {
                    /* code */
                    lowFundCharge = 10;
                }

                /* Deposit process information */
                cout << fixed;
                cout << "\n\tProcessing deposit for $" << fixed << setprecision(2) << transactionAmount;
                cout << "\n\tBalance: $" << fixed << setprecision(2) << balance;
                cout << "\n\tService charge: $10.00 for balance below $1000.00";
                cout << "\n\tTotal service charges: " << fixed << setprecision(2) << (charges + lowFundCharge);

        }
        else if(transactionType == 'E') {

                /* Insuficient fund charge */
                if (balance < 1000 && lowFundCharge != 10)
                {
                    /* code */
                    lowFundCharge = 10;
                }

                /* Output code */
                cout << fixed;
                cout << "\n\tYour choice was " << transactionType;       //-prints current choice
                cout << "\n\tProcessing end of month..";        //-title for displayed text
                cout << "\n\tTotal service charges: " << setprecision(2) << (charges + lowFundCharge);
                cout << "\n\tFinal Balance : " << setprecision(2) << (balance - (charges + lowFundCharge)) << "\n\n";        //-Objective C) prints out monthly balance
                return 0;

        }
    } while (transactionType != 'C' || transactionType != 'D' || transactionType != 'E');
    


    return 0;
}

/* This function gets the users initial balance. */
void initialBalance(float &balance){

    cout << "\n\tCheckbook Balancing Program\n\n\tWhat is your initial balance: ";      //-Initial balance input prompt

    cin >> balance;
}

/* This function gets the transaction type from the user. */
void usrChoice(char &transactionType){

    cout << "\n\tEnter a transaction type: ";                                           //-Usr option transaction type
    cin >> transactionType;
    transactionType = toupper(transactionType);
}

/* This function does the check processing (-) by substracting from the balance*/
float checkProcess(float &balance,  float &transactionAmount){

    balance =  (balance - transactionAmount);         //-Objective A)

    return balance;
}

/* This function does the deposit processing (+) by adding to the balance */
float deposit(float &balance, float &transactionAmount){

    balance = (balance + transactionAmount);      //-Objective B)

    return balance;
}