/* 
 *      Programming assignment 7 "Postal packages"
 *      Author: Mauricio McCoy
 *      Completed
 * 
 *      This program allows users to enter information about a package that include: weight, and three sides.
 *      After some input validation if the package is appropriate the program calculates the price of the package by using the input variables
 *      and comparing them to an array of structures that hold a standard value.
 *      It print the transaction information per transaction. At the end it prints the number of packages accepted and the number of packages
 *      rejected.
 *      
 */
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>

using namespace std;

/*  SHIPPING REQUIREMENTS:
 *      The package weight must not exceed 50 pounds.
 *      The package must not exceed 3 feet in length, width, or height.
 *      The girth of the package must not exceed 5 feet. The girth is the circumference around the two smallest sides of the package. If side1, side2, and side3 are the lengths of the three sides, and largest is the largest of the three sides, then the girth can be calculated using:
 *      girth = 2 * ( side1 + side2 + side3 - largest ) 
 */

/* GLOBAL CONSTANTS */
const int USR_DATA_SLOTS = 4;

const int TBL_ROWS = 15;

/* structures */
struct MeasureCost{
    int weight;
    float charge;
} measureCostChart[TBL_ROWS];

/*  FUNCTION PROTOTYPES
 *      getPackageInfo();
 */
void getPackageInfo(int &weight, float &sideX, float &sideY, float &sidez);
float searchPrice(struct MeasureCost measureCostChart[TBL_ROWS], int& weight, float& cost);
float girthCalculation(float &girth, float &sideX, float &sideY, float &sideZ, float &largest, bool &status, int &weight, int &transactionNumber);


int main()
{
    /* VARIABLES */
    int weight = 0;
    float largest = 0;
    float sideX = 0;
    float sideY = 0;
    float sideZ = 0;
    float girth = 0;
    float cost = 0;
    string message;
    /* counters */
    int transactionNumber = 0;
    int accepted = 0;
    int rejected = 0;
    bool status;

    struct MeasureCost measureCostChart[TBL_ROWS]= {{1, 1.5},
                                                        {2, 2.10},
                                                        {3, 4.0},
                                                        {5, 6.75},
                                                        {7, 9.90},
                                                        {10, 14.95},
                                                        {13, 19.40},
                                                        {16, 24.20},
                                                        {20, 27.30},
                                                        {25, 31.90},
                                                        {30, 38.50},
                                                        {35, 43.50},
                                                        {40, 44.80},
                                                        {45, 47.40},
                                                        {50, 55.20} };      /* COST/MEASURE ARRAY */


    /* PROGRAM TITLE */
    cout << "\n\tLonestar Package Service\n";

    while (weight != -1)
    {
            /* FUNCTION CALLS */
            getPackageInfo(weight, sideX, sideY, sideZ);  
            girthCalculation(girth, sideX, sideY, sideZ, largest, status, weight, transactionNumber);        
            if (weight == -1 or sideX == -1 or sideY == -1 or sideZ == -1)
            {
                cout << "\n\tNumber of accepted packages: " << accepted ;
                cout << "\n\tNumber of rejected packages: " << rejected << "\n";
                return 0;
            }

            if (status == true)
            {
                message = "Accepted";
                transactionNumber++;
                accepted++;
            }
            else
            {
                message = "Rejected";
                transactionNumber++;
                rejected++;
            }

            cout << "\n\tTransaction# :" << setw(5) << right << transactionNumber;
            cout << "\n\tStatus" << setw(8) << ":" << setw(12) << right  << message;
            cout << "\n\tWeight " << setw(7) << ":" << setw(6) << right << weight;
            cost = searchPrice(measureCostChart, weight, cost);
            if (status == false){cost = 0.0; cout << "\n\tCost " << setw(9) << ":" << setw(5) << right << setprecision(4) << cost << "\n";}
            else if (status == true){cout << "\n\tCost " << setw(9) << ":" << setw(8) << right << setprecision(4) << cost << "\n";}
            // cout << "\n\tGIRTH: " << setprecision(4) << girth;
    }

}

/*  FUNCTIONS
 *      calls:
 *          getPackageInfo();
 */

/*  getPackageInfo(); FUNCTION 
 *      Pending: get input in single line
 *      Pending: input validation.
 */
void getPackageInfo(int &weight, float &sideX, float &sideY, float &sideZ)
{
    printf("\n\tEnter package weight and 3 dimensions: ");

    printf ("\n\tWeight: ");    /* INPUT request */
    scanf("%d", &weight);       /* INPUT READ */
    /* Input validation (pounds) */
    if (weight ==-1)
    {
        return;
    }
    else if (weight <= 0 or weight > 50)
    {
        printf("\n\tWeight must be greater than 0 and less than or equal to 50\n");     /* Error Mesasge */
        return;
    }
    
    printf ("\n\tSide X: ");    /* INPUT request */
    scanf("%f", &sideX);        /* INPUT READ */
    /* Input validation (inches) */
    if (sideX == -1)
    {
        return;
    }
    if (sideX <= 0 or sideX > 36)
    {   
        printf("\n\tSide X must be greater than 0\n");      /* Error message */
        return;
    }
    
    printf ("\n\tSide Y: ");    /* INPUT request */
    scanf("%f", &sideY);        /* INPUT READ */
    /* Input validation (inches) */
    if (sideY ==-1)
    {
        return;
    }
    if (sideY == 0 or sideY >= 36)
    {
        cout << "\n\tSide Y must be greater than 0 and less than 36\n";         /* Error message */
        return;
    }

    printf ("\n\tSide Z: ");    /* INPUT request */
    scanf("%f", &sideZ);        /* INPUT READ */
    /* Input validation (inches) */
    if (sideZ ==-1)
    {
        return;
    }
    if (sideZ == 0 or sideZ >= 36)
    {
        printf("\n\tSide Z must be greater than 0 and less than 36\n");     /* Error message */
        return;
    }

}

/* Search Function */
float searchPrice(struct MeasureCost measureCostChart[TBL_ROWS], int& weight, float& cost)
{
    for (int row = 0; row < TBL_ROWS; row++)
    {
        if(weight <= measureCostChart[row].weight && weight > measureCostChart[row - 1].weight)
        {
            cost = measureCostChart[row].charge;
            // cout << cost;
        }
    }
    return cost;
}

/* 
 *  Girth Calculation Function
 */
float girthCalculation(float &girth, float &sideX, float &sideY, float &sideZ, float &largest, bool &status, int &weight, int &transactionNumber)
{
    float sizeTotal;
    if (sideX > sideY and sideX > sideZ)
    {
        largest = sideX;
    }
    else if (sideY > sideZ and sideY > sideX)
    {
        largest = sideY;
    }
    else
    {
        largest = sideZ;
    }
    sizeTotal = sideX + sideY + sideZ;
    /* girth formula
     *  girth = 2 * ( side1 + side2 + side3 - largest ) 
     */
    girth = (sizeTotal - largest) * 2;

    if (girth >= 50 or girth <= 0)
    {
        status = false;
    }
    else
    {
        status = true;
    }
    
    
    /* return */
    return girth;
}