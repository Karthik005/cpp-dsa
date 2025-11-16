#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> gen_power_set(vector<int> set_vec)
{
    vector<vector<int>> pwr_set;
    pwr_set.reserve(1<<set_vec.size());
    pwr_set.push_back(vector<int>());

    for (int i = 0; i< set_vec.size(); ++i) {
        int cur_size = pwr_set.size();
        for (int j = 0; j< cur_size; ++j) {
            vector<int> cur_vec = pwr_set[j];
            cur_vec.push_back(set_vec[i]);
            pwr_set.push_back(cur_vec);
        }
    }

    return pwr_set;
}

void print_vec(const vector<int>& vec) {
    for (const int& x : vec){
        cout <<x<<" ";
    }
    cout <<endl;
}

void print_pwr_set(const vector<vector<int>>& pwr_set) {
    cout<<"The size is:"<<pwr_set.size() <<endl;
    for (const vector<int>& vec : pwr_set)
        print_vec(vec);
}

int main() {
    print_pwr_set(gen_power_set(vector<int>{1,2,3,4,5}));
}