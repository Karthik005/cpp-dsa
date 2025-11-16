#include <iostream>
#include <vector>
#include "../../Utils/print_funcs.cpp"

using namespace std;

bool merge(int a[], int b[], int size_a, int size_b, int max_size) {
    if (size_a+size_b > max_size) {
        return false;
    }

    int b_iter = size_b-1, a_iter = size_a-1;
    int current_iter = size_a+size_b-1;
    while(b_iter >= 0) {
        if (b[b_iter] >= a[a_iter]){
            a[current_iter] = b[b_iter];
            b_iter--;
        }else {
            a[current_iter] = a[a_iter];
            a_iter--;
        }
        current_iter--;
    }
    return true;
}

int main() {
    int a[10] = {5,6,7,8};
    int b[6] = {1,2,3,4, 9,10};
    merge(a, b, 4, 6, 10);
    for (int i : a) {
        cout << i <<",";
    }
    cout << endl;
}