#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int re_space(const string &base_str, vector<string> &best_strings, vector<int> &best_unmatched, 
             const unordered_set<string> &dict, int index)
{
    if (index == base_str.length())
    {
        return 0;
    }
    if (best_strings[index].length() != 0)
    {
        return best_unmatched[index];
    }
    string optimal_str;
    int num_unmatched = base_str.length();
    cout << index << endl;
    for (int i = index; i < base_str.length(); i++)
    {
        string current_str = base_str.substr(index, i - index + 1);
        int current_unmatched = (dict.find(current_str) != dict.end()) ? 0 : current_str.length();
        if (current_unmatched > num_unmatched)
            continue;
        else
        {
            current_unmatched +=
                re_space(base_str, best_strings, best_unmatched, dict, i + 1);
            if (current_unmatched <= num_unmatched)
            {
                num_unmatched = current_unmatched;
                optimal_str = current_str +" " +((i+1 < base_str.length()) ? best_strings[i + 1] : "");
            }
        }
    }
    best_strings[index] = optimal_str;
    best_unmatched[index] = num_unmatched;
    return num_unmatched;
}


int main() {
    unordered_set<string> dict {
        "looked" ,"just" ,"like" ,"her" ,"brother", "sslooke"
    };
    string base_str = "jesslookedjustliketimherbrother";
    vector<string> best_strs(base_str.length(), "");
    vector<int> best_unmatched(base_str.length(), 0);
    re_space(base_str, best_strs, best_unmatched, dict, 0);
    cout << best_strs[0] << endl;
}