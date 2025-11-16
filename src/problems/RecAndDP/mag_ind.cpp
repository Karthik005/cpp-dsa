#include <iostream>
#include <vector>

using namespace std;


int get_mag_ind_dist(const vector<int>& values, int start_ind, int end_ind) {
    
    int cur_ind = (start_ind+end_ind)/2;
    if (values[cur_ind] == cur_ind){
        return cur_ind;
    } else {
        if (start_ind == end_ind) {
            return -1;
        }
        if (values[cur_ind] > cur_ind) {
            return get_mag_ind_dist(values, start_ind, cur_ind-1);
        } else {
            return get_mag_ind_dist(values, cur_ind+1, end_ind);
        }
    }
}

int get_mag_ind_ndist(const vector<int> &values, int start_ind, int end_ind)
{

    int cur_ind = (start_ind + end_ind) / 2;
    if (values[cur_ind] == cur_ind)
    {
        return cur_ind;
    }
    else
    {
        if (start_ind == end_ind)
        {
            return -1;
        }
        if (values[cur_ind] > cur_ind)
        {
            if (values[cur_ind] >=0 &&  values[values[cur_ind]] == values[cur_ind])
                return values[cur_ind];
            return get_mag_ind_ndist(values, start_ind, cur_ind - 1);
        }
        else
        {
            if (values[cur_ind] >= 0 && values[values[cur_ind]] == values[cur_ind])
                return values[cur_ind];
            return get_mag_ind_ndist(values, cur_ind + 1, end_ind);
        }
    }
}

int main() {
    cout << get_mag_ind_ndist(vector<int>{0,0,0,5,6,7}, 0, 5) <<endl;
}