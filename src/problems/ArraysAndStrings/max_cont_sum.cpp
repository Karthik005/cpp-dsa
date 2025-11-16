#include<vector>
#include<iostream>
#include<cmath>
#include<stdexcept>

using namespace std;

int get_max_sum_cont(const vector<int>& arr) {
    if (arr.size() == 0) throw invalid_argument("Zero size array");
    int max_sum = arr[0];
    int max_sum_here = arr[0];

    for (unsigned int i = 1; i< arr.size(); ++i) {
        max_sum_here = max<int>(arr[i], arr[i]+max_sum_here);
        max_sum = max<int>(max_sum, max_sum_here);
    }
    return max_sum;
}

int main(){
    cout << "Max sum is " << get_max_sum_cont(vector<int>({2, -8, 3, -2, 4, -10})) << endl;
}