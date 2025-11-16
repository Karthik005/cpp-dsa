#include "SquareMap.hpp"

#include <iostream>

void
SquareMap::map(std::vector<int> &data) {
    for (int& i : data) {
        i*= i;
    }
}