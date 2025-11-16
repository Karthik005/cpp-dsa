#include <iostream>
#include <utility>
#include <string>
#include <stdexcept>
#include <unordered_map>

using namespace std;

pair<int,int> get_hits(string guess, string pattern) {
    if (guess.length() != 4 || pattern.length() != 4) 
        throw invalid_argument("Invalid input");

    int c_count[4] = {0};
    unordered_map<char,int> c_map {
        {'R', 0},
        {'Y', 1},
        {'G', 2},
        {'B', 3},
    };

    int hits = 0, pseudo_hits = 0;

    for (int i = 0; i<4; ++i) {
        const char& g_c = guess[i];
        const char& p_c = pattern[i];
        if (g_c == p_c) {
            hits++;
        } else {
            if (c_count[c_map[p_c]] > 0) {
                pseudo_hits++;
            }
            if (c_count[c_map[g_c]] < 0 ) {
                pseudo_hits++;
            }
            c_count[c_map[p_c]]--;
            c_count[c_map[g_c]]++;
        }
    }
    return pair<int,int>{hits, pseudo_hits};
}

int main() {
    pair<int,int> a = get_hits("GBRY", "RGBY");
    cout << a.first << ","<<a.second<<endl;
}