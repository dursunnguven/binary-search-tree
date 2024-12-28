/**
 * @file Node.h
 * @description İkili arama ağacı düğümünü tanımlar
 * @course Veri Yapıları
 * @assignment Ödev 2
 * @date 25/12/2024
 * @author DURSUN GÜVEN B211210096
 */

#ifndef NODE_H
#define NODE_H

class Node {
public:
    char data;      // Düğümdeki veri
    Node* left;     // Sol alt düğüm
    Node* right;    // Sağ alt düğüm

    Node(char data);
};

#endif
