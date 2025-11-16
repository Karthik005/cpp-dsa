#include "SumReduce.hpp"

#include <iostream>
#include <vector>

int SumReduce::reduce(std::vector<int>& data) {
    int sum = 0;
    for (const int& i : data) {
        sum += i;
    }
    return sum;
}