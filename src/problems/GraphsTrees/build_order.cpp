#include "../../DataStructures/Graph.hpp"
#include <iostream>
#include <sstream>
#include <queue>
#include <unordered_map>

using namespace std;

Graph<char> build_dep_graph(vector<char> projects,
                            vector<vector<char>> dep_pairs,
                            unordered_map<char, g_node<char> *>& nmap,
                            unordered_map<char, int> &dep_count)
{
    Graph<char> dep_gr;
    
    for (const char& c : projects) {
        // Initialize the hashmap of pointers to nodes of the graph
        nmap[c] = dep_gr.create_node(c);
        dep_count[c] = 0;
        dep_gr.add_node(nmap[c]);
    }

    for (int i=0; i<dep_pairs.size(); ++i) {
        char dep_from = dep_pairs[i][0];
        char dep_to = dep_pairs[i][1];
        dep_count[dep_to]++;
        nmap[dep_from]->push_node(nmap[dep_to]);
        for (v_pair<char> ed_pr : nmap[dep_from]->adj_list)
        {
            char c = ed_pr.vert->value;
            cout << ed_pr.vert << endl;
            cout <<endl;
        }
    }
}

void print_build_order(const unordered_map<char, g_node<char> *> &nmap,
                        unordered_map<char, int> &dep_count)
{
    int num_done = 0;
    queue<char> node_que;
    ostringstream output;
    for (const pair<char,int> &c : dep_count)
    {
        if (c.second == 0) {
            node_que.push(c.first);
        }
    }
    
    while(!node_que.empty()) {
        char cur = node_que.front();
        output << cur << " ";
        cout << cur<<" "<<(nmap.at(cur))->adj_list.size() << endl;
        for (v_pair<char> ed_pr : nmap.at(cur)->adj_list) {
            char c = ed_pr.vert->value;
            cout << ed_pr.vert << endl;
            if (--dep_count[c] == 0) {
                node_que.push(c);
            }
        }
        node_que.pop();
        num_done++;
    }
    if (num_done != dep_count.size()) {
        cout <<"Invalid yo"<<endl;
    } else {
        cout << output.str() << endl;
    }

}

int main()
{
    vector<char> projs{'a', 'b', 'c', 'd', 'e', 'f'};
    vector<vector<char>> deps{{'a', 'd'}, {'f', 'b'}, {'b', 'd'}, {'f', 'a'}, {'d', 'c'}};
    unordered_map<char, int> dep_count;
    unordered_map<char, g_node<char> *> nmap;
    Graph<char> graph = build_dep_graph(projs, deps,nmap, dep_count);
    for (const char &c : projs)
    {
        // Initialize the hashmap of pointers to nodes of the graph
        cout<<c<<" "<<dep_count[c]<<endl;   
    }

    print_build_order(nmap, dep_count);
}