//
//  hang_functions.hpp
//  Hangman
//
//  Created by Jake Bowen on 10/29/24.
//

#ifndef hang_functions_hpp
#define hang_functions_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

void greet();
void display_misses(int misses);
void display_status(vector<char> incorrect, string answer);
void end_game(string answer, string codeword);
void clearScreen();
void PrintMessage(string msg, bool Printtop, bool PrintBottom);
void Draw(int guess_count, char input);
void PrintLetters(string input, char from, char to);
void PrintAvailable(string taken);
bool PrintWordCheckWin(string word, string guessed);
int TriesLeft(string word, string guessed);

#endif /* hang_functions_hpp */
