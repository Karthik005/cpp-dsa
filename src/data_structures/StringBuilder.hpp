#ifndef DSA_DS_STRINGBUILDER_H_
#define DSA_DS_STRINGBUILDER_H_

#include <vector>
#include <string>
#include <iostream>

class StringBuilder {
    
    private:
    std::vector<char> array_;

    public:
    StringBuilder() {}

    StringBuilder(const StringBuilder& csb) {
        array_ = csb.array_;
    }

    StringBuilder(const std::string& str) {
        array_ = std::vector<char>(str.length());
        for(int i = 0; i < str.length(); i++)
        {
            array_[i] = str[i];
        }
    }

    void operator=(const StringBuilder& csb) {
        array_ = csb.array_;
    }

    void operator+=(const std::string& str) {
        for (const char &x : str) {
            array_.push_back(x);
        }
    }

    std::string to_string() {
        std::string ret_str(array_.size(), ' ');
        for (int i=0; i < array_.size(); ++i) {
            ret_str[i] = array_[i];
        }
        return ret_str;
    }

    int length(){
        return array_.size();
    }

};

int main(){
    StringBuilder builder("");
    for (int i = 0; i< 10; ++i) {
        builder+="Karthik is Awesome\n";
    }
    std::cout << builder.to_string() << builder.length() << std::endl;
    return 0;
}

#endif // DSA_DS_STRINGBUILDER_H_
