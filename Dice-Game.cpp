#include <iostream>
#include <limits>
#include <random>
#include <stdexcept>
using namespace std;

class DiceGame {
public:
    DiceGame() : pointsTotal(500), playerWon(false) {}

    void playGame() {
        string playerName = getPlayerName();
        do {
            placeBet();
            rollDice();
            calculatePoints();
            displayPoints();
            checkGameStatus();
        } while (playerWantsToContinue());
    }

private:
    int pointsTotal;
    int bet;
    int dice[2];
    bool playerWon;

    static string getPlayerName() {
        cout << "Welcome to the Dice Game! Please enter your name: ";
        string name;
        cin >> name;
        return name;
    }

    void placeBet() {
        cout << "You have " << pointsTotal << " points." << endl;
        cout << "Place your bet: ";
        while (!(cin >> bet) || bet <= 0 || bet > pointsTotal) {
            cout << "Invalid bet. Please enter a value between 1 and " << pointsTotal << ": ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    void rollDice() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, 6);
        dice[0] = distrib(gen);
        dice[1] = distrib(gen);
        cout << "Rolled: " << dice[0] << " and " << dice[1] << endl;
    }

    void calculatePoints() {
        int sum = dice[0] + dice[1];
        if (dice[0] == 4 && dice[1] == 4) {
            pointsTotal += bet + 200;
        } else if (sum == 7 || sum == 11) {
            pointsTotal += bet + 100;
        } else {
            pointsTotal -= (25 + bet);
        }
    }

    void displayPoints() const {
        if (pointsTotal > 0) {
            cout << "Current points: " << pointsTotal << endl;
        } else {
            cout << "You've run out of points!" << endl;
        }
    }

    void checkGameStatus() {
        if (pointsTotal >= 1000) {
            cout << "Congratulations! You've won the game with " << pointsTotal << " points!" << endl;
            playerWon = true;
        } else if (pointsTotal <= 0) {
            cout << "Sorry, you've lost all your points. Better luck next time!" << endl;
            playerWon = false;
        }
    }

    bool playerWantsToContinue() {
        if (playerWon || pointsTotal <= 0) {
            char choice;
            cout << "Would you like to play again? (Y/N): ";
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                pointsTotal = 500; // Reset points for a new game
                return true;
            }
            return false;
        }
        cout << "Continue playing? (Y/N): ";
        char choice;
        cin >> choice;
        return choice == 'Y' || choice == 'y';
    }
};

int main() {
    try {
        DiceGame game;
        game.playGame();
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    }
    cout << "Goodbye! Have a nice day!" << endl;
    return 0;
}