#include <iostream>
#include <random>

int getRandom() {
  std::random_device rd;
  std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
  std::mt19937 mt{ss};

  std::uniform_int_distribution die100{1, 100};
  return die100(mt);
}

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getGuess() {
  while (true) {

    std::cout << "Enter guess\n";
    int guess{};
    std::cin >> guess;

    if (std::cin.fail()) {
      std::cout << "Invalid\n";
      std::cin.clear();
      ignoreLine();
      continue;
    }

    ignoreLine();
    return guess;
  }
}

bool playGame(int randomNum, int guesses) {

  for (int i{0}; i < guesses; ++i) {
    int guess{getGuess()};

    if (guess < randomNum) {
      std::cout << "Your guess is too low\n";
    } else if (guess > randomNum) {
      std::cout << "Your guess is too high\n";
    } else {
      std::cout << "Ayyy you win!\n";
      return true;
    }
  }
  return false;
}

bool playAgain() {
  while (true) {
    char ch{};
    std::cout << "Would you like to play again? (y/n)? \n";
    std::cin >> ch;
    switch (ch) {
    case 'y':
      return true;
    case 'n':
      return false;
    }
  }
}

int main() {
  constexpr int guesses{7};

  do {
    int randomNum{getRandom()};

    std::cout << "lets play a game, guess a number between 1 and 100, you have "
                 "7 guesses\n";

    bool won{playGame(randomNum, guesses)};
    if (won) {
      std::cout << "You win congrats\n";
    } else {
      std::cout << "You lose lol, here's the correct answer : " << randomNum
                << '\n';
    }

  } while (playAgain());
}