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
using std::endl;

#include <String>
using std::string;

#include <cstdlib>
using std::rand;
using std::srand;

#include <time.h>
using std::time;

int rollDice();     //declare function

int main(){
    
    // declare and initialise variables
    int sum = 0;    // store returned sum from rollDice function
    int point = 0;  // store point when it has been made
    string hasRolled = "Player has rolled ";    // roll statement to be printed after rolls

    srand(time(0));     // store seed from time
    
    sum = rollDice();
    cout << hasRolled << sum << endl;
    
    //  determine game outcome
    switch(sum){
        // player wins if
        case 7:     //roll 7 on first throw
        case 11:    //roll 11 on first throw
            cout << "WIN" << endl;
            return 0;       // terminate game
        // player loses if
        case 2:     //roll 2 on first throw
        case 3:     //etc.
        case 12:
            cout << "LOSE" << endl;
            return 0;       //terminate game
        // point is made and game continues if
        default:    //default cases cover sums 4, 5, 6, 8, 9, 10
            point = sum;    // point takes the value of whatever sum is
            cout << "Point made is " << point << endl;
            
            // continue game
            sum = rollDice();
            while (sum != point){
                switch(sum){
                    // lose if rolled 7 before point
                    case 7:
                        cout << hasRolled << sum << endl;
                        cout << "LOSE" << endl;
                        return 0;   // terminate game
                    // continue game and while loop if any other number is rolled
                    default:
                        sum = rollDice();
                }
            } //point has been made, end while
            
            // sum == point, return win
            cout << hasRolled << sum << endl;
            cout << "Point has been made" << endl;
            cout << "WIN" << endl;
            
    }   // exit switch statement

    
    return 0;   //terminate game
}

int rollDice(){     //returns sum of faces
    // declare and intialise local variables
    int faceOne = 0;
    int faceTwo = 0;
    int sumOfFaces = 0;
    
    // picks a random number from 1 to 6 and stores in face values
    faceOne = (1 + rand() % 6);
    faceTwo = (1 + rand() % 6);
    sumOfFaces = faceOne + faceTwo;
    
    return sumOfFaces;
    
}
