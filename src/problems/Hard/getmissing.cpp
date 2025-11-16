#include <iostream>
#include <vector>
#include <utility>
#include "../../Utils/print_funcs.cpp"

using namespace std;
typedef pair<int,int> int_pair;
bool get_bit_at_pos(const vector<int>& arr, int index, int pos) {
    return (arr[index] >> pos) & 1;
}

int_pair get_expected_counts(int num) {
    int count_0 = (num/2)+(num%2);
    int count_1 = num - count_0;

    return int_pair{count_0, count_1};
}

int get_missing_int(const vector<int>& arr) {
    vector<vector<int>> bit_indices(2);
    vector<int> current_indices(arr.size());
    for (int i = 0; i<arr.size(); i++)
    {
        current_indices[i] = i;
    }
    int missing_int = 0;
    int bit_pos = 0;
    while(true) {
        for (const int& i: current_indices) {
            if (get_bit_at_pos(arr, i, bit_pos)){
                bit_indices[1].push_back(i);
            } else {
                bit_indices[0].push_back(i);
            }
        }

        int_pair expected = get_expected_counts(current_indices.size()+1);
        if (bit_indices[0].size() != expected.first){
            current_indices = bit_indices[0];
        } else if (bit_indices[1].size() != expected.second) {
            missing_int |= (1<<bit_pos);
            current_indices = bit_indices[1];
        }
        if (bit_indices[0].size() == 0 || bit_indices[1].size() == 0)
            break;
        bit_indices[0] = vector<int>();
        bit_indices[1] = vector<int>();
        bit_pos++; 
    }

    return missing_int;
}

int main() {
    cout << get_missing_int(vector<int>{0,1,3,2}) <<endl;
}

