#include "../../DataStructures/DataStructures.hpp"
#include "../../DataStructures/LinkedListAdv.cpp"
#include "b_tree_aux.hpp"
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

bool is_bst(b_node<int> * root, int& max_val, int& min_val) {
    int l_max, l_min;
    int r_max, r_min;
    b_node<int> * left = root->left;
    b_node<int> * right = root->right;
    // cout<<left->data<<" "<<root->data<<" "<<right->data<<" "<<endl;
    if (left != nullptr) {
        if (!is_bst(left, l_max, l_min)) return false;
    } else {
        l_max = l_min = root->data;
    }
    if (right != nullptr) {
        if (!is_bst(right, r_max, r_min)) return false;
    } else {
        r_min = r_max = root->data;
    }
    if (l_max > root->data || r_min < root->data) {
        return false;
    } else {
        min_val = l_min;
        max_val = r_max;
    }
    return true;
}

int main() {
    std::vector<int> alpha{1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> beta{1, 2, 3, 5, 4, 6, 7};
    // b_node<int> *a = get_b_tree(alpha, 0, 7);
    b_node<int> *b = get_b_tree(alpha, 0, 7);
    int h,j;
    cout<<"Here "<<is_bst(b, h, j)<<endl;
}

