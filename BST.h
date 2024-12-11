#ifndef BST_H
#define BST_H

#include <SFML/Graphics.hpp>
#include <memory>

class BST {
private:
    struct Node {
        int value;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node(int v) : value(v), left(nullptr), right(nullptr) {}
    };

    std::unique_ptr<Node> root;

    void insert(std::unique_ptr<Node>& node, int value);
    void visualize(sf::RenderWindow& window, Node* node, float x, float y, float dx, int depth);

public:
    void insert(int value);
    void visualize(sf::RenderWindow& window);
};

#endif
