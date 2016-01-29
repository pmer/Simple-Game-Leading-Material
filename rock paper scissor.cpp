/***********************************************
Input: string (r, p, s)
main: computer-generated rock or paper or scissor, compare if input and com-gen is the same
output: win (same) or lose

improvement: take input including capital letter, COMMENT PROPERLY
Steps: what does this program do (this box), comment input function, input function, comment getRand funtion, ...
comment is psuedocode, help you visualize all the steps and the possibility of your code
comment will help your teammate read your codes
comment will help you understand what you wrote.
Put an index at the beginning of your code to quickly allocate the code you need (remember how messy code Pacfish codes and
************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void getInput (string& );
string getRand();
void output(string, string);

int main (){
    string input;               //input: takes input from user (r, p, s)
    string answer;              //answer: computer-generate answer (rock, paper, scissors)

    //get input from user and a computer-generated answer
    getInput(input);
    answer = getRand ();

    cout <<"\nUser: " <<input;
    cout <<"\nComputer: " <<answer;

    output(input, answer);

    return 0;
}


/*********************** getInput() ********************************
Parameter: &string
return: nothing
Purpose: get string input from user
*****************************************************************/
void getInput (string &input){
     cout <<"Welcome to 'Rock', 'Paper', 'Scissors' game.\n You will play against the computer\n";
    cout <<"r\t\t for rock\n" <<"p\t\t for paper\n" <<"s\t\t for scissors\n";
    cout <<"Enter your choice (r, p, s): ";
    cin >>input;
    while (input != "r" && input != "p" && input != "s"){
        cout <<"Invalid input. Please re-input";
        cin >>input;
    }

    if (input == "r")
        input = "rock";
    else if (input == "p")
        input = "paper";
    else if (input == "s")
        input = "scissors";

    /* Can't switch string
    switch (input){
    case "r": input = "rock";
    case "p": input = "paper";
    case "s": input = "scissors";
    }
    */
}

/********************** getRand() *********************************
Parameter: none
return: a string (rock || paper || scissors)
How it works: computer randomly generate a number, switch that number to string.
*******************************************************************/
string getRand(){
    short temp;             //temp: holds random number computer generated
    string answer;
    temp = rand() % 3 + 1 ;  //randomly generate from 0 - 2 then + 1, so 1- 3

    switch(temp){
    case 1: answer = "rock"; break;
    case 2: answer = "paper"; break;
    case 3: answer = "scissors"; break;
    }

    return answer;
}

/********************** output() ************************************
Parameter: input (string), answer (string)
Return   : nothing
What it does: compare input and answer and print out if user is winner or not
*********************************************************************/
void output(string input, string answer){
    int gameState;          //gameState == 1: win
                            //gameState == 2: lose
                            //gameState == 3: tie

    if (input == "rock"             && answer == "paper")
            gameState = 2;
    else if (input == "paper"       && answer == "scissors")
            gameState = 2;
    else if (input == "scissors"    && answer == "rock")
            gameState = 2;
    else if (input == answer )
             gameState = 3;
    else
            gameState = 1;


    switch (gameState){
        case 1: cout <<"\nCongratulations. You beat the computer."; break;
        case 2: cout <<"\nSorry you lose"; break;
        case 3: cout <<"\nIt's a tie"; break;
    }
}
