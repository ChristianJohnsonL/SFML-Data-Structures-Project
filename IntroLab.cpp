#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "BST.h"
#include "Heap.h"
#include "AVL.h"
#include "BTree.h"

enum class ADTType { None, BST, Heap, AVL, BTree };

void visualizeADT(ADTType currentADT, std::unique_ptr<BST>& bst, std::unique_ptr<Heap>& heap, std::unique_ptr<AVL>& avl, std::unique_ptr<BTree>& btree) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "ADT Visualizer");

    sf::Font font;
    if (!font.loadFromFile("ArialMdm.ttf")) {
        std::cerr << "Failed to load font: ArialMdm.ttf" << std::endl;
        return;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(200, 200, 200));

        if (currentADT == ADTType::BST && bst) {
            bst->visualize(window);
        } else if (currentADT == ADTType::Heap && heap) {
            heap->visualize(window);
        } else if (currentADT == ADTType::AVL && avl) {
            avl->visualize(window);
        } else if (currentADT == ADTType::BTree && btree) {
            btree->visualize(window);
        }

        window.display();
    }
}

void cliMenu() {
    ADTType currentADT = ADTType::None;
    std::unique_ptr<BST> bst;
    std::unique_ptr<Heap> heap;
    std::unique_ptr<AVL> avl;
    std::unique_ptr<BTree> btree;

    while (true) {
        std::cout << "\nSelect an ADT to visualize:" << std::endl;
        std::cout << "1. Binary Search Tree" << std::endl;
        std::cout << "2. Heap" << std::endl;
        std::cout << "3. AVL Tree" << std::endl;
        std::cout << "4. B-Tree" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 5) {
            std::cout << "Exiting program." << std::endl;
            break;
        }

        switch (choice) {
            case 1:
                currentADT = ADTType::BST;
                bst = std::make_unique<BST>();
                heap.reset();
                avl.reset();
                btree.reset();
                std::cout << "Binary Search Tree selected." << std::endl;
                break;
            case 2:
                currentADT = ADTType::Heap;
                heap = std::make_unique<Heap>();
                bst.reset();
                avl.reset();
                btree.reset();
                std::cout << "Heap selected." << std::endl;
                break;
            case 3:
                currentADT = ADTType::AVL;
                avl = std::make_unique<AVL>();
                bst.reset();
                heap.reset();
                btree.reset();
                std::cout << "AVL Tree selected." << std::endl;
                break;
            case 4:
                currentADT = ADTType::BTree;
                btree = std::make_unique<BTree>(3);
                bst.reset();
                heap.reset();
                avl.reset();
                std::cout << "B-Tree selected." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                continue;
        }

        while (true) {
            std::cout << "\nSelect an operation:" << std::endl;
            std::cout << "1. Insert" << std::endl;
            std::cout << "2. Find" << std::endl;
            std::cout << "3. Delete" << std::endl;
            std::cout << "4. Visualize" << std::endl;
            std::cout << "5. Back to Main Menu" << std::endl;
            std::cout << "Enter your choice: ";

            int operation;
            std::cin >> operation;

            if (operation == 5) {
                std::cout << "Returning to Main Menu." << std::endl;
                break;
            }

            int value;
            switch (operation) {
                case 1:
                    std::cout << "Enter value to insert: ";
                    std::cin >> value;
                    if (currentADT == ADTType::BST && bst) {
                        bst->insert(value);
                    } else if (currentADT == ADTType::Heap && heap) {
                        heap->insert(value);
                    } else if (currentADT == ADTType::AVL && avl) {
                        avl->insert(value);
                    } else if (currentADT == ADTType::BTree && btree) {
                        btree->insert(value);
                    } else {
                        std::cout << "No ADT selected." << std::endl;
                    }
                    break;
                case 2:
                    std::cout << "Enter value to find: ";
                    std::cin >> value;
                    std::cout << "Find functionality not implemented." << std::endl;
                    break;
                case 3:
                    std::cout << "Enter value to delete: ";
                    std::cin >> value;
                    std::cout << "Delete functionality not implemented." << std::endl;
                    break;
                case 4:
                    std::cout << "Opening visualization..." << std::endl;
                    visualizeADT(currentADT, bst, heap, avl, btree);
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    }
}

int main() {
    cliMenu();
    return 0;
}
