#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int longest_ones_seq(int num) {
    
    if (num == 0) return 0;

    int prev_max, cur_max, total_max;
    prev_max = cur_max = total_max = 0;
    bool flag = false;
    while(num != 0) {
        cur_max = 0;
        while(num&1) {
            cout <<"Here "<<num<<endl;
            num >>=1;
            cur_max++;
            flag = false;
        }

        if (cur_max == 0) {
            num >>=1;
            if (!flag) {
                flag = true;

            } else {
                prev_max = 0;
                continue;
            }
        }

        if (cur_max+prev_max+1 > total_max) {
            total_max = cur_max + prev_max +1;
        }
        prev_max = cur_max >0 ? cur_max : prev_max;

    }

    return total_max;
}

int main() {
    cout << longest_ones_seq(1775) << endl;
}