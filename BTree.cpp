#include "BTree.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void BTree::insert(int value) {
    if (!root) {
        root = std::make_unique<Node>(true);
        root->keys.push_back(value);
        return;
    }

    if (root->keys.size() == 2 * t - 1) {
        auto newRoot = std::make_unique<Node>(false);
        newRoot->children.push_back(std::move(root));
        splitChild(newRoot.get(), 0);
        root = std::move(newRoot);
    }

    insertNonFull(root.get(), value);
}

void BTree::insertNonFull(Node* node, int value) {
    // Handle insertion logic for B-Tree
}

void BTree::splitChild(Node* parent, int i) {
    // Handle child splitting logic for B-Tree
}

void BTree::visualize(sf::RenderWindow& window) {
    // Visualization for B-Tree
}
