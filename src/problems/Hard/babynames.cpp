#include "../../Utils/headers.hpp"
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

typedef unordered_map<string,string> str_str_map;
typedef unordered_map<string,int> str_int_map;
typedef unordered_map<string,list<string>> str_lst_map;

str_str_map get_name_map(const vector<pair<string,string>>& name_pairs) {
    str_str_map name_map;
    str_lst_map list_map;
    for( const auto& pr : name_pairs) {
        if (name_map.find(pr.first) != name_map.end()){
            if (name_map.find(pr.second) != name_map.end()) {
                cout <<"Enters here" << endl;
                string dupe = name_map[pr.second];
                for (const auto& i : list_map[name_map[pr.second]]){
                    name_map[i] = name_map[name_map[pr.first]];
                }
                list_map[pr.first].merge(list_map[dupe]);
            } else {
                name_map[pr.second] = name_map[pr.first];
                list_map[name_map[pr.first]].push_back(pr.second);
            }
        } else if (name_map.find(pr.second) != name_map.end()) {
            name_map[pr.first] = name_map[pr.second];
            list_map[name_map[pr.second]].push_back(pr.first);
        } else {
            name_map[pr.first] = pr.first;
            name_map[pr.second] = name_map[pr.first];
            list_map[pr.first] = list<string>{pr.first, pr.second};
        }
    }

    return name_map;
}

str_int_map get_fin_counts(const str_int_map& name_counts, const str_str_map& name_map) {
    str_int_map fin_counts;
    print_map<string, string>(name_map);
    for (const auto& pr : name_counts) {
        string cur_name = pr.first;
        int cur_count = pr.second;
        string rep_name = name_map.at(cur_name);
        if (fin_counts.find(rep_name) == fin_counts.end()) {
            fin_counts[rep_name] = cur_count;
        } else {
            fin_counts[rep_name] += cur_count;
        }
    }

    return fin_counts;
}

int main() {
    str_int_map name_count{
        {"John",15}, {"Jon",12}, {"Chris",13}, {"Chas",14}, {"Kris",4}, {"Christopher",19}
    };
    vector<pair<string, string>> prs { 
    {"Jon", "John"} , {"John" , "Johnny"}, 
    {"Chris", "Kris"}, {"Chas", "Christopher"},
    {"Chas", "Chaasdf"},
    {"Chris", "Christopher"}
    };
    print_map<string,int>(get_fin_counts(name_count, get_name_map(prs)));
}