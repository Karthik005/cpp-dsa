#include <iostream>
#include <vector>
#include <utility>
#include <ctype.h>
#include <stdexcept>
#include "../../Utils/print_funcs.cpp"

using namespace std;

typedef pair<int,int> intpair;

intpair get_longest_subarr(const vector<char>& arr) {
    vector<vector<intpair>> let_num_cnt(arr.size(), vector<intpair>(arr.size(), intpair{0,0}));
    intpair indices{-1,-1};
    int max_count = 0;

    for(int i = 0; i<arr.size(); ++i) {
        for(int j = i; j>=0; --j) {
            if (i==j){
                if (isalpha(arr[i])) {
                    let_num_cnt[i][j] = intpair{1,0};
                } else if (isdigit(arr[i])) {
                    let_num_cnt[i][j] = intpair{0,1};
                } else {
                    throw invalid_argument("Invalid char");
                }
            } else {
                let_num_cnt[i][j].first = let_num_cnt[i][i].first + let_num_cnt[i-1][j].first;
                let_num_cnt[i][j].second = let_num_cnt[i][i].second + let_num_cnt[i-1][j].second;
                if (let_num_cnt[i][j].first == let_num_cnt[i][j].second && let_num_cnt[i][j].first > max_count){
                    max_count = let_num_cnt[i][j].first;
                    indices = intpair{j,i};
                }
            }
        }
    }

    return indices;
}

int main() {
    intpair a = get_longest_subarr(vector<char>{'1', 'a', 'b', 'c', 'd', 'e', '2', '3', '4', 'c'});
    print_pair<int,int>(a);
}
