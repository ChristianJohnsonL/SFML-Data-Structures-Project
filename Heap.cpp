#include "Heap.h"
#include <iostream>
#include <cmath>

void Heap::insert(int value) {
    data.push_back(value);
    int i = data.size() - 1;
    while (i > 0 && data[i] > data[(i - 1) / 2]) {
        std::swap(data[i], data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void Heap::deleteRoot() {
    if (data.empty()) return;
    data[0] = data.back();
    data.pop_back();
    int i = 0;
    while (2 * i + 1 < data.size()) {
        int child = 2 * i + 1;
        if (child + 1 < data.size() && data[child + 1] > data[child])
            child++;
        if (data[i] >= data[child]) break;
        std::swap(data[i], data[child]);
        i = child;
    }
}

void Heap::visualize(sf::RenderWindow& window) {
    if (data.empty()) return;

    float x = window.getSize().x / 2.0f;
    float y = 50.0f;
    float dx = 50.0f;

    for (size_t i = 0; i < data.size(); ++i) {
        sf::CircleShape node(20);
        node.setFillColor(sf::Color::Green);
        node.setPosition(x - dx * i, y + 50.0f * log2(i + 1));
        window.draw(node);

        sf::Text value;
        sf::Font font;
        font.loadFromFile("Arial.ttf");
        value.setFont(font);
        value.setString(std::to_string(data[i]));
        value.setCharacterSize(16);
        value.setFillColor(sf::Color::Black);
        value.setPosition(node.getPosition().x + 10, node.getPosition().y + 5);
        window.draw(value);
    }
}
