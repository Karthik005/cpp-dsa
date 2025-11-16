#include<iostream>
#include<queue>
#include<string>
#include<cmath>
#include<string.h>

void push_in_que(std::queue<char>& ch_que, const char * ch_ptr, int num_chars) {
    for (int i =0 ; i<num_chars; ++i){
        if (ch_ptr[i] == '_') {
            ch_que.push('%');
            ch_que.push('2');
            ch_que.push('0');
        } else {
            ch_que.push(ch_ptr[i]);
        }
    }
}

void urlify(char * str, int max_chars) {
    std::queue<char> ch_que;
    int i = 0;
    char cur_ch;

    do {
        cur_ch = str[i];
        if (ch_que.empty() && cur_ch != '_') {
            ++i;
            continue;
        } else {
            if (cur_ch == '_' && ch_que.empty()) {
                push_in_que(ch_que, "20", 2);
                str[i] = '%';
            } else {
                push_in_que(ch_que, &cur_ch, 1);
                str[i] = ch_que.front();
                ch_que.pop();
            }
            ++i;
        }
    } while(i<max_chars);

    while(!ch_que.empty()) {
        str[i] = ch_que.front();
        ch_que.pop();
        ++i;
    }

}

int main(int argc, char const *argv[])
{
    int true_size = atoi(argv[2]);
    std::string st = argv[1];
    char s[st.size()+50] = {0};
    strcpy(s, argv[1]);
    urlify(s,  true_size);
    std::cout << "URLIFIED: " << s << std::endl;
    return 0;
}