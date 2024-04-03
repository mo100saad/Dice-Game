# Dangerous Dice-Game
DD Game is an engaging and interactive betting game designed for a single player. Upon starting the game, the player is welcomed and prompted to enter their name. The game begins with an initial pool of 500 points for the player to bet with. In each round, the player places a bet and then rolls two dice. The outcome of the dice roll determines the points won or lost:

Rolling double fours adds 200 points plus the bet amount to the player's total.
Rolling a sum of 7 or 11 adds 100 points plus the bet amount.
Any other outcome results in a loss of the bet amount plus an additional 25 points.
The game checks the player's total points after each round, offering a chance to continue or end the game. The objective is to accumulate 1,000 points to win. However, if the player's total points fall to zero, they lose. Players have the option to restart the game after winning or exhausting their points, ensuring continuous entertainment. The game is designed with an object-oriented programming approach, featuring robust input validation, random dice rolls for fairness, and an intuitive user interface for a seamless gaming experience

## Run Locally

- Ensure a C++ compiler (GCC, Clang) is installed on your system.
- Download Dice-Game.cpp from the GitHub repository.
- Open terminal/command prompt, navigate to the file's directory.
- Compile the game: g++ -std=c++11 Dice-Game.cpp -o DiceGame
- Run the executable:
  + Linux/macOS: ./DiceGame
  + Windows: DiceGame.exe
- Follow on-screen instructions to play the game.
