#include <iostream>
#include <bitset>

using namespace std;

int insert_in_num(int m, int n, int i, int j){
    int mask = ~(((1 << (j-i+1)) - 1) << i);
    int update_bits = m << i;
    return(n & mask | update_bits);
}

int main(){
    int a = 1<<31 | 1<<15 | 1<<12;
    int b = 31;
    int i = 2, j = 6;
    cout << bitset<32>(insert_in_num(b,a,i,j))<<endl;
}