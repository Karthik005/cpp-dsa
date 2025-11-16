#include<string>
#include<unordered_map>
#include<iostream>
#include<cmath>
using namespace std;

unordered_map<int, string> units_names = {
    {1, "One"},
    {2, "Two"},
    {3, "Three"},
    {4, "Four"},
    {5, "Five"},
    {6, "Six"},
    {7, "Seven"},
    {8, "Eight"},
    {9, "Nine"},
    {10, "Ten"},
    {11, "Eleven"},
    {12, "Twelve"},
    {13, "Thirteen"},
    {14, "Fourteen"},
    {15, "Fifteen"},
    {16, "Sixteen"},
    {17, "Seventeen"},
    {18, "Eighteen"},
    {19, "Nineteen"}
};

unordered_map<int, string> tens_names = {
    {2, "Twenty"},
    {3, "Thirty"},
    {4, "Forty"},
    {5, "Fifty"},
    {6, "Sixty"},
    {7, "Seventy"},
    {8, "Eighty"},
    {9, "Ninety"}
};

unordered_map<int, string> power_names = {
    {2 , "Hundred"},
    {3 , "Thousand"},
    {6 , "Million"},
    {9 , "Billion"},
    {12 , "Trillion"},
};

int extract_place(int num, int power) {
    cout <<" num, val "<<num<<" " << power << endl;
    return (num/((int)pow(10,power))) % 10;
}

string generate_string(int num) {
    if (num == 0) return "Zero";
    cout << " the number is "<<num <<endl;
    string ret_str = "";
    int power = 0;
    int place_val;
    while(true) {
        place_val = extract_place(num, power);
        cout <<"Breaks here " << place_val<<" "<<power << endl;
        if ((num / ((int)pow(10,power))) == 0) {
            break;
        }
        if (power < 3) {
            if (place_val != 0)
            {
                if (power == 0)
                    ret_str = " " + (units_names[place_val]) + ret_str;
                else if (power == 1){
                    cout << "enters here" << endl;
                    if ((num % 100) < 20)
                    {
                        ret_str = " " + units_names[num % 100];
                    } else {
                        ret_str = " " + (tens_names[place_val]) + ret_str;
                    }
                }else if (power == 2){
                    ret_str = " " +
                            units_names[place_val] + " " +
                            power_names[power] + 
                            ret_str;
                }
            }
            power++;

        } else {
            int sub_num = (num/((int)pow(10,power)) % ((int)pow(10, 3)));
            cout << sub_num << endl;
            if (sub_num != 0){
                ret_str = " "+generate_string(sub_num)+ " " + power_names[power] + ret_str;
            }
            power+=3;
        }
    }
    return ret_str.substr(1);
}

int main () {
    cout << generate_string(1000500)<<endl;
}