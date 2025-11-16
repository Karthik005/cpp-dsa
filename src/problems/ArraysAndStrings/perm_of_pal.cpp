#include<iostream>
#include<string>
#include<map>

using namespace std;

bool is_present(map<char,bool> c_map, char c){
    if (c_map.find(c) == c_map.end()) return false;
    return c_map[c];
}

bool is_perm_of_pal(string s){
    map<char,bool> char_map;
    int unmatched_chars = 0;
    int w_spaces = 0;
    
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '_'){
            w_spaces++;
        } else {
            if(!is_present(char_map,s[i])){
                char_map[s[i]] = true;
                unmatched_chars++;
            } else {
                char_map[s[i]] = false;
                unmatched_chars--;
            }
        }
    }
    
    return (bool)((s.length()-w_spaces)%2 == unmatched_chars);
}

int main(int argc, char const *argv[])
{
    string s = argv[1];
    cout <<"Is perm of pal: "<<is_perm_of_pal(s)<<endl;
    return 0;
}
