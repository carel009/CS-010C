#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include <fstream>
#include "Node.h"

class AVLTree
{
    public:
       void insert(const string &);
       int balanceFactor(Node*);
       void printBalanceFactors();
       void visualizeTree(const string &);
       AVLTree();
    
    private:
        Node* rotate(Node*, string, int);
        Node* rotateLeft(Node*);
        Node* rotateRight(Node*);
        void printBalanceFactors(Node*);
        void visualizeTree(ofstream &, Node*);
        Node* insert(Node*, string);
        int height(Node*);
        int max(int, int);
        Node* root;
};
#endif