#include<iostream>
using namespace std;

int get_max(int a, int b) {
    if (a >> 31 && !(b >> 31)) return b;
    if (b >> 31 && !(a >> 31)) return a;
    int c = a-b;
    return (c >> ((sizeof(int) * 8) - 1)) ? b : a;
}

int main() {
    cout << get_max(30,9) << endl;
}