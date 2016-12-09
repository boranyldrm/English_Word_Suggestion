//
// Created by Boran Yildirim on 2.12.2016.
//

#ifndef ASSIGNMENT_4_SUGGESTWORDS_H
#define ASSIGNMENT_4_SUGGESTWORDS_H


#include <fstream>
#include <string>
#include "AVLTree.h"

using namespace std;

class SuggestWords {

public:
    SuggestWords(string file);

    ~SuggestWords();

    void printTree();

    void addWords(string file);

    void findWord(const string &word);
private:
    AVLTree wordTree;

    AVLTree *suggestTree;

    void makeSuggestions (AVLNode *node, const string &word, const int &length);
};

#endif
