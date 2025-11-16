#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "../../Utils/print_funcs.cpp"

using namespace std;

int MAX_CHAR = 26;
string sort_str(const string& src_str) {
    int char_count[MAX_CHAR] = {0};

    for (const char& a : src_str) {
        char_count[a - 'a'] += 1;
    }

    string fin_str;
    for (int i=0; i<MAX_CHAR; ++i){
        fin_str+=string(char_count[i], 'a'+i);
    }
    return fin_str;
}

struct StrMap {
    string base_str;
    int orig_ind;
};


bool compare(const StrMap& a, const StrMap& b){
        return a.base_str < b.base_str;
}

void sort_anagrams(vector<string>& bae_strs) {
    vector<StrMap> strmaps(bae_strs.size());
    vector<string> pre_maps(bae_strs);
    for (int i = 0; i<bae_strs.size(); ++i) {
        strmaps[i] = (StrMap{sort_str(bae_strs[i]), i});
        cout << strmaps[i].base_str;
    }
    sort(strmaps.begin(), strmaps.end(), compare);
    int i = 0;
    for (const StrMap& map : strmaps){
        cout << map.orig_ind<<endl;
        bae_strs[i] = pre_maps[map.orig_ind];
        ++i;
    }
}

int main() {
    vector<string> strs = {
        "apple",
        "pear",
        "arep",
        "pplea"
    };

    sort_anagrams(strs);
    print_vec(strs);
}

