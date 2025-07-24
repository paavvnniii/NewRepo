/*
    Rock Paper Scissors Game in C++
    --------------------------------
    Developed by: Paavni Bharti
    Date: July 2025

    This is a simple CLI-based Rock-Paper-Scissors game where the user
    plays against the computer. The computer randomly chooses rock, paper,
    or scissors, and the user inputs their choice.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to get the computer's random choice
string getComputerChoice() {
    int randomNum = rand() % 3; // Generates 0, 1, or 2
    switch (randomNum) {
    case 0: return "rock";
    case 1: return "paper";
    case 2: return "scissors";
    }
    return "rock"; // Default fallback
}

// Function to determine the result
string getResult(string user, string computer) {
    if (user == computer) return "It's a draw!";
    if ((user == "rock" && computer == "scissors") ||
        (user == "paper" && computer == "rock") ||
        (user == "scissors" && computer == "paper"))
        return "You win!";
    else
        return "You lose!";
}

int main() {
    string userChoice;
    char playAgain;

    cout << "=== Rock Paper Scissors Game ===" << endl;

    do {
        // Get user input
        cout << "\nEnter your choice (rock, paper, scissors): ";
        cin >> userChoice;

        // Convert input to lowercase
        for (char& c : userChoice) c = tolower(c);

        // Validate input
        if (userChoice != "rock" && userChoice != "paper" && userChoice != "scissors") {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        // Seed and generate computer's choice
        srand(time(0));
        string computerChoice = getComputerChoice();

        // Show result
        cout << "Computer chose: " << computerChoice << endl;
        cout << getResult(userChoice, computerChoice) << endl;

        // Ask if user wants to play again
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (tolower(playAgain) == 'y');

    // Thank you message with credit
    cout << "\nThanks for playing!" << endl;
    cout << "Game developed by Paavni Bharti " << endl;

    return 0;
}
