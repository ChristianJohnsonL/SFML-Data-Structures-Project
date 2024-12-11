#ifndef AVL_H
#define AVL_H

#include <SFML/Graphics.hpp>
#include <memory>

class AVL {
private:
    struct Node {
        int value;
        int height;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node(int v) : value(v), height(1), left(nullptr), right(nullptr) {}
    };

    std::unique_ptr<Node> root;

    int height(const std::unique_ptr<Node>& node);
    int getBalance(const std::unique_ptr<Node>& node);
    void insert(std::unique_ptr<Node>& node, int value);
    std::unique_ptr<Node> rotateLeft(std::unique_ptr<Node> node);
    std::unique_ptr<Node> rotateRight(std::unique_ptr<Node> node);
    void visualize(sf::RenderWindow& window, Node* node, float x, float y, float dx);

public:
    void insert(int value);
    void visualize(sf::RenderWindow& window);
};

#endif
