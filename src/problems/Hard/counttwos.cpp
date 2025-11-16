#include <iostream>
#include <cmath>

using namespace std;

int get_mod_cnt(const int &n, const int &cur_pow, const int &prev_pow);

int count_num_twos(int n)
{
    int prev_pow = 1, cur_pow = 10;
    int total_count = 0;

    while((n % cur_pow) != n) {
        total_count += (n/cur_pow) * prev_pow;
        total_count += get_mod_cnt(n, cur_pow, prev_pow);
        cout << total_count << endl;
        prev_pow = cur_pow;
        cur_pow *= 10;
    }

    total_count += get_mod_cnt(n, cur_pow, prev_pow);
    return total_count;

}

int get_mod_cnt(const int& n, const int& cur_pow, const int& prev_pow) {
    int mod_val = n%cur_pow;
    int cur_2_mult = prev_pow << 1;
    mod_val = min<int>(prev_pow, mod_val-cur_2_mult+1);
    return max<int>(mod_val, 0);
}

int main() {
    cout << count_num_twos(123) << endl;
}