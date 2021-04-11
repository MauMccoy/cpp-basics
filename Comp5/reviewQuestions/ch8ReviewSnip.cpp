/* 
//      CHAPTER 8 REVIEW EXERCISES
//      
//      Review Questions and Exercises: 1, 3, 7, 17, 23, 25, 29, 31, 33, 37, 39.
//      Answers to Review Questions and Exercises are in Appendix D in the textbook.
// 
*/
#include <iostream>

using namespace std;

// Prototypes
float listTotal(float list[], int length);

int main(){

    int length = 20;
    float list[length];

    cout << listTotal(list, length);


    return 0;
}


/* 
//      (END) BOOK EXERCISES
*/

/* 
//      CHAPTER 8 OTHER EXERCISES 
*/


/* 1 */
// Write a value-returning function that calculates and returns the sum of the elements in a one-dimensional array of float values.
// The array and the array length should be parameters to the function. 
float listTotal(float list[], int length ){
   int index;
   float sum = 0.0;

   for (index = 0; index < length; index++){
       sum = sum + list[index];
   }
   return sum;
}

/* 
//      (END) OTHER EXERCISES
*/