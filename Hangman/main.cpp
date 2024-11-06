//
//  main.cpp
//  Hangman
//
//  Created by Jake Bowen on 10/31/24.
//

#include "hang_functions.hpp"//;

// g++ -o my_program main.cpp hang_functions.cpp

using namespace std;



int main() {
    system("clear");
    std::vector<std::string> words;
    std::ifstream file("/usr/share/dict/words");

    if (!file) {
        std::cerr << "Unable to open dictionary file!" << std::endl;
        return 1;
    }

    std::string word;
    while (file >> word) {
        // Only add words longer than 6 characters
        if (word.length() >= 6 && word.length() < 12) {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            words.push_back(word);
        }
    }
    file.close();

    if (words.empty()) {
        std::cerr << "No words found longer than 6 characters!" << std::endl;
        return 1;
    }

    std::random_device rd;  // Seed source for randomness (usually based on hardware)
    std::mt19937 gen(rd()); // Mersenne Twister RNG engine, seeded with random device
    std::uniform_int_distribution<> dist(0, static_cast<int>(words.size() - 1));
    int randomIndex = dist(gen);
    std::string codeWord = words[randomIndex];

    //std::string answer(codeWord.length(), '_');
    int maxTries = 0;
    char input;

       while (true) {
           cout << "\nChoose difficulty level:\n1. Easy (10 tries)\n2. Medium (8 tries)\n3. Hard (6 tries)\n";
           cout << "Enter 1, 2, 3, or press 'q' to quit: ";
           cin >> input;

           if (input == 'q' || input == 'Q') {
               PrintMessage("Quitting the game. Goodbye!", true, true);
               return 0;
           } else if (input == '1' || input == '2' || input == '3') {
               int difficulty = input - '0'; // Convert char '1', '2', '3' to integer 1, 2, 3

               switch (difficulty) {
                   case 1: maxTries = 10; break;
                   case 2: maxTries = 8; break;
                   case 3: maxTries = 6; break;
               }
               break; // Valid input, exit the loop
           } else {
               system("clear");
               cout << "Invalid input! Please enter 1, 2, 3, or 'q' to quit." << endl;
               // Clear the error flag on cin and ignore the rest of the input line
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
           }
       }
    system("clear");
    
    string guesses;
    int tries = 0;
    bool win  = false;

    //clearScreen();
   // bool PrintTop = true;
    //bool PrintBottom = true;
    do {
        clearScreen();
        PrintMessage("HANG MAN", true, true);
        Draw(tries, input);
        PrintAvailable(guesses);
        PrintMessage("Guess the Word", true, true);
        win = PrintWordCheckWin(codeWord, guesses);
        
        if (win)
            break;
        
        char c;
        cout << "Enter guess here: ";
        cin >> c;
        char new_c = tolower(c);
        if (guesses.find(new_c) == string::npos) {
            guesses += new_c;
        }
        tries = TriesLeft(codeWord, guesses);
    } while (tries < maxTries);
    
    if (win) {
        cout << endl;
        PrintMessage("Winner!", true, true);
    }
    cout << endl;
    if (win == false) {
        PrintMessage("Loser", true, true);
        cout << "Word was " << codeWord << endl;
        
    }
    
    

    return 0;
}
