#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string compress_string(string src_str){
    if (src_str.length() == 0) return src_str;

    string ret_str;
    char cur_char = src_str[0];
    int cur_count = 1;
    ostringstream container;
    

    for(int i=1; i<src_str.length(); ++i){
        if (src_str[i] == cur_char){
            cur_count++;
        }
        if ((src_str[i] != cur_char) || (i==src_str.length()-1)){
            container << cur_char << cur_count;
            cout << container.str()<<endl;
            cur_char = src_str[i];
            cur_count = 1;
            if ((i == src_str.length() - 1) && (cur_char != src_str[i-1])){
                container<<cur_char<<cur_count;
            }
            // if (src_str[i])
        }
    }
    ret_str = container.str();
    return ret_str.length() < src_str.length() ? ret_str : src_str;
}

int main(int argc, char const *argv[])
{
    string s = argv[1];
    cout << "Compressed string " << compress_string(s) << endl;
    return 0;
}
