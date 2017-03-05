//
//  main.cpp
//  CrapsGame
//
//
//  Created by Melinda Fernandes on 02/03/2017.
//  Copyright © 2017 Melinda Fernandes. All rights reserved.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <String>
using std::string;

#include <cstdlib>
using std::rand;
using std::srand;

#include <time.h>
using std::time;

int placeWager(int);
int runAGame();
int rollDice();     //declare functions


int main(){
    
    int bankBalance = 1000; //   initialise bankBalance to 1000 dollars
    int bet = 0;
    int result = 0;
    
    bet = placeWager(bankBalance);
    
    result = runAGame();
    
    // add or deduct wager bet from bank balance
    if (result == 1)
        bankBalance = bankBalance + bet;
    else {
        bankBalance = bankBalance - bet;
        if (bankBalance == 0){ // check if player bet all their money
            cout << "Sorry. You're busted!" << endl;
        }
    }
    
    cout << "Your new bank balance is $" << bankBalance << endl;
    
    return 0;   //terminate game
}

int placeWager(int bankBalance){
    
    int wager = 0;         //   initialise wager to 0
    
    //prompt player to enter wager
    cout << "Enter a wager: " << endl;
    cin >> wager;
    if (wager > bankBalance){
        while (wager > bankBalance)
            cout << "Enter a wager: " << endl;
        cin >> wager;
    }
    return wager;
    
}

int runAGame(){
    //function returns 0 if player lost, returns 1 if player won
    
    // declare and initialise variables
    int sum = 0;    // store returned sum from rollDice function
    int point = 0;  // store point when it has been made
    
    srand(time(0));     // store seed from time
    
    sum = rollDice();
    //cout << hasRolled << sum << endl;
    
    //  determine game outcome
    switch(sum){
            // player wins if
        case 7:     //roll 7 on first throw
        case 11:    //roll 11 on first throw
            cout << "WIN" << endl;
            return 1;       //
            // player loses if
        case 2:     //roll 2 on first throw
        case 3:     //etc.
        case 12:
            cout << "LOSE" << endl;
            return 0;       //
            // point is made and game continues if
        default:    //default cases cover sums 4, 5, 6, 8, 9, 10
            point = sum;    // point takes the value of whatever sum is
            cout << "Point made is " << point << endl;
            
            // continue game
            sum = rollDice();
            while (sum != point){
                if(sum ==7){
                    // lose if rolled 7 before point
                    //cout << hasRolled << sum << endl;
                    cout << "LOSE" << endl;
                    return 0;   //
                } else {
                    // continue game and while loop if any other number is rolled
                    sum = rollDice();
                    //cout << hasRolled << sum << endl;
                }
            } //point has been made, end while
            
            // sum == point, return win
            //cout << hasRolled << sum << endl;
            cout << "Point has been made!" << endl;
            cout << "WIN" << endl;
            
    }   // exit switch statement
    return 1; //end function
}

int rollDice(){     //returns sum of faces
    // declare and intialise local variables
    int faceOne = 0;
    int faceTwo = 0;
    int sumOfFaces = 0;
    string hasRolled = "You have rolled ";    // roll statement to be printed after rolls
    
    cout << "~Press Enter to roll the dice";
    cin.ignore();
    
    // picks a random number from 1 to 6 and stores in face values
    faceOne = (1 + rand() % 6);
    faceTwo = (1 + rand() % 6);
    sumOfFaces = faceOne + faceTwo;
    
    cout << hasRolled << sumOfFaces << "\n" << endl;
    
    return sumOfFaces;
    
}
