//
// Created by Boran Yildirim on 4.12.2016.
//

#ifndef ASSIGNMENT_4_AVLTREE_H
#define ASSIGNMENT_4_AVLTREE_H

#pragma once
#include <iostream>
#include <string>
using namespace std;

struct AVLNode {
    string value;
    int h; // The depth of the node in the tree
    AVLNode *left, *right;
};

class AVLTree {

private:
    AVLNode *root, *NIL; // The root is private to restrict direct access to the pointers

public:
    AVLTree();

    // When the destructor is called, it invokes the method DeallocMemory which recursively,
    // in a bottom-up style, deallocs the dynamic allocated memory
    ~AVLTree();

    // if the AVLTree empty return true, else false
    bool isEmpty();

    // This public method search calls for the private method search, in order not to give user access to the root
    bool search(string val);

    // The same pattern of restricting access is here
    void insert(string val);

    // In-Order traversal, prints the elements in ascending order
    void printInOrderTraversal();

    // Pre-Order Traversal
    void printPreOrderTraversal();

    // Post-Order Traversal
    void printPostOrderTraversal();

private:

    // search the value T in subtree with the root in node N,
    bool search(AVLNode *node, string val);

    // After insertion, call balance method, to keep the tree balanced
    AVLNode * insert(AVLNode *node, string val);

    int max(int a, int b);

    // the depth of the node N in the tree
    void getHeight(AVLNode *node);

    // The Rotate left operation, for balancing the tree
    AVLNode * rotateLeft(AVLNode *node);

    AVLNode * rotateRight(AVLNode *node);

    // balance the nodes in the way that no two subtrees of a node have their maximum depth with a difference bigger than 1
    AVLNode* balance(AVLNode *node);

    void printInOrderTraversal(AVLNode *node);

    void printPreOrderTraversal(AVLNode *node);

    void printPostOrderTraversal(AVLNode *node);

    // Recursively destroys the tree
    void deallocMemory(AVLNode *node);

    friend class SuggestWords;
};

#endif //ASSIGNMENT_4_AVLTREE_H
