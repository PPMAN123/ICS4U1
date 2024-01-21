// Programmed by Christopher Mong
// Programmed on Jan 12, 2023
// Programmed for ICS4U1-02

#include "game.h"
#include "word.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;

void welcomeMenu() {
  cout << "WELCOME TO WORDLE!" << endl;
  cout << "RULES: " << endl;
  cout << "1. Enter a 5 letter word" << endl;
  cout << "2. Green box signals correct letter and correct position" << endl;
  cout << "3. Yellow box signals correct letter but wrong position" << endl;
  cout << "4. Grey box signals incorrect letter" << endl;
  cout << "5. You have 5 tries to guess the word, good luck!" << endl;
  cout << endl;
}

string getRandomWord() {
  string word;
  int line = rand() % 808;
  word = validWord[line];
  return word;
}

inline bool correct(string input, string word) {
  // checks if input is equal to target word
  return input == word;
}

int main() {
  // stores the user's guesses
  string guesses[MAX_GUESSES];
  // array to hold the state of the letters match (none, partial, full)
  int matches[MAX_GUESSES][WORD_LENGTH];
  string word = "     ";
  bool won = false;
  // number of guesses used, number of lines in file, random number
  int numGuess = 0;
  // line in file
  string line;
  welcomeMenu();

  Board board(getRandomWord());
  line = board.getWord();
  board.displayLetters();

  PlayerWord player(word);

  while (numGuess < MAX_GUESSES) {
      while ((word != "q" || word != "Q") && !player.isValidWord(word, 0)) {
      cout << "\n\033[94mEnter your guess (q or Q to quit): ";
      cin >> word;
      player.convertToLowercase(word);
      if (word == "Q")
        break;
      else if (!player.isValidWord(word, 0))
        cout << "\n\033[31mINVALID INPUT." << endl;
    }

    if (word == "q" || word == "Q") {
      cout << "\n\033[31mYOU QUIT THE GAME. THE WORD WAS " << line << "."
           << endl;
      return 0;
    }
    // change string to all lower or upper to avoid error
    guesses[numGuess] = word;

    // check if the guess matches and display to console
    player.checkWord(word, line, matches, numGuess);
    board.drawBoard(guesses, matches, numGuess);
    // if the users guessed correctly, end the game
    if (correct(word, line)) {
      cout << "\n\033[0mYOU WIN! THE WORD WAS " << line << "." << endl;
      won = true;

      break;
    }
    numGuess++;
    word = "";
  }

  // if the game is over and user hasn't won
  if (!won) {
    cout << "\n\033[31mGAME OVER! THE WORD WAS " << line << "\033[31m." << endl;
  }
}
