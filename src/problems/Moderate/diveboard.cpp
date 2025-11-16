#include <iostream>
#include <vector>
#include "../../Utils/print_funcs.cpp"
using namespace std;

vector<int> get_lengths(int num_k, int shorter, int longer) {
    vector<int> lengths(num_k+1);
    for (int i = 0; i<=num_k; i++) {
        lengths[i] = ((i*shorter) + ((num_k-i)*longer));
    }
    return lengths;
}

int main() {
    print_vec(get_lengths(10, 3, 5));
}
