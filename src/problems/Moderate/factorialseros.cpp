#include <iostream>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

int get_fact_zeros(int n) {
    int zeros = 0;
    for (int i =5; i<=n; ++i) {
        int k = i;
        unordered_map<int, int> power_map;
        int cur_pow = 0;
        while ((k%5) == 0){
            if (power_map.find(k) != power_map.end()){
                cur_pow+=power_map[k];
                break;
            } else{
                cur_pow++;
                k/=5;
            }
        }
        zeros+=cur_pow;
        power_map[i] = cur_pow;
    }
    return zeros;
}

int main(int argc, char* argv[]) {
    cout << get_fact_zeros(atoi(argv[1])) << endl;
}