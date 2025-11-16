#include<queue>
#include<vector>
#include<limits.h>
#include<iostream>
#include "../../Utils/headers.hpp"

using namespace std;

int get_min_ind(vector<queue<int>> que_vec) {
    int min_ind = -1;
    int min_val = INT_MAX;
    for (int i=0; i<que_vec.size(); ++i) {
        if (!que_vec[i].empty() && que_vec[i].front() < min_val) {
            min_val = que_vec[i].front();
            min_ind = i;
        }
    }
    return min_ind;
}


int get_kth_mult(int k) {
    vector<queue<int>> que_vec(3);
    vector<int> mults;
    que_vec[0].push(1);
    while(mults.size() < k) {
        int min_ind = get_min_ind(que_vec);
        cout << min_ind << endl;
        for (int i=min_ind; i<que_vec.size(); ++i) {
            que_vec[i].push(((i+1)*2 +1) * que_vec[min_ind].front());
        }
        mults.push_back(que_vec[min_ind].front());
        que_vec[min_ind].pop();
    }
    print_vec<int>(mults);
    return mults[k-1];
}

int main() {
    cout << get_kth_mult(28) <<endl;
}