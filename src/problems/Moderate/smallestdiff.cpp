#include <cmath>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>
#include <iostream>

using namespace std;

int get_min_diff(vector<int> arr1, vector<int> arr2) {
    if (arr1.size() == 0 || arr2.size() == 0){
        throw invalid_argument("One or more arrays empty");
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int i = 0, j = 0;
    int min_diff = INT_MAX;
    do {
        int current_diff = abs(arr1[i] - arr2[j]);
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
        if (arr1[i] < arr2[j]) {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            i++;
        } else {
            break;
        }
    } while (i < arr1.size() && j < arr2.size());
    return min_diff;
}

int main() {
    vector<int> a{
        1,3,15,11,12
    };
    vector<int> b = {23,127,235,19,8};
    cout << get_min_diff(a,b) << endl;
}