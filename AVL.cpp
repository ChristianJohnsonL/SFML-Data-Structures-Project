#include "AVL.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

int AVL::height(const std::unique_ptr<Node>& node) {
    return node ? node->height : 0;
}

int AVL::getBalance(const std::unique_ptr<Node>& node) {
    return node ? height(node->left) - height(node->right) : 0;
}

void AVL::insert(std::unique_ptr<Node>& node, int value) {
    if (!node) {
        node = std::make_unique<Node>(value);
        return;
    }

    if (value < node->value) {
        insert(node->left, value);
    } else if (value > node->value) {
        insert(node->right, value);
    } else {
        return; // No duplicates
    }

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && value < node->left->value) {
        node = rotateRight(std::move(node));
    } else if (balance < -1 && value > node->right->value) {
        node = rotateLeft(std::move(node));
    } else if (balance > 1 && value > node->left->value) {
        node->left = rotateLeft(std::move(node->left));
        node = rotateRight(std::move(node));
    } else if (balance < -1 && value < node->right->value) {
        node->right = rotateRight(std::move(node->right));
        node = rotateLeft(std::move(node));
    }
}

std::unique_ptr<AVL::Node> AVL::rotateLeft(std::unique_ptr<Node> node) {
    auto rightChild = std::move(node->right);
    node->right = std::move(rightChild->left);
    rightChild->left = std::move(node);

    node->height = 1 + std::max(height(node->left), height(node->right));
    rightChild->height = 1 + std::max(height(rightChild->left), height(rightChild->right));

    return rightChild;
}

std::unique_ptr<AVL::Node> AVL::rotateRight(std::unique_ptr<Node> node) {
    auto leftChild = std::move(node->left);
    node->left = std::move(leftChild->right);
    leftChild->right = std::move(node);

    node->height = 1 + std::max(height(node->left), height(node->right));
    leftChild->height = 1 + std::max(height(leftChild->left), height(leftChild->right));

    return leftChild;
}

void AVL::insert(int value) {
    insert(root, value);
}

void AVL::visualize(sf::RenderWindow& window) {
    if (!root) return;
    visualize(window, root.get(), window.getSize().x / 2, 50, 200);
}

void AVL::visualize(sf::RenderWindow& window, Node* node, float x, float y, float dx) {
    if (!node) return;

    sf::CircleShape shape(20);
    shape.setFillColor(sf::Color::Magenta);
    shape.setPosition(x - 20, y);
    window.draw(shape);

    sf::Font font;
    font.loadFromFile("Arial.ttf");
    sf::Text value(std::to_string(node->value), font, 16);
    value.setFillColor(sf::Color::White);
    value.setPosition(x - 10, y + 5);
    window.draw(value);

    if (node->left) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x, y + 20)),
            sf::Vertex(sf::Vector2f(x - dx, y + 100))
        };
        window.draw(line, 2, sf::Lines);
        visualize(window, node->left.get(), x - dx, y + 100, dx / 1.5f);
    }

    if (node->right) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x, y + 20)),
            sf::Vertex(sf::Vector2f(x + dx, y + 100))
        };
        window.draw(line, 2, sf::Lines);
        visualize(window, node->right.get(), x + dx, y + 100, dx / 1.5f);
    }
}
