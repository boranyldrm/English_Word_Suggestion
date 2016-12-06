#include <iostream>
#include "SuggestWords.h"

using namespace std;

int main() {
    // for debug from CLion text path  /Users/boranyildirim/Desktop/CS202/Assignment_4/vocabulary.txt
    SuggestWords words("vocabulary.txt");

    cout << "Welcome to Dorthraki Vocabulary!!!" << endl;

    cout << "This vocabulary contains 378 words." << endl;

    string userInput;

    do {
        cout << "Enter a word: ";
        cin >> userInput;

        words.findWord(userInput);

        if (userInput == "quit")
            cout << "Good Bye !!" << endl;

    } while (userInput != "quit");
}
