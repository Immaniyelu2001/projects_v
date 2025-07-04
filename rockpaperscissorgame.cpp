#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Game {
private:
    string playerChoice;
    string computerChoice;
    string choices[3] = {"rock", "paper", "scissors"};

public:
    Game() {
        srand(time(0)); // Seed the random number generator
    }

    void getPlayerChoice() {
        cout << "\nEnter your choice (rock/paper/scissors): ";
        cin >> playerChoice;

        // Simple input validation
        while (playerChoice != "rock" && playerChoice != "paper" && playerChoice != "scissors") {
            cout << "Invalid input. Try again: ";
            cin >> playerChoice;
        }
    }

    void generateComputerChoice() {
        computerChoice = choices[rand() % 3];
        cout << "Computer chose: " << computerChoice << endl;
    }

    string determineWinner() {
        if (playerChoice == computerChoice)
            return "It's a draw!";
        else if ((playerChoice == "rock" && computerChoice == "scissors") ||
                 (playerChoice == "paper" && computerChoice == "rock") ||
                 (playerChoice == "scissors" && computerChoice == "paper"))
            return "You win!";
        else
            return "Computer wins!";
    }

    void play() {
        getPlayerChoice();
        generateComputerChoice();
        cout << determineWinner() << "\n";
    }
};

int main() {
    Game game;
    char again;

    do {
        game.play();
        cout << "\nDo you want to play again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
