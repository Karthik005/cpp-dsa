#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

string build_from_pattern(const string& pattern, const string& first,
                          const string& second);

bool matches_pattern(const string& pattern, const string& value) {
    
    if (pattern.length() == 0) 
        return value.length() == 0 ?  true : false;

    char main_char = pattern[0];
    char alt_char = main_char == 'a' ? 'b' : 'a';
    int main_count = count(pattern.begin(),pattern.end(), main_char);
    int alt_count = pattern.length() - main_count;
    int main_max_size = value.length() / main_count;
    int first_alt = pattern.find(alt_char);

    for (int main_size = 1; main_size < main_max_size; ++main_size) {
        int remaining_length = value.length() - (main_size*main_count);
        string first = value.substr(0, main_size);
        cout << "reaches here " << first<< endl;
        for (int alt_size = 0; alt_size < remaining_length; ++alt_size) {
            if (alt_size == 0 || remaining_length % alt_size == 0) {
                int alt_index = first_alt * main_size;
                string second = alt_index == 0 ? "" :
                                value.substr(alt_index, alt_index+alt_size);
                if (build_from_pattern(pattern, first, second) == value) {
                    return true;
                }
            }
        }
    }

    return false;
}

string build_from_pattern(const string &pattern, const string &first,
                          const string &second)
{
    char main_char = pattern[0];
    char alt_char = main_char == 'a' ? 'b' : 'a';
    unordered_map<char, string> ch_map {
        {'a', first},
        {'b', second}
    };
    string ret_str = "";
    for (const char& x : pattern) {
        ret_str+=ch_map[x];
    }
    return ret_str;
}

int main(int argc, char * argv[]) {
    string pattern = argv[1];
    string value = argv[2];
    cout << matches_pattern(pattern, value);
}