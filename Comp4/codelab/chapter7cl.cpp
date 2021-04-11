/* 
//  These snippets are practice for chapter 7
//          * Classes and Objects *
*/
#include <iostream>
#include <string>

using namespace std;

/* 1 */
class Player
{
public:
    /* data */
    string name;
    int score;

    void setName(string n){
        name = n;
    }

    void setScore(int s){
        score = s;
    }

    string getName(){
        return name;
    }

    int getScore(){
        return score;
    }

};
/* * */

/* 2 */
class Counter
{
public:
    /* data */
    int counter;

    Counter(){
        counter = 0;
    }

    void increment(){
        counter += 1;
    }

    int getValue(){
        return counter;
    }
};
/* * */

/* 3 */
Calculator calc;
/* * */

/* 4 */
BankAccount account("John Smith", "123-45-6789");
/* * */

/* 5 */
class Accumulator
{
    public:
        /* data member */
        int sum;
        
        /* constructor */
        Accumulator(){ 
            sum = 0; 
        }

        /* function // no parameter // returns intergers */
        int getSum(){
            return sum;
        }

        /* function // interger parameter // returns nothing */
        int add(int a){
            sum += a;
        }
};
/* * */

/* 6 */
class GasTank
{
    public:
        /* data member */
        double amount;
        
        /* constructor */
        GasTank(){ 
            amount = 0; 
        }

        /* function // no parameter // returns intergers */
        void addGas(double a){
            amount += a;
        }

        /* function // interger parameter // returns nothing */
        void useGas(double b){
            amount -= b;
            if (amount < 0)
            {
                /* code */
                amount = 0;
            }
            
        }

        bool isEmpty(){
            if (amount < 0.1)
            {
                /* code */
                return true;
            } else {
                return false;
            }
        }

        double getGasLevel(){
            return amount;
        }
};
/* * */

/* 7 */
Window(int width, int height, int xPos, int yPos)
    : width(width), height(height), xPos(xPos), yPos(yPos)
{}

Window(int width, int height)
	: width{ width }, height{ height }, xPos{ 0 }, yPos{ 0 }
	{ }
/* * */

/* 8 */
~Window(){
    close();
    freeResources();
};
/* * */

/* 9 */
class Player
{
private:
    /* data */
    string name;
    int score;
public:
    void setName(string name);
    void setScore(int score);
    string getName();
    int getScore();
};

/* * */

/* 10 */
#include "Player.h"

using namespace std;

string name;
int score;

Player::setName(string name){

}
Player::setScore(int score){

}
string Player::getName(){
    return name;
}
int Player::getScore(){
    return score;
}
/* * */

/* 11 */
int counter;

Counter::Counter(){
    counter = 0;
}

void Counter::increment(){
    counter += 1;
}

int Counter::getValue(){
    return counter;
}
/* * */

/* 12 */
class Counter
{
private:    
    int counter;
public:
	Counter();
    void increment();
    getValue();
};
/* * */

int main (){

    return 0;
}