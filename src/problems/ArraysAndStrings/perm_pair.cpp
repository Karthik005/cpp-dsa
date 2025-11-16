#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

bool check_if_perm(const string& a, const string& b) {
    if (a.length() != b.length()) return false;
    
    unordered_map<char,int> ch_map;
    for(const char& x : a) {
        if (ch_map.find(x) == ch_map.end()) {
            ch_map[x] = 1;
        } else {
            ch_map[x]++;
        }
    }

    for (const char &x : b) {
        if (ch_map.find(x) == ch_map.end() ||
            ch_map[x] == 0) {
            return false;
        }
        else {
            ch_map[x]--;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string s = argv[1];
    string b = argv[2];
    cout << "Is perm of pal: " << check_if_perm(s,b) << endl;
    return 0;
}