/**
 * @file Node.cpp
 * @description İkili arama ağacı düğümünün kaynak kodlarını tanımlar
 * @course Veri Yapıları
 * @assignment Ödev 2
 * @date 25/12/2024
 * @author DURSUN GÜVEN B211210096
 */

#include "../include/Node.h"

Node::Node(char data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}
