#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool is_one_edit_away(string a, string b){
    
    bool edit_done = false;
    string shorter = (a.length() < b.length()) ? a : b;
    string longer = (shorter == a ) ? b : a;
    int s_ind = 0;

    if (shorter.length() != longer.length()){
        if (shorter.length() < longer.length() -1)
            return false;
    }
    for (int l_ind = 0; l_ind<longer.length();l_ind++){
        if (shorter[s_ind] != longer[l_ind]){
            if (edit_done){
                return false;
            } else{
                edit_done = true;
                if (shorter.length() == longer.length()){
                    s_ind++;
                }
            }
        } else{
            s_ind++;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string a = argv[1], b = argv[2];
    cout << "Is one edit away: " << is_one_edit_away(a,b) << endl;
    return 0;
}