#include <iostream>
#include <vector>

using namespace std;

int find_center(vector<int> rotated_arr) {
    if (rotated_arr.size() < 1) return 0;
    int low = 0, high = rotated_arr.size()-1;
    while(low <= high) {
        int mid = (low + high)/2;
        cout << low << ":"<<mid<<":"<<high<<endl;
        if (rotated_arr[mid] < rotated_arr[low]){
            high = mid-1;
        } else if (rotated_arr[mid] > rotated_arr[high]) {
            low = mid+1;
        } else {
            return high+1;
        }
        if (rotated_arr[low] == rotated_arr[high]) break;
    }
    cout <<"Center:"<<low<<endl;
    return low;
}

inline int get_adj_ind(int actual_ind, int cent_ind, int size){
    return (actual_ind+cent_ind) % size;
}

bool mod_bin_search(int num, int cent_ind, vector<int> rotated_arr) {
    int low = 0;
    int high = rotated_arr.size() -1 ;
    int size = rotated_arr.size();
    while (low <= high){
        int mod_low = get_adj_ind(low, cent_ind, size);
        int mod_high = get_adj_ind(high, cent_ind, size);
        int mid = (low+high)/2;
        int mod_mid = get_adj_ind(mid, cent_ind, size);
        cout << "HERE "<<mod_mid << endl;
        
        if (rotated_arr[mod_mid] > num) {
            high = mid-1;
        } else if (rotated_arr[mod_mid] < num) {
            low = mid+1;
        } else {
            return true;
        }
    }
    
    return false;
}

bool rot_search(vector<int> rot_arr, int num) {
    int cent_ind = find_center(rot_arr);
    return mod_bin_search(num, cent_ind, rot_arr);
}

int main() {
    cout << rot_search(vector<int>{5,6,1,2,3}, 6);
}

