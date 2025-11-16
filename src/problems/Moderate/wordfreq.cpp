#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class FreqFinder {
    private:
    unordered_map<string,int> word_count_;
    int total_count_;

    public:
    FreqFinder() {
        total_count_ = 0;
    }

    void count_word(const string& word) {
        if (word_count_.find(word) == word_count_.end()) {
            word_count_[word] = 1;
        } else {
            word_count_[word]++;
        }
        total_count_++;
    }

    float get_freq(string word) {
        if (word_count_.find(word) == word_count_.end())
        {
            return 0;
        }
        else
        {
            return (float(word_count_[word])/ ((float) total_count_));
        }
    }
};

int main() {
    FreqFinder finder;
    vector<string> strs{
        "apple",
        "apple",
        "apple",
        "mango"
    };

    for (const string& a : strs){
        finder.count_word(a);
    }
    cout <<finder.get_freq("apple")<<endl;
}