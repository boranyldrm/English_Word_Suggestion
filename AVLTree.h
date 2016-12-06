//
// Created by Boran Yildirim on 4.12.2016.
//

#ifndef ASSIGNMENT_4_AVLTREE_H
#define ASSIGNMENT_4_AVLTREE_H

#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string value;
    int h; // The depth of the node in the tree
    Node *left, *right;
};

class AVLTree {

private:
    Node *Root, *NIL; // The Root is private to restrict direct access to the pointers

public:
    AVLTree();

    // When the destructor is called, it invokes the method DeallocMemory which recursively,
    // in a bottom-up style, deallocs the dynamic allocated memory
    ~AVLTree();

    bool isEmpty();

    // This public method Search calls for the private method Search, in order not to give user access to the Root
    bool Search(string val);

    // The same pattern of restricting access is here
    void Insert(string val);

    // The Max value form AVL is the rightmost node in the tree
    string Max();

    // The Min value from AVL is in the leftmost node of the tree
    string Min();

    // In-Order traversal, prints the elements in ascending order
    void PrintInOrderTraversal();

    // Pre-Order Traversal
    void PrintPreOrderTraversal();

    // Post-Order Traversal
    void PrintPostOrderTraversal();

private:
    // Initialization of the Tree
    // Create Root and NIL node, in order not to acces unallocated memory
    void Init();

    // Search the value T in subtree with the root in node N,
    bool Search(Node *N, string val);

    // After insertion, call balance method, to keep the tree balanced
    Node * Insert(Node *N, string val);

    int Max(int a, int b);

    // Updadets the depth of the node N in the tree
    void GetHeight(Node *N);

    // The Rotate left operation, for balancing the tree
    Node * RotateLeft(Node *N);

    Node * RotateRight(Node *N);

    // Balance the nodes in the way that no two subtrees of a node have their maximum depth with a difference bigger than 1
    Node* Balance(Node *N);

    void PrintInOrderTraversal(Node *N);

    void PrintPreOrderTraversal(Node *N);

    void PrintPostOrderTraversal(Node *N);

    // Recursively destroys the tree
    void deallocMemory(Node *N);

    friend class SuggestWords;
};

#endif //ASSIGNMENT_4_AVLTREE_H
