#include <iostream>
#include<vector>
#include "../../Utils/print_funcs.cpp"
using namespace std;

int find_num_denoms(int total_cents) {
    vector<int> dp_arr(total_cents, 0);
    vector<int> denoms{1,5,10,25};
    // for (const int& i : denoms){
    //     dp_arr[i-1] = 1;
    // }
    dp_arr[0] = 1;
    for (int i=1; i< total_cents; ++i) {
        dp_arr[i] = dp_arr[i-1];
        for (const int &den : denoms)
        {
            dp_arr[i] += (((i+1)%den) < (i%den));
        }
    }

    print_vec(dp_arr);
    return dp_arr[total_cents-1];
}

int main() {
    cout <<find_num_denoms(10) << endl;
}