#include <iostream>
#include <stdint.h>
#include <vector>
#include "../Code.hpp"

int main() {
  int gamemode;
  std::vector<int> results = {0, 0};
  int length, range;
  std::vector<std::vector<int>> guesses;
  std::cout << "Welcome to Mastermind!\n \
                Select gamemode below:\n \
                [1] Testing\n \
                [2] Play\n \
                Enter gamemode number: ";
  std::cin >> gamemode;
  switch (gamemode) {
    case 1:
      // part a: Test guesses
      length = 5;
      range = 6;
      Code game(length, range); // {game} instance of code class
      guesses.push_back({5, 0, 3, 2, 6});
      guesses.push_back({2, 1, 2, 2, 2});
      guesses.push_back({1, 3, 3, 4, 5});
      for (int i = 0; i < guesses.size(); ++i) {  
        for (int j = 0; j < length; ++j) {
          std::cout << guesses[i][j] << " ";
        }
        if (!game.establishGuessCode(guesses[i])){
          break;
        }
        results[0] = game.checkCorrect(); // pass in object of Code guess?
        results[1] = game.checkIncorrect(); // same as above
        std::cout << results[0] << " " << results[1] << std::endl;
      }

      break;
    case 2:
      // part b: Play Game
      std::cout << "Hello";
      break;
    default: std::cout << "Please enter either 1 or 2\n";
  }
  return 1;
}
