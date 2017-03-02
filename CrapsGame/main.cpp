//
//  main.cpp
//  CrapsGame
//
//  Created by Melinda Fernandes on 02/03/2017.
//  Copyright © 2017 Melinda Fernandes. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;

#include <String>
using std::string;

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
    if (sum == 7 || sum == 11){
        cout << "WIN" << endl;
        return 0;       // terminate game
    }
    if (sum == 2 || sum == 3 || sum == 12){
        cout << "LOSE" << endl;
        return 0;       //terminate game
    }
    if (sum == 4 || sum == 5 || sum == 6 || sum == 8 || sum == 9 || sum == 10 ){
        point = sum;
        cout << "Point made is " << point << endl;
        
        sum = rollDice();
        while (sum != point){
            if (sum == 7){
                cout << hasRolled << sum << endl;
                cout << "LOSE" << endl;
                return 0;   // terminate game
            }
            else
                sum = rollDice();   // to continue while loop
        }   // end while
        
        //return "WIN" as while condition is not satisfied
        cout << hasRolled << sum << endl;
        cout << "Point has been made" << endl;
        cout << "WIN" << endl;
        
    }
    
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
