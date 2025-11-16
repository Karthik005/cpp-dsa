#include <iostream>

int count_num_ways(int total_steps) {
    int dp_arr[total_steps] = {1,2,4};
    if (total_steps <= 3) return dp_arr[total_steps-1];
    for (int i = 3; i<total_steps; ++i) {
        
        dp_arr[i] = dp_arr[i-1]+dp_arr[i-2] + dp_arr[i-3];
    }
    return dp_arr[total_steps-1];
}

int main(){
    std::cout << count_num_ways(10) << std::endl;
}