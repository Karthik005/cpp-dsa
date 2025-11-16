#include "headers.hpp"
#include <set>

using namespace std;

pair<int,int> get_pair(const vector<int>& arr_a, const vector<int>& arr_b) {
    int sum_a = 0, sum_b = 0;
    set<int> a_vals;

    for(const int& i : arr_a) {
        sum_a += i;
        a_vals.insert(i);
    }

    for(const int& j : arr_b) {
        sum_b += j;
    }
    int diff = sum_b - sum_a;
    if ((diff % 2) != 0) {
        return pair<int,int>{-1,-1};
    }
    diff/=2;
    for (const int& j : arr_b) {
        int cand_a = j-diff;
        if (a_vals.find(cand_a) != a_vals.end()) {
            return pair<int,int>{cand_a, j};
        }
    }
    return pair<int,int>{-1,-1};
}

int main() {
    vector<int> arr_a{4, 1, 2, 1, 1, 2},
        arr_b{3, 6, 3, 3};
    print_pair<int,int>(get_pair(arr_a, arr_b));
}