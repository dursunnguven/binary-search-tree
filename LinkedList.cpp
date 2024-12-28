/**
 * @file LinkedList.cpp
 * @description Tek yönlü bağlı liste yapısının kaynak kodlarını tanımlar ve gerekli işlemleri içerir.
 * @course Veri Yapıları
 * @assignment Ödev 2
 * @date 25/12/2024
 * @author DURSUN GÜVEN B211210096
 */

#include "../include/LinkedList.h"
#include <iostream>
#include <iomanip>

LinkedListNode::LinkedListNode(BinarySearchTree* tree) {
    this->tree = tree;
    this->next = nullptr;
}

LinkedListNode::~LinkedListNode() {
    delete tree;
}

LinkedList::LinkedList() {
    head = nullptr;
    current = nullptr;
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        LinkedListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::addTree(BinarySearchTree* tree) {
    LinkedListNode* newNode = new LinkedListNode(tree);
    if (head == nullptr) {
        head = newNode;
        current = head;
    } else {
        LinkedListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LinkedList::nextTree() {
    if (current != nullptr && current->next != nullptr) {
        current = current->next;
    } else {
        std::cout << "Son dugumde bulunuyorsunuz." << std::endl;
    }
}

void LinkedList::previousTree() {
    if (current != head) {
        LinkedListNode* temp = head;
        while (temp->next != current) {
            temp = temp->next;
        }
        current = temp;
    } else {
        std::cout << "Ilk dugumde bulunuyorsunuz." << std::endl;
    }
}

void LinkedList::deleteCurrentTree() {
    if (current == nullptr) {
        std::cout << "Silinecek dugum yok." << std::endl;
        return;
    }

    if (current == head) {
        head = head->next;
        delete current;
        current = head;
    } else {
        LinkedListNode* temp = head;
        while (temp->next != current) {
            temp = temp->next;
        }
        temp->next = current->next;
        delete current;
        current = temp->next;
    }
}

void LinkedList::displayList() const {
    LinkedListNode* temp = head;
    int count = 0; // İlk 10 düğümü göstermek için sayaç

    std::cout << "Adres         ASCII Toplamı" << std::endl;

    while (temp != nullptr && count < 10) { // Sadece ilk 10 düğümü göster
        std::cout << std::setw(10) << temp << " ";
        std::cout << std::setw(6) << temp->tree->getTotalASCII();

        if (temp->next != nullptr) {
            std::cout << " -> ";
        }

        temp = temp->next;
        count++;
    }

    std::cout << std::endl;

    if (current != nullptr) {
        std::cout << "\nSecili agacin yapisi:" << std::endl;
        current->tree->draw();
    } else {
        std::cout << "Secili bir agac yok!" << std::endl;
    }
}

void LinkedList::mirrorCurrentTree() {
    if (current != nullptr) {
        current->tree->mirror();
    } else {
        std::cout << "Aynalanacak bir agac yok." << std::endl;
    }
}
