#include "BST.h"
#include <iostream>

void BST::insert(int value) {
    insert(root, value);
}

void BST::insert(std::unique_ptr<Node>& node, int value) {
    if (!node) {
        node = std::make_unique<Node>(value);
    } else if (value < node->value) {
        insert(node->left, value);
    } else {
        insert(node->right, value);
    }
}

void BST::visualize(sf::RenderWindow& window) {
    if (!root) return;
    visualize(window, root.get(), window.getSize().x / 2, 50, 100, 0);
}

void BST::visualize(sf::RenderWindow& window, Node* node, float x, float y, float dx, int depth) {
    if (!node) return;

    sf::CircleShape shape(20);
    shape.setFillColor(sf::Color::Blue);
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
        visualize(window, node->left.get(), x - dx, y + 100, dx / 1.5f, depth + 1);
    }

    if (node->right) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x, y + 20)),
            sf::Vertex(sf::Vector2f(x + dx, y + 100))
        };
        window.draw(line, 2, sf::Lines);
        visualize(window, node->right.get(), x + dx, y + 100, dx / 1.5f, depth + 1);
    }
}
