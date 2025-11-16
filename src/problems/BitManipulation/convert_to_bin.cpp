#include<bitset>
#include<iostream>
#include<sstream>
#include<string>
#include <exception>

using namespace std;

string convert(double num) {
    if (num > 1 || num < 0) throw out_of_range("Not a valid argument");
    ostringstream stream;
    stream << "0.";
    while(num > 0) {
        if (stream.str().length() > 32) return "ERROR";
        double r = num * 2;
        cout << num << endl;
        if (r >= 1){
            stream<<1;
            num = r - 1;
        } else {
            stream<<0;
            num = r;
        }
    }
    return stream.str();

}

int main(){
    cout << convert(0.25)<<endl;
}