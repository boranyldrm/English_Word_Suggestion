//
// Created by Boran Yildirim on 4.12.2016.
//

#include "AVLTree.h"

AVLTree::AVLTree() {
    Init(); // Initialize pointers when constructor is called
}

void AVLTree::Init() {
    Root = NIL = new Node;
    NIL->h = 0;
    NIL->left = NIL->right = NULL;
}

AVLTree::~AVLTree() {
    deallocMemory(Root);
}

void AVLTree::deallocMemory(Node *N) {
    if (N == NIL) return;
    deallocMemory(N->left);
    deallocMemory(N->right);
    delete N;
    N = NIL;
}

bool AVLTree::isEmpty() {
    return Root->value.compare("") == 0;
}

bool AVLTree::Search(string val) {
    return Search(Root, val);
}

bool AVLTree::Search(Node *N, string val) {
    if (N == NIL)
        return false;

    if (N->value == val)
        return true;

    if (val < N->value)
        return Search(N->left, val);
    else
        return Search(N->right, val);
}

void AVLTree::Insert(string val) {
    Root = Insert(Root, val);
}

Node *AVLTree::Insert(Node *N, string val) {
    if (N == NIL) {
        N = new Node;
        N->value = val;
        N->left = N->right = NIL;
        N->h = 1;

        return N;
    }

    if (val <= N->value)
        N->left = Insert(N->left, val);
    else
        N->right = Insert(N->right, val);

    return Balance(N);
}

int AVLTree::Max(int a, int b) {
    return a>b ? a : b;
}

void AVLTree::GetHeight(Node *N) {
    N->h = 1 + Max(N->left->h, N->right->h);
}

Node *AVLTree::RotateLeft(Node *N) {
    Node *t = N->left;
    N->left = t->right;
    t->right = N;
    GetHeight(N);
    GetHeight(t);

    return t;
}

Node *AVLTree::RotateRight(Node *N) {
    Node *t = N->right;
    N->right = t->left;
    t->left = N;
    GetHeight(N);
    GetHeight(t);

    return t;
}

Node *AVLTree::Balance(Node *N) {
    GetHeight(N);

    if (N->left->h > N->right->h + 1) {
        if (N->left->right->h > N->left->left->h)
            N->left = RotateRight(N->left);
        N = RotateLeft(N);
    }
    else if (N->right->h > N->left->h + 1) {
        if (N->right->left->h > N->right->right->h)
            N->right = RotateLeft(N->right);
        N = RotateRight(N);
    }

    return N;
}

void AVLTree::PrintInOrderTraversal() {
    PrintInOrderTraversal(Root);
}

void AVLTree::PrintInOrderTraversal(Node *N) {
    if (N != NIL) {
        PrintInOrderTraversal(N->left);
        cout << N->value << " ";
        PrintInOrderTraversal(N->right);
    }
}

void AVLTree::PrintPreOrderTraversal() {
    PrintPreOrderTraversal(Root);
}

void AVLTree::PrintPreOrderTraversal(Node *N) {
    if (N != NIL) {
        cout << N->value << " ";
        PrintPreOrderTraversal(N->left);
        PrintPreOrderTraversal(N->right);
    }
}

void AVLTree::PrintPostOrderTraversal() {
    PrintPostOrderTraversal(Root);
}

void AVLTree::PrintPostOrderTraversal(Node *N) {
    if (N == NIL) {
        PrintPostOrderTraversal(N->left);
        PrintPostOrderTraversal(N->right);
        cout << N->value << " ";
    }
}

string AVLTree::Max() {
    Node *N = Root;
    while (N->right != NIL) N = N->right;
    return N->value;
}

string AVLTree::Min() {
    Node *N = Root;
    while (N->left != NIL) N = N->left;
    return N->value;
}