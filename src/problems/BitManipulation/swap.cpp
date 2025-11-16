#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int swap_pairwise(int num) {
    int mask = ((~(1<<31))/3) | 1<<31;
    cout << bitset<32>(mask) << endl;
    return ((num & mask) >> 1) | ((num & (mask >> 1)) << 1); 
}

int main(){
    int ans = swap_pairwise(1755);
    cout << bitset<32>(1755)<<endl;
    cout << bitset<32>(ans)<<endl;
}