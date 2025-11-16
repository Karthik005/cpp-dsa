#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_set>
#include <cmath>
#include "../../Utils/print_funcs.cpp"

using namespace std;

string get_longest_composed(const vector<string> &word_lst)
{
    unordered_set<string> words;
    int max_word_len = 0;
    for (const string &word : word_lst)
    {
        words.insert(word);
        max_word_len = max<int>(max_word_len, word.length());
    }
    list<string> composed_words;
    string ret_str = "";

    for (int i = 0; i < word_lst.size(); ++i)
    {
        const string &current_word = word_lst[i];
        // print_vec<string>(composed_words);
        // cout << current_word;
        list<string> new_composed;
        for (const string &word : composed_words)
        {
            if ((current_word.length() + word.length()) <= max_word_len)
            {
                string candidate_1 = current_word + word;
                string candidate_2 = word + current_word;
                new_composed.push_back(candidate_1);
                new_composed.push_back(candidate_2);
                bool cand1_valid = (words.find(candidate_1) != words.end());
                bool cand2_valid = words.find(candidate_2) != words.end();
                if (!cand1_valid && !cand2_valid) continue;
                if (candidate_1.length() > ret_str.length())
                {
                    ret_str = cand1_valid ? candidate_1 : candidate_2;
                    if (ret_str.length() == max_word_len) return ret_str;
                }
            }
        }
        composed_words.insert(composed_words.end(), new_composed.begin(), new_composed.end());
        composed_words.push_back(current_word);
    }
    return ret_str;
}

int main() {
    cout << get_longest_composed(vector<string>{"cat", "banana", "dog", "nana", "walk", "walker", "dogwalker"}) << endl;
}
