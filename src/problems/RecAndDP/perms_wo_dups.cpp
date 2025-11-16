#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include "../../Utils/print_funcs.cpp"

using namespace std;

void gen_perms_for_char(const string& base_str, const char& ch, vector<string>& fill_vec) {
    for(int i = 0; i < base_str.length(); ++i){
        fill_vec.push_back(base_str.substr(0,i) + ch + base_str.substr(i));
    }
    fill_vec.push_back(base_str+ch);
}

void gen_all_perms(const string& base_str, int ind, vector<string>& fill_vec) {
    if (ind == base_str.length()) return;
    if (ind == 0) {
        fill_vec.push_back(string(1,base_str[ind]));
        gen_all_perms(base_str, ind+1, fill_vec);
        return;
    }
    vector<string> new_perms;
    int res_size = fill_vec[0].length()+1 * fill_vec.size();
    new_perms.reserve(res_size);
    for (const string& base_pstr : fill_vec){
        gen_perms_for_char(base_pstr, base_str[ind] , new_perms);
    }
    fill_vec = move(new_perms);
    gen_all_perms(base_str, ind+1, fill_vec);
}

int main() {
    vector<string> base_vec;
    gen_all_perms("abcd", 0, base_vec);
    print_vec<string>(base_vec);
}