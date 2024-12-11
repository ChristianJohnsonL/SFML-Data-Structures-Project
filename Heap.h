#ifndef HEAP_H
#define HEAP_H

#include <SFML/Graphics.hpp>
#include <vector>

class Heap {
private:
    std::vector<int> data;

public:
    void insert(int value);
    void deleteRoot();
    void visualize(sf::RenderWindow& window);
};

#endif
