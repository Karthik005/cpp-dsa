#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int count_num_ones(int num){
    int count = 0;
    while(num != 0) {
        num = num&(num-1);
        count++;
    }
    return count;
}


int get_bit_diff(int a, int b) {
    int c = a^b;
    return count_num_ones(c);
}

int main() {
    cout << get_bit_diff(29, 15)<<endl;
    cout << count_num_ones((1<<30)-1);
}