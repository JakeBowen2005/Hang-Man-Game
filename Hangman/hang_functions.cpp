//
//  hang_functions.cpp
//  Hangman
//
//  Created by Jake Bowen on 10/29/24.
//

#include "hang_functions.hpp"

using namespace std;


// define functions

void greet() {
    cout << " ====================" << endl;
    cout << " Welcome to the hangman game" << endl;
    cout << " Save your best friend from death" << endl;
    cout << " ====================" << endl;
}

void display_misses(int misses) {
    if (misses == 0) {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========= \n";
        
    } else if (misses == 1) {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========= \n";
        
    } else if (misses == 2) {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<"  |   | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========= \n";

        
    } else if (misses == 3) {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<" /|   | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========= \n";

        
    } else if (misses == 4) {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<" /|\\  | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========= \n";
        
        
    } else if (misses == 5) {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<" /|\\  | \n";
        cout<<" /    | \n";
        cout<<"      | \n";
        cout<<" ========= \n";
        
    } else if (misses == 6) {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<" /|\\  | \n";
        cout<<" / \\  | \n";
        cout<<"      | \n";
        cout<<" ========= \n";

    }
}

void display_status(vector<char> incorrect, string answer) {
    cout << "Incorrect Guesses: " << endl;
    for (int i = 0; i < incorrect.size(); i++) {
        cout << incorrect[i] << " ";
    }
    cout << "\nCodeword:\n";
        for (int i = 0; i < answer.length(); i++) {
            cout << answer[i];
        }
}

void end_game(string answer, string codeword) {
    if (answer == codeword) {
        cout << "Winner!! You saved your best friend!" << endl;
        cout << "The code word was " << codeword << endl;
    } else {
        cout << "Oh NO!!\n Sorry you let your friend die!" << endl;
        cout << "The code word was " << codeword << endl;
    }
}

void clearScreen() {
    system("clear");

}

void PrintMessage(string msg, bool Printtop = true, bool PrintBottom = true) {
    if (Printtop) {
        cout << "+---------------------------------+" << endl;
        cout << "|";
    } else {
        cout << "|";
    }
    bool front = true;
    for (int i = static_cast<int>(msg.length()); i < 33; i++) {
        if (front) {
            msg = " " + msg;
        } else {
            msg = msg + " ";
        }
        front = !front;
    }
    cout << msg.c_str();
    
    if (PrintBottom) {
        cout << "|" << endl;
        cout << "+---------------------------------+" << endl;
    } else {
        cout << "|" << endl;
    }
}

void Draw(int guess_count, char input) {
    if (input == '1') {
        if (guess_count >= 1) {
            PrintMessage("|", false, false);
        } else {
            PrintMessage("", false, false);
        }
        if (guess_count >= 2) {
            PrintMessage("|", false, false);
        } else {
            PrintMessage("", false, false);
        }
        if (guess_count >= 3) {
            PrintMessage("0", false, false);
        } else {
            PrintMessage("", false, false);
        }
        if (guess_count == 4) {
            PrintMessage("/  ", false, false);
        }
        if (guess_count == 5) {
            PrintMessage("/| ", false, false);
        }
        if (guess_count >= 6) {
            PrintMessage("/|\\", false, false);
        } else {
            PrintMessage("", false, false);
        }
        if (guess_count >= 7) {
            PrintMessage("|", false, false);
        } else {
            PrintMessage("", false, false);
            }
        if (guess_count == 8) {
            PrintMessage("/   ", false, false);
        }
        if (guess_count >= 9) {
            PrintMessage("/ \\", false, false);
        }
        
    } else if (input == '2') {
        if (guess_count >= 1) {
            PrintMessage("|", false, false);
        } else {
            PrintMessage("", false, false);
        }
        if (guess_count >= 2) {
            PrintMessage("0", false, false);
        } else {
            PrintMessage("", false, false);
        }
        if (guess_count == 3) {
            PrintMessage("/  ", false, false);
        }
        if (guess_count == 4) {
            PrintMessage("/| ", false, false);
        }
        if (guess_count >= 5) {
            PrintMessage("/|\\", false, false);
        } else {
            PrintMessage("", false, false);
        }
        if (guess_count >= 6) {
            PrintMessage("|", false, false);
        } else {
            PrintMessage("", false, false);
            }
        if (guess_count >= 7) {
            PrintMessage("/ \\", false, false);
        }
    
    }
    else if (input == '3') {
        if (guess_count >= 1) {
            PrintMessage("|", false, false);
        } else {
            PrintMessage("", false, false);
        }
        if (guess_count >= 2) {
            PrintMessage("0", false, false);
        } else {
            PrintMessage("", false, false);
        }
        if (guess_count == 3) {
            PrintMessage("/|\\ ", false, false);
        }
        if (guess_count >= 4) {
            PrintMessage("|", false, false);
        } else {
            PrintMessage("", false, false);
        }
        if (guess_count >= 5) {
            PrintMessage("/ \\", false, false);
        }
    }
}

void PrintLetters(string input, char from, char to) {
    string s;
    for (char i = from; i <= to; i++) {
        if (input.find(i) == string::npos) {
            s += i;
            s += " ";
        } else {
            s += " ";
        }
    }
    PrintMessage(s, false, false);
}

void PrintAvailable(string taken) {
    PrintMessage("Available Letters");
    PrintLetters(taken, 'a', 'm');
    PrintLetters(taken, 'n', 'z');
}


bool PrintWordCheckWin(string word, string guessed) {
    bool win = true;
    string s;
    for (int i = 0; i < word.length(); i++) {
        if (guessed.find(word[i]) == string::npos) {
            win = false;
            s += "_ ";
        } else {
            s += word[i];
            s += " ";
        }
    }
    PrintMessage(s, false);
    return win;
}

int TriesLeft(string word, string guessed) {
    int error = 0;
    for (int i = 0; i < guessed.length(); i++) {
        if (word.find(guessed[i]) == string::npos) {
            error++;
        }
    }
    return error;
}

