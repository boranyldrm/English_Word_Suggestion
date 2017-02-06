#include <iostream>
#include "SuggestWords.h"

using namespace std;

int main() {

    SuggestWords words("words");

    cout << "Welcome to English dictionary." << endl << endl;

    //cout << "This vocabulary contains 378 words." << endl;

    string userInput;

    do {
        cout << "Enter a word: ";
        cin >> userInput;

        words.findWord(userInput);

        if (userInput == "quit")
            cout << "Good Bye !!" << endl;

    } while (userInput != "quit");
}
