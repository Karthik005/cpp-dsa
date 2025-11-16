#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int get_year_max(const vector<pair<int,int>>& bd_pairs) {
    int max_alive = 0;
    int max_year = 0;
    int births[101] = {0};
    int deaths[101] = {0};
    int total_alive = 0;

    for (const auto& pr : bd_pairs) {
        births[pr.first-1900]+=1;
        if (pr.second < 2000) deaths[pr.second-1900+1]+=1;
    }
    for (int i = 0; i<101; ++i) {
        total_alive += (births[i] - deaths[i]);
        if (total_alive > max_alive){
            max_alive = total_alive;
            max_year = i;
        }
    }

    return max_year+1900;
}

int main() {
    vector<pair<int,int>> years = {
        {1900,1908},
        {1901,1909},
        {1902,1909},
        {1903,1910},
        {1905,1910},
        {1910,1910}
    };
    cout <<get_year_max(years) << endl;
}