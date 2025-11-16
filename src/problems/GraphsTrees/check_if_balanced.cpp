#include "../../DataStructures/DataStructures.hpp"
#include "b_tree_aux.hpp"
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

bool check_if_bal(b_node<int>* root, int& max_depth, int& min_depth) {
    if (root == nullptr){
        max_depth = 0;
        min_depth = 0;
        return true;
    }
    int l_max, l_min;
    int r_max, r_min;
    b_node<int> *left = root->left;
    b_node<int> *right = root->right;
    // cout<<left->data<<" "<<root->data<<" "<<right->data<<" "<<endl;
    if (!check_if_bal(left, l_max, l_min) ||
        !check_if_bal(right, r_max, r_min)){
        return false;
    }
    
    if (l_max-r_min > 1 || r_max - l_min > 1) {
        return false;
    }
    max_depth = max<int>(l_max, r_max)+1;
    min_depth = min<int>(l_min, r_min)+1;

    return true;
}

int main(){
    std::vector<int> alpha{1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> beta{1, 2, 3, 5, 4, 6, 7};
    // b_node<int> *a = get_b_tree(alpha, 0, 7);
    b_node<int> *b = get_b_tree(alpha, 0, 7);
    int h, j;
    cout << "Here " << check_if_bal(b, h, j) << endl;
}