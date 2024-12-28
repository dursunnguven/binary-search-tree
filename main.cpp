/**
 * @file main.cpp
 * @description Programın ana dosyası
 * @course Veri Yapıları
 * @assignment Ödev 2
 * @date 25/12/2024
 * @author DURSUN GÜVEN B211210096
 */

#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
#include "BinarySearchTree.h"

void loadTreesFromFile(const std::string& fileName, LinkedList& list) {
    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "Dosya acilamadi: " << fileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        BinarySearchTree* tree = new BinarySearchTree();
        for (char ch : line) {
            tree->insert(ch);
        }
        list.addTree(tree);
    }

    inputFile.close();
}

int main() {
    LinkedList list;
    loadTreesFromFile("agaclar.txt", list);

    char choice;
    do {
        std::cout << "Secenekler:" << std::endl;
        std::cout << "D: Sonraki agaca git" << std::endl;
        std::cout << "A: Onceki agaca git" << std::endl;
        std::cout << "S: Su anki agaci sil" << std::endl;
        std::cout << "W: Su anki agaci aynala" << std::endl;
        std::cout << "L: Bagli listeyi goster" << std::endl;
        std::cout << "E: Programi sonlandir" << std::endl;
        std::cout << "Seciminiz: ";
        std::cin >> choice;

        switch (choice) {
            case 'D':
            case 'd':
                list.nextTree();
                break;
            case 'A':
            case 'a':
                list.previousTree();
                break;
            case 'S':
            case 's':
                list.deleteCurrentTree();
                break;
            case 'W':
            case 'w':
                list.mirrorCurrentTree();
                break;
            case 'L':
            case 'l':
                list.displayList();
                break;
            case 'E':
            case 'e':
                std::cout << "Program sonlandiriliyor..." << std::endl;
                break;
            default:
                std::cout << "Gecersiz secim!" << std::endl;
                break;
        }
    } while (choice != 'E' && choice != 'e');

    return 0;
}
