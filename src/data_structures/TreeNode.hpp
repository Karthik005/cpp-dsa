#ifndef DSA_DS_TREENODE_H_
#define DSA_DS_TREENODE_H_

#include <vector>

template<class T>
struct t_node{
    T data;
    vector<T> children;
    
    t_node(T data_val) {
        data = data_val;
    }
};

#endif // DSA_DS_TREENODE_H_
