#include <iostream>
#include <string>

using namespace std;

void print_parens(int rem_open, int rem_close, const string& prefix) {
    if (rem_open == rem_close) {
        if (rem_open == 0)
            cout << prefix <<", ";
        else
            print_parens(rem_open-1, rem_close, prefix+"(");
        return;
    }

    if (rem_open > 0) {
        print_parens(rem_open - 1, rem_close, prefix + "(");
    }
    if (rem_close > 0) {
        print_parens(rem_open, rem_close - 1, prefix + ")");
    }
}


int main() {
    print_parens(5,5,"");
}

