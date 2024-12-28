/**
 * @file BinarySearchTree.cpp
 * @description İkili arama ağacının kaynak kodlarını tanımlar
 * @course Veri Yapıları
 * @assignment Ödev 2
 * @date 25/12/2024
 * @author DURSUN GÜVEN B211210096
 */

#include "../include/BinarySearchTree.h"
#include <iomanip> // setw için
#include <queue>   // queue için
#include <utility> // pair için

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
}

void BinarySearchTree::insert(Node*& current, char data) {
    if (current == nullptr) {
        current = new Node(data);
    } else if (data < current->data) {
        insert(current->left, data);
    } else if (data > current->data) {
        insert(current->right, data);
    }
}

void BinarySearchTree::insert(char data) {
    insert(root, data);
}

void BinarySearchTree::destroyTree(Node* current) {
    if (current != nullptr) {
        destroyTree(current->left);
        destroyTree(current->right);
        delete current;
    }
}

void BinarySearchTree::displayTree(Node* current, int depth) const {
    if (current != nullptr) {
        displayTree(current->right, depth + 1);
        for (int i = 0; i < depth; i++) {
            std::cout << "   ";
        }
        std::cout << current->data << std::endl;
        displayTree(current->left, depth + 1);
    }
}

void BinarySearchTree::display() const {
    displayTree(root);
}

void BinarySearchTree::drawTree(Node* node, int depth, int space) const {
    if (node == nullptr) {
        return;
    }

    space += 5;

    // Sağ alt düğümü çiz
    drawTree(node->right, depth + 1, space);

    // Bu düğüm için boşluk ekle ve düğüm verisini yazdır
    std::cout << std::endl;
    for (int i = 5; i < space; i++) {
        std::cout << " ";
    }
    std::cout << node->data << std::endl;

    // Sol alt düğümü çiz
    drawTree(node->left, depth + 1, space);
}

void BinarySearchTree::draw() const {
    drawTree(root, 0, 0);
}

int BinarySearchTree::getTotalASCII(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return node->data + getTotalASCII(node->left) + getTotalASCII(node->right);
}

int BinarySearchTree::getTotalASCII() const {
    return getTotalASCII(root);
}

void BinarySearchTree::mirror() {
}
