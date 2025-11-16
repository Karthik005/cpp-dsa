#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <iostream>

using namespace std;

int smallest_diff(vector<int> a_arr, vector<int> b_arr) {
    
    if (a_arr.size() == 0 || b_arr.size() == 0){
        throw invalid_argument("One or more arguments has size 0");
    }

    unsigned int i = 0, j = 0;
    sort(a_arr.begin(), a_arr.end());
    sort(b_arr.begin(), b_arr.end());
    int min_diff = abs(a_arr[0] - b_arr[0]);
    
    while(true) {
        int diff = abs(a_arr[i]-b_arr[j]);
        if (diff < min_diff) min_diff = diff;
        cout << i << " " << j << endl;
        if (a_arr[i] == b_arr[j]) break;
        else if (a_arr[i] < b_arr[j]) {
            if (i == (a_arr.size()-1) ) break;
            ++i;
        } else {
            if (j == (b_arr.size() - 1))
                break;
            ++j;
        }
        
    }
    return min_diff;
}

int main() {
    vector<int> a{1,2,1,1,1};
    vector<int> b{2,2,2,2,2};

    cout << "min_diff "<< smallest_diff(a,b) <<endl;
}