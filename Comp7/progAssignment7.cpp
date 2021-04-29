/* 
 *      Programming assignment 7 "Postal packages"
 *      Author: Mauricio McCoy
 *      Completed: 00 - 00 - 00
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
void searchPrice(struct MeasureCost measureCostChart[TBL_ROWS]);


int main()
{
    /* VARIABLES */
    int weight;
    int tempWeight;
    float sideX;
    float sideY;
    float sideZ;
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

            searchPrice(measureCostChart);
    }
    
    cout << "\n\t" << weight << "\t" << sideX << "\t" << sideY << "\t" << sideZ <<"\n"; 

    return 0;
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
    cout << "\n\tEnter package weight and 3 dimensions: ";
    printf ("\n\tWeight: ");
    scanf("%d", &weight);
    if (weight <= 0 || weight > 50)
    {
        return;
    }
    
    printf ("\n\tSide X: ");
    scanf("%f", &sideX);
    if (sideX <= 0 || sideX > 36)
    {
        return;
    }
    
    printf ("\n\tSide Y: ");
    scanf("%f", &sideY);
    if (sideY <= 0 || sideY > 36)
    {
        return;
    }

    printf ("\n\tSide Z: ");
    scanf("%f", &sideZ);
    if (sideZ <= 0 || sideZ > 36)
    {
        return;
    }
    
}

/* Search Function */
void searchPrice(struct MeasureCost measureCostChart[TBL_ROWS])
{
    for (int row = 0; row < TBL_ROWS; row++)
    {
        cout << setw(5) << measureCostChart[row].weight << "-"<<  measureCostChart[row].charge;
    }
    
}