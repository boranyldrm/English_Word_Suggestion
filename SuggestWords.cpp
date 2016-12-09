//
// Created by Boran Yildirim on 2.12.2016.
//

#include "SuggestWords.h"


SuggestWords::SuggestWords(string file) {
    addWords(file);
    suggestTree = new AVLTree();
}

SuggestWords::~SuggestWords() {
    delete suggestTree;
}

void SuggestWords::addWords(string file) {
    string line;
    ifstream myfile (file.c_str());
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            wordTree.insert(line);
        }
        myfile.close();
    }

    else
        cout << "Unable to open file";
}

void SuggestWords::printTree() {
    wordTree.printInOrderTraversal();
}

void SuggestWords::findWord(const string &word) {
    if (wordTree.search(word) )
        cout << "Found! The word is in vocabulary." << endl;
    else {
        cout << "NOT FOUND!!" << endl;
        int length = (int) word.length();

        if (length >= 5)
            makeSuggestions(wordTree.root ,word, length / 2 + 1);
        else
            makeSuggestions(wordTree.root ,word, length);

        if ( !suggestTree->isEmpty() ) {
            cout << "Some suggestions: ";
            suggestTree->printInOrderTraversal();
            cout << endl;
        }
        else
            cout << "There is no word to suggest." << endl;

        suggestTree->deallocMemory(suggestTree->root);
        suggestTree = new AVLTree;
    }
}

void SuggestWords::makeSuggestions(AVLNode *node, const string &word, const int &length) {
    if (node != wordTree.NIL && word.at(0) != 0) {
        if (word.at(0) < node->value.at(0)) {
            makeSuggestions(node->left, word, length);
        }
        if (word.at(0) > node->value.at(0)) {
            makeSuggestions(node->right, word, length);
        }

        if (word.at(0) == node->value.at(0)) {
            bool flag = false;
            for (int i = 1; i < length && !flag; ++i) {
                if (word.at(i) != node->value.at(i))
                    flag = true;
            }
            if (!flag)
                suggestTree->insert(node->value);

            makeSuggestions(node->left, word, length);
            makeSuggestions(node->right, word, length);
        }
    }
}
