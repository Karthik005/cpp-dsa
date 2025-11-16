#include <vector>
#include <utility>
#include <iostream>
#include "../../Utils/print_funcs.cpp"

using namespace std;

int mod_search(const vector<int>& arr, int n , int st, int end) {
    int start = st;
    int ender = end;
    while(st<=end) {
        int cent = (st+end)/2;
        if(arr[cent] < n) {
            st = cent+1;
        } else if (arr[cent] > n) {
            end = cent-1;
        } else {
            return cent;
        }
    }
    if (arr[st] > n) return st;
    else return st+1;
}

pair<int,int> get_indices_sort (const vector<int>& arr) {
    int m = -1, n = -1;
    int e_min = 0, e_max = 0;
    for(int i = 0; i<arr.size()-1; ++i) {
        if(arr[i+1] < arr[i]) {
            n = i+1;
            if(m == -1) {
                m = i;
                e_min = e_max = arr[m];
            }
        }
    }
    if (m == -1) return pair<int,int>{m,n};
    for (int i = m+1; i<n ; ++i) {
        cout << e_max << " " << e_min << " " << arr[i] << endl;
        if (arr[i] < e_min)
            e_min = arr[i];
        if (arr[i] > e_max)
            e_max = arr[i];
    }

    int st = m, end = n;
    if (e_min < arr[m-1]) {
        st = mod_search(arr, e_min, 0, m-1);
        if (arr[st] < e_min) st++;
    }
    if (n < arr.size() - 1 && e_max > arr[n+1]) {
        cout << "enters here" << e_max <<" "<<n <<endl;
        end = mod_search(arr, e_max, n+1, arr.size()-1);
        if (arr[end] > e_max) end--;
    }

    return pair<int,int>{st,end};
}

int main() {
    vector<int> src{1,2,4,7,10,11,7,12,6,7,16,18,19};
    print_vec<int>(src);
    print_pair<int,int>(get_indices_sort(src));
}