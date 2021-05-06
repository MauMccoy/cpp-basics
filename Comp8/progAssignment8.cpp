/* 
 *      Author: Mauricio McCoy
 *      Title : Programming Assignment 8
 *      Status: In-Progress 
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
    int id;
    char name[15];
    float grade;
};

/* FUNCTION PROTOTYPES */
void getGrades(struct Student *array, int &);
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
    struct Student array;
    
    /* FUNCTION CALLS */
    getGrades(&array, numStudents);         /* FUNCTION 1 (COMPLETE)*/    

    sortUp(&array, numStudents);            /* FUNCTION 2 (COMPLETE)*/

    average = averageGrade(&array, numStudents, average);   /* FUNCTION 3 (COMPLETE) */

    displayGrades(&array, numStudents, average);     /* FUNCTION 4 (COMPLETE)*/
}

/* FUNCTION DECLARATIONS */
/* INPUT FUNCTION (1)*/
void getGrades(struct Student *array, int &numStudents)
{
    float tempGrade;
    /* STUDENT TOTAL INPUT */
    printf("Enter the number of students in your class: ");
    scanf("%d", &numStudents);
    
    printf("Number of students in your class: %d", numStudents);
    printf("\n\n");

    /* GRADE INPUT */
    for(int i = 0; i < numStudents; ++i)
    {
        printf("Enter Name: ");
        scanf("%s",array[i].name);
        printf("Enter Grade: ");
        scanf("%f", &array[i].grade);                
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

                // array[i].name = array[j].name;
                char *temp = (char *)malloc((strlen(array[i].name) + 1) * sizeof(char));
                strcpy(temp, array[i].name);
                strcpy(array[i].name, array[j].name);
                strcpy(array[j].name, temp);
                free(temp);
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
        average += array[i].grade;
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
        cout << "\nName: \t" << setw(10) << array[i].name << "\t" << setw(10) << right << array[i].grade <<"\n\n";
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