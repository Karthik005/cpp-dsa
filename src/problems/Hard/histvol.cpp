#include "../../Utils/headers.hpp"
#include <algorithm>
#include <cmath>

using namespace std;

class IndexFunc
{
    vector<int> src_vec;

public:
    IndexFunc(const vector<int> &hist) : src_vec(hist) {}
    bool operator()(const int &a, const int &b)
    {
        return src_vec[a] >= src_vec[b];
    }
};

vector<int> get_sorted_inds(const vector<int> &hist)
{
    vector<int> ret_vec(hist.size());
    for (int i = 0; i < hist.size(); ++i)
        ret_vec[i] = i;
    sort(ret_vec.begin(), ret_vec.end(), IndexFunc(hist));
    return ret_vec;
}

int get_vol(int start, int end, int height)
{
    return (abs(start - end) - 1) * height;
}

int get_vol(const vector<int> &hist)
{
    int start, end;
    vector<int> sorted_inds = get_sorted_inds(hist);
    // print_vec(sorted_inds);
    int total_vol;
    if (hist.size() <= 1)
        return 0;
    start = sorted_inds[0];
    end = sorted_inds[1];
    total_vol = get_vol(start, end, hist[end]);

    for (int i = 2; i < hist.size(); i++)
    {
        int current_ind = sorted_inds[i];
        int current_height = hist[current_ind];
        if (current_height == 0)
            break;
        if (current_ind < start)
        {
            total_vol += get_vol(current_ind, start, current_height);
            start = current_ind;
        }
        else if (current_ind > end)
        {
            total_vol += get_vol(end, current_ind, current_height);
            end = current_ind;
        }
        else
        {
            total_vol -= current_height;
        }
    }

    return total_vol;
}

int main() {
    cout << get_vol(vector<int>{0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0}) << endl;
}
