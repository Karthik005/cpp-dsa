#include "../DataStructures/Graph.hpp"

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <functional>
#include <limits>
#include <stdexcept>

using namespace std;


template<typename T>
vector<int> djikstras(Graph<T> graph, g_node<T>* src) {
    typedef g_node<T> gnd;

    if (graph.size() == 0) {throw out_of_range("Graph is empty")};
    unordered_set<T> seen_nodes;
    unordered_map<gnd*, int> node_dist;
    auto cmd = [&](gnd* a, gnd* b) {
        return node_dist[b] - node_dist[a];
    };
    priority_queue<gnd*, vector<gnd*>, cmd> p_que;
    for (int i = 0; i<graph.size() ; ++i) {
        node_dist[graph[i]] = INT8_MAX;
    }

    node_dist[src] = 0;

    for (int i = 0; i < graph.size(); ++i)
    {
        p_que.push(graph[i]);
    }

    gnd current_node = p_que.top();
    while (!p_que.empty()) {
        current_node = p_que.top();
        for (const v_pair& x : current_node.adj_list()) {
            if (seen_nodes.find(x.vert) == seen_nodes.end() &&
                node_dist[current_node] + x.dist < node_dist[x.vert]) {
                node_dist[x.vert] = node_dist[current_node] + x.dist;
            }
        }
        p_que.pop();
        
    }
}
