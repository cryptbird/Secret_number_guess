#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    srand(time(0));

    char playAgain;
    
    do {
        // initialising range at the start of each game
        int minNumber = 1; 
        int maxNumber = 100;
        
        int attempts = 0;
        int guess;
        
        cout << "Welcome to the Number Guessing Game!" << endl;
        // taking input of range from user
        cout<<"Enter the range in which you wish to guess: (low, high)"<<endl;
        cin>>minNumber>>maxNumber;
        // Invalid input
        while(minNumber>=maxNumber-1){
            cout<<"Invalid input, try again!"<<endl;
            cout<<"Enter the range in which you wish to guess: (low, high)"<<endl;
            cin>>minNumber>>maxNumber;
        }
        // number to be guessed
        int secretNumber = rand() % (maxNumber - minNumber + 1) + minNumber;
        
        cout << "I'm thinking of a number between " << minNumber << " and " << maxNumber << "." << endl;
        
        while (true) {
            cout << "Enter your guess: ";
            if (!(cin >> guess)) {
                cout << "Invalid input. Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            
            attempts++;
            
            if (guess < secretNumber) {
                cout << "Too low! Try again." << endl;
            } else if (guess > secretNumber) {
                cout << "Too high! Try again." << endl;
            } else {
                cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
                break;
            }
        }
        
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');
    
    cout << "Thanks for playing! Goodbye." << endl;
    
    return 0;
}
