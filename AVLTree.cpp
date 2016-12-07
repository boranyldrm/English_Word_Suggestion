//
// Created by Boran Yildirim on 4.12.2016.
//

#include "AVLTree.h"

AVLTree::AVLTree() {
    root = NIL = new AVLNode;
    NIL->h = 0;
    NIL->left = NIL->right = NULL;
}

AVLTree::~AVLTree() {
    deallocMemory(root);
}

void AVLTree::deallocMemory(AVLNode *node) {
    if (node == NIL) return;
    deallocMemory(node->left);
    deallocMemory(node->right);
    delete node;
    node = NIL;
}

bool AVLTree::isEmpty() {
    return root->value.compare("") == 0;
}

bool AVLTree::search(string val) {
    return search(root, val);
}

bool AVLTree::search(AVLNode *node, string val) {
    if (node == NIL)
        return false;

    if (node->value == val)
        return true;

    if (val < node->value)
        return search(node->left, val);
    else
        return search(node->right, val);
}

void AVLTree::insert(string val) {
    root = insert(root, val);
}

AVLNode *AVLTree::insert(AVLNode *N, string val) {
    if (N == NIL) {
        N = new AVLNode;
        N->value = val;
        N->left = N->right = NIL;
        N->h = 1;

        return N;
    }

    if (val <= N->value)
        N->left = insert(N->left, val);
    else
        N->right = insert(N->right, val);

    return balance(N);
}

int AVLTree::max(int a, int b) {
    return a>b ? a : b;
}

void AVLTree::getHeight(AVLNode *N) {
    N->h = 1 + max(N->left->h, N->right->h);
}

AVLNode *AVLTree::rotateLeft(AVLNode *N) {
    AVLNode *t = N->left;
    N->left = t->right;
    t->right = N;
    getHeight(N);
    getHeight(t);

    return t;
}

AVLNode *AVLTree::rotateRight(AVLNode *N) {
    AVLNode *t = N->right;
    N->right = t->left;
    t->left = N;
    getHeight(N);
    getHeight(t);

    return t;
}

AVLNode *AVLTree::balance(AVLNode *N) {
    getHeight(N);

    if (N->left->h > N->right->h + 1) {
        if (N->left->right->h > N->left->left->h)
            N->left = rotateRight(N->left);
        N = rotateLeft(N);
    }
    else if (N->right->h > N->left->h + 1) {
        if (N->right->left->h > N->right->right->h)
            N->right = rotateLeft(N->right);
        N = rotateRight(N);
    }

    return N;
}

void AVLTree::printInOrderTraversal() {
    printInOrderTraversal(root);
}

void AVLTree::printInOrderTraversal(AVLNode *N) {
    if (N != NIL) {
        printInOrderTraversal(N->left);
        cout << N->value << " ";
        printInOrderTraversal(N->right);
    }
}

void AVLTree::printPreOrderTraversal() {
    printPreOrderTraversal(root);
}

void AVLTree::printPreOrderTraversal(AVLNode *N) {
    if (N != NIL) {
        cout << N->value << " ";
        printPreOrderTraversal(N->left);
        printPreOrderTraversal(N->right);
    }
}

void AVLTree::printPostOrderTraversal() {
    printPostOrderTraversal(root);
}

void AVLTree::printPostOrderTraversal(AVLNode *N) {
    if (N == NIL) {
        printPostOrderTraversal(N->left);
        printPostOrderTraversal(N->right);
        cout << N->value << " ";
    }
}