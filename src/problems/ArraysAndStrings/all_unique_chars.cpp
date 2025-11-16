#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

bool all_unique_map(const string& str){
    set<char> char_map;
    
    for(const char& c : str){
        if (char_map.find(c) == char_map.end()){
            char_map.insert(c);
        } else {
            return false;
        }
    }
    return true;
}

bool all_unique(string str) {
    sort(str.begin(), str.end());
    for (int i=0; i<str.length()-1; ++i) {
        if (str[i] == str[i+1]) {
            return false;
        }
    }
    return true;
}


int main(int argc, char const *argv[])
{
    string s = argv[1];
    cout << "Contains all unique: " << all_unique(s) << endl;
    return 0;
}
