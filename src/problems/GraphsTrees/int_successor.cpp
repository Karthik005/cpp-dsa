#include <iostream>

template<typename T>
struct bp_node {
    T data;
    bp_node<T> * left;
    bp_node<T> * right;
    bp_node<T> * parent;
};

bp_node<int>* get_successor(bp_node<int>* root) {
    if (root->parent == nullptr) {
        return nullptr;
    }
    
    if (root == root->parent->left){
        return root->parent;
    } else {
        return root->parent->parent;
    }
}

