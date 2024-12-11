#ifndef BTREE_H
#define BTREE_H

#include <SFML/Graphics.hpp>
#include <vector>

class BTree {
private:
    struct Node {
        std::vector<int> keys;
        std::vector<std::unique_ptr<Node>> children;
        bool isLeaf;

        Node(bool leaf) : isLeaf(leaf) {}
    };

    std::unique_ptr<Node> root;
    int t; // Minimum degree

    void insertNonFull(Node* node, int value);
    void splitChild(Node* parent, int i);

public:
    BTree(int minDegree) : t(minDegree), root(std::make_unique<Node>(true)) {}

    void insert(int value);
    void visualize(sf::RenderWindow& window);
};

#endif
