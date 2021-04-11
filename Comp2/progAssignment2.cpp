// Programming Assignment 1
// Author: Mauricio McCoy
// Completed: 02 / 07 / 21
// Status: Comple
// 
// This program performs basic addition and substraction tasks to a manage a monthly checkbook.
// It handles deposits (addition to the balance) as well as check transactions(substractions from the balance).
// Then provides a monthly total balance.
// It is also menu driven, provides user input validation and keeps track of a services charge fee.


#include <iostream>     //-input/output library
#include <iomanip>      //-input/output manipulation library
#include <cctype>       //-toupper function library
#include <math.h>       //-c++ mathlibrary

using namespace std;

int main (){        //-main function

    /* 
    INSTRUCTIONS
        Here the program provides instructions for user input, by giving menu instructions.
        Then the program allows input and converts it into uppercase ussing the 'toupper()' function
    */
    double balance;     //-balance variable definition
    char choice;        //-choice variable definition
    double transAmount;     //-transaction amount variable definition
    double serviceCharge = .35;     //-service charge constant definition
    cout << "\n\tCheckbook Balancing Program\n\n\tWhat is your initial balance: ";      //-initial balance input prompt
    cin >> balance;     //-initial balance input    

    /* 
    MENU
    */
    cout << "\n\tOPTIONS:\n";

    cout << "\n\tC (process check)\n";

    cout << "\n\tD (process deposit)\n";

    cout << "\n\tE (process end of month)\n";

    cout << "\nEnter Transaction Type: \n";

    cin >> choice;      //-Input user choice
    choice = (toupper(choice));     //-Input conversion to uppercase   
    
    /* 
    OBJECTIVES:
        A) Process checks (-)
        B) Process deposits (+)
        C) Provide end of month total
     */
    do {        //-Do while loop 
        cout << "\n\tCurrent Balance: " << balance << "\n";     //-prints out current balance

        if (choice == 'C')      //-Objective A) Process checks (-)
        {
            /* code */
            cout << "\n\tYour choice was " << choice;       //-prints out current choice
            cout << "\n\tEnter transaction amount: ";       //-Instructions requiring transaction amount
            cin >> transAmount;     //-transaction ammount input
            while (transAmount < 0)     //-input validation
            {
                /* code */
                cout << "\n\tplease enter a positive number: ";
                cin >> transAmount;
            }
            

            cout << "\tProcessing check for: $" << transAmount;     //-transaction amount display

            balance =  (balance - transAmount) - serviceCharge;         //-Objective A)

            cout << "\n\tService charge: $.35 for a check\n\tTotal service charges: " << serviceCharge;     //-prints service charge
            cout << "\n\tYour balance is now: $" << balance << "\n";        //-prints updated balance
        }
        else if (choice == 'D')     //-Objective B) Deposits (+)
        {
            /* code */
            cout << "\n\tYour choice was " << choice;       //-prints current choice 
            cout << "\n\tEnter transaction amount: ";       //-instructions requiring transaction amount
            cin >> transAmount;     //-transaction amount input
            while (transAmount < 0)     //-input validation
            {
                /* code */
                cout << "\n\tplease enter a positive number: ";
                cin >> transAmount;
            }
            cout << "\tProcessing deposit for: $" << transAmount;       //-transaction amount display

            balance = (balance + transAmount) - serviceCharge;      //-Objective B)

            cout << "\n\tService charge: $.35 for a check\n\tTotal service charges: " << serviceCharge;     //-prints service charge
            cout << "\n\tYour balance is now: $" << balance << "\n";        //-prints updated balance


        }
        else if(choice == 'E')      //-Objective C) End of month total
        {
            /* code */
            cout << "\n\tYour choice was " << choice;       //-prints current choice
            cout << "\n\tProcessing end of month..";        //-title for displayed text
            cout << "\n\tFinal Balance : " << balance << "\n\n";        //-Objective C) prints out monthly balance
            return 0;

        } else
        {
            /* 
                Input validation for transaction types:
                'C', 'D', 'E'
            */
            cout << "\n\tPlease enter 'C', 'D' or E...\n";
            cout << "\n\tEnter a transaction type: ";
            cin >> choice;
        }

        cout << "\n\tEnter a transaction type: ";
        cin >> choice;
        choice = toupper(choice);

        
    } while(choice == 'C' || choice == 'D' || choice == 'E');

    cout << "\n\tProgram ending";

}