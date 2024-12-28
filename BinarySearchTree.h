/**
 * @file BinarySearchTree.h
 * @description İkili arama ağacı yapısını tanımlar
 * @course Veri Yapıları
 * @assignment Ödev 2
 * @date 25/12/2024
 * @author DURSUN GÜVEN B211210096
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include "Node.h"

class BinarySearchTree {
private:
    Node* root; // Ağacın kök düğümü

    void insert(Node*& current, char data);
    void destroyTree(Node* current);
    void drawTree(Node* node, int depth, int space) const;
    void displayTree(Node* current, int depth = 0) const;
    int getTotalASCII(Node* node) const;

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(char data);
    void display() const;
    void draw() const;
    int getTotalASCII() const;
    void mirror();
};

#endif
