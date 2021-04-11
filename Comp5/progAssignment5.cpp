/* 
// 
//      Programming Assignment 5 "Payroll Version 1.0"
//      Author: Mauricio McCoy
//      Completed: 04 - 01 - 2021
//      Status: COMPLETE
// 
//     This is a payroll program that allows the user to input General information about the employee
//     and timesheet information into struct's that are then used to calculate: Gross Pay, Net Pay,
//     and Tax Deductions. That are then used to print a payroll tabulated format output. 
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/* Employe Master Struct */
struct employeeMaster{
    /* data */
    int id;             //-Employee id
    string name;        //-Employee name
    float payRate;      //-Hourly payrate
    bool empType;       //-Employee type | 0 for union // 1 for management |
}employee[4];

/* Employee timesheet struct */
struct employeeTimesheet
{
    double hoursWorked;
}timesheet[4];

/* Payroll struct */
struct payroll
{
    double grossPay;
    double taxDeduction;
    double netPay;
}payrollInfo[4];

int main(){
    int n;
    double tax = .15;           /* tax declaration. */
    double overtimePay = 0;     /* overtime declaration. */
    int bTypeTest;              /* termporary variable for bool intput validation */

    /* Values for Controlling Format */
    int name_width = 20 ;
    int int_width = 7 ;
    int dbl_width = 12 ;
    int num_flds = 7 ;
    string sep = " |" ;
    int total_width = name_width*2 + int_width*2 + dbl_width*3 + sep.size() * num_flds ;
    string line = sep + string( total_width-1, '-' ) + '|' ;


    /* Menu: */
    cout << "\n\tPayroll: Armadillo Automotive Group\n";

    /* Master Info: */
    for ( n = 0; n < 4; n++)
    {
        cout << "\n\tEnter master info for employee " << n;
        /* Employee id
        // INPUT + VALIDATION
        */
        cout << "\n\tID: ";
        cin >> employee[n].id;        
        cin.ignore( numeric_limits <streamsize> ::max(), '\n' );
        if (employee[n].id <= 0)    /* Employee ID input validation */
        {
            while (employee[n].id <= 0)
            {
                cout << "\n\tID: ";
                cin >> employee[n].id;
                cin.ignore(numeric_limits <streamsize> ::max(), '\n');
            }
            
        }
        

        /* Employee name
        // INPUT + VALIDATION
        */
        cout << "\n\tName: ";
        getline(cin, employee[n].name);
        /* 
            figure out how to get string properly and limit to 20 characters            
        */    

        /* Employee payRate
        // INPUT + VALIDATION
        */
        cout << "\n\tPay-Rate(* hour): ";
        cin >> employee[n].payRate;     /* employee payRate */
        /* ->Hours Worked: Value must be greater than or equal to 0         */        
        if (employee[n].payRate < 0)    /* Employee payRate input validation */
        {
            while (employee[n].payRate < 0)
            {
                cout << "\n\tPay-Rate(* hour): ";       /* employee payRate */
                cin >> employee[n].payRate;
            }
            
        }

        /* Employee type:
        // INPUT + VALIDATION
        */  
        cout << "\n\tType: ";
        cin >> bTypeTest;
        /* empType can only be 1 or 0 */
        /* bTypeTest is used to validate data input */
        /* Then assigned to the structure if valid. */
        while (bTypeTest > 1 || bTypeTest < 0)
        {
            cout << "\n\tType: ";
            cin >> bTypeTest;
            if (bTypeTest == 1)
            {
                employee[n].empType = bTypeTest;
            }
            else if (bTypeTest == 0)
            {
                employee[n].empType = bTypeTest;
            }
        }
    }

/*
//  Time-sheet info input
*/
    for (int n = 0;n < 4; n++)
    {    
        cout << "\n\tHours worked for " << employee[n].name << ": ";
        cin >> timesheet[n].hoursWorked;
        
/* Input validation for hours worked */
        if (timesheet[n].hoursWorked < 0)
        {
            while (timesheet[n].hoursWorked < 0)    /* Added character input validation */
            {
                cout << "\n\tHours Worked for " << employee[n].name << ": ";
                cin >> timesheet[n].hoursWorked;
            }
            
        }
        
    }
    
/*  Calculations:
//      || Gross pay || Tax. || Net Pay is Gross Pay + Tax. 
*/
    for (int n = 0; n < 4; n++)
    {
        /* UNION or MANAGER conditional desicion */
        if (employee[n].empType == 0)
        {
            /* Gross pay UNION */
            if (timesheet[n].hoursWorked > 40)      /* UNION */
            {
                /* overtime payment calculation */
                overtimePay = (timesheet[n].hoursWorked - 40) * (employee[n].payRate * 1.5);

                /* gross payment + overtime calculation */
                payrollInfo[n].grossPay = (employee[n].payRate * timesheet[n].hoursWorked) + overtimePay;

                /* taxed deduction amount */
                payrollInfo[n].taxDeduction = payrollInfo[n].grossPay * tax;

                /* net payment calculation */
                payrollInfo[n].netPay = payrollInfo[n].grossPay - payrollInfo[n].taxDeduction;

            }
            else if (timesheet[n].hoursWorked >= 0 && timesheet[n].hoursWorked <= 40)
            {
                /* gross payment (without overtime payment) calculation */
                payrollInfo[n].grossPay = employee[n].payRate * timesheet[n].hoursWorked;
                /* value output test */

                /* taxed deduction amount */
                payrollInfo[n].taxDeduction = payrollInfo[n].grossPay * tax;
                /* value output test */

                /* net payment calculation */
                payrollInfo[n].netPay = payrollInfo[n].grossPay - payrollInfo[n].taxDeduction;
                /* value output test */

            }
        }
        else if(employee[n].empType == 1)            /* MANAGER */
        {
            /* Gross payment MANAGER */            
            payrollInfo[n].grossPay = employee[n].payRate * timesheet[n].hoursWorked;
            /* value output test */
            cout << "\n\tgrossPay: " << payrollInfo[n].grossPay;

            /* taxed deduction amount */
            payrollInfo[n].taxDeduction = payrollInfo[n].grossPay * .15;
            /* value output test */
            cout << "\n\ttaxDeduction: " << payrollInfo[n].taxDeduction;

            /* net payment calculation */
            payrollInfo[n].netPay = payrollInfo[n].grossPay - payrollInfo[n].taxDeduction;
            /* value output test */
            cout << "\n\tnetPay: " << payrollInfo[n].netPay;
        }        
        
    }

    cout << line << '\n' << sep
              << setw(name_width) << "ID" << sep << setw(name_width) << "Name" << sep
              << setw(dbl_width) << "Gross Pay" << sep << setw(dbl_width) << "Tax" << sep
              << setw(dbl_width) << "net pay" << sep << '\n' << line << '\n' ;

/* 
// Tabulated Output format
*/
    for( int n = 0 ; n < 4 ; n++ )
    {
        cout << sep << setw(name_width) << employee[n].id << sep << setw(name_width) << employee[n].name << sep
                  << fixed << setprecision(2)
                  << setw(dbl_width) << payrollInfo[n].grossPay << sep << setw(dbl_width) << payrollInfo[n].taxDeduction << sep
                  << setw(dbl_width) << payrollInfo[n].netPay << sep << '\n' ;
    }
    cout << line << '\n' ;

    return 0;
}