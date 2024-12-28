/**
 * @file LinkedList.h
 * @description Tek yönlü bağlı liste yapısını tanımlar ve gerekli işlemleri içerir.
 * @course Veri Yapıları
 * @assignment Ödev 2
 * @date 25/12/2024
 * @author DURSUN GÜVEN B211210096
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "BinarySearchTree.h"

class LinkedListNode {
public:
    BinarySearchTree* tree; // Her düğüm bir ikili arama ağacını işaret eder
    LinkedListNode* next;   // Sonraki düğüme işaretçi

    LinkedListNode(BinarySearchTree* tree);
    ~LinkedListNode();
};

class LinkedList {
private:
    LinkedListNode* head;       // Listenin başı
    LinkedListNode* current;    // Seçili düğüm

public:
    LinkedList();
    ~LinkedList();

    void addTree(BinarySearchTree* tree); // Yeni bir ağacı listeye ekler
    void nextTree();                     // Sonraki düğüme geçer
    void previousTree();                 // Önceki düğüme geçer
    void deleteCurrentTree();            // Seçili düğümü siler
    void displayList() const;            // Listeyi ve seçili ağacı görselleştirir
    void mirrorCurrentTree();            // Seçili ağacı aynalar
};

#endif
