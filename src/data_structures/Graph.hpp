#ifndef DSA_DS_GRAPH_H_
#define DSA_DS_GRAPH_H_

#include<vector>


template <class T> struct v_pair;

template<class T>
struct g_node {
    T value;
    bool visited;
    std::vector<v_pair<T>> adj_list;

    void push_node(g_node * neighbr, int weight=1) {
        adj_list.push_back(v_pair<T>{neighbr, weight});
    }

};

template<class T>
struct v_pair {
    g_node<T>* vert;
    int dist;
};

template<class T>
class Graph {
    private:
    std::vector<g_node<T>*> nodes;
    
    public:
    
    g_node<T> * create_node(T value) {
        g_node<T> * ret_node = new g_node<T>{value, false};
        return ret_node;
    }

    void add_node(g_node<T> * node) {
        nodes.push_back(node);
    }

    g_node<T> * at(int index) {
        return nodes[index];
    }

    g_node<T> operator[](int index){
        return nodes[index];
    }

    int size() {
        return nodes.size();
    }

    ~Graph() {
        for (const auto& x : nodes) {
            delete x;
        }
    }
};

#endif // DSA_DS_GRAPH_H_
