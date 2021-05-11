/* 
 *      Author: Mauricio McCoy
 *      Title : Programming Assignment 8
 *      Complete
 * 
 *      This program uses functions, structures and pointers to creade a gradebook.
 *      The user is allowed to specify the number of students in the class. Then is asked for grade inputs.
 *      After aquiring the grades from the user, the programs sorts the grades of the class in ascending order.
 *      Calculates the average. And displays the grades. Main actions are functions.
 * 
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

/* STRUCTURES */
struct Student
{
    float grade;
};

/* FUNCTION PROTOTYPES */
void getGrades(struct Student *array, int &, float &, float &);
void sortUp(struct Student *array, int &);
float averageGrade(struct Student *array, int &, float &);
void displayGrades(struct Student *array, int &, float &);
    /* EXTRAS */
void line();

int main ()
{
    /* VARIABLES */
    int numStudents = 0;
    float average = 0;
    float maxGrade = 105.00;
    float minGrade = 0.00;
    struct Student array;
    
    /* FUNCTION CALLS */
    getGrades(&array, numStudents, maxGrade, minGrade);                         /* FUNCTION 1 (COMPLETE)*/    

    sortUp(&array, numStudents);                            /* FUNCTION 2 (COMPLETE)*/

    average = averageGrade(&array, numStudents, average);   /* FUNCTION 3 (COMPLETE) */

    displayGrades(&array, numStudents, average);            /* FUNCTION 4 (COMPLETE)*/
}

/* FUNCTION DECLARATIONS */
/* INPUT FUNCTION (1)*/
void getGrades(struct Student *array, int &numStudents, float &maxGrade, float &minGrade)
{
    float tempGrade;
    
    /* STUDENT TOTAL INPUT */
    printf("Enter the number of students in your class: ");
    scanf("%d", &numStudents);
    printf("\n\n");

    /* GRADE INPUT */
    for(int i = 0; i < numStudents; ++i)
    {
        printf("Enter Grade: ");
        tempGrade = scanf("%f", &array[i].grade);
        if (array[i].grade < minGrade or array[i].grade > maxGrade)
        {
            while (array[i].grade < minGrade or array[i].grade > maxGrade)
            {
                /* code */
                printf("Enter Grade: ");
                tempGrade = scanf("%f", &array[i].grade);
            }
            
        }
        

    }  
}

/* ASCENDING SORT FUNCTION (2)*/
void sortUp(struct Student *array, int &numStudents)
{
    int counter = 0;
    float placeholder;
    //  ASCENDING SORT
	for(int i = 0; i < numStudents; i++)
	{		
		for(int j = i + 1; j < numStudents; j++)
		{
			if(array[i].grade>array[j].grade)
			{
                /* grades */
				placeholder  = array[i].grade;
				array[i].grade = array[j].grade;
				array[j].grade = placeholder;
			}
		}
	}    
}

/* AVERAGE GRADE FUNCTION (3)*/
float averageGrade (struct Student *array, int &numStudents, float &average)
{
    float sum = 0;
    for (int i = 0; i < numStudents; i++)
    {
        average += (array + i)->grade;
    }
    average /= numStudents;
    return average;
}

/* DISPLAY INFORMATION FUNCTION (4)*/
void displayGrades(struct Student *array, int &numStudents, float &average)
{
    printf("Displaying Information:\n\n");
    cout << setw(36) << "Grade:\n";
    line();
    for(int i = 0; i < numStudents; ++i)
    {    
        cout << setw(34) << right << array[i].grade <<"\n\n";
    };
    line();
    cout << "\nAverage: \t" << setprecision(4) << setw(18) << average << "\n\n";
}

/* EXTRAS */
void line()
{
    for (int i = 0; i < 36; i++)
    {
        cout << "-";
    }
    cout << "\n";
}