#ifndef _BTREE_AUX_
#define _BTREE_AUX_

#include "../../DataStructures/DataStructures.hpp"
#include <vector>
#include <iostream>

b_node<int> *create_emplace(int val)
{
    b_node<int> *new_node = new b_node<int>(val);
    return new_node;
}

b_node<int> *get_b_tree(std::vector<int> sort_arr, int start_ind, int end_ind)
{
    if (start_ind > end_ind)
        return nullptr;

    int mid_ind = (start_ind + end_ind) / 2;
    // std::cout << mid_ind << std::endl;
    b_node<int> *root = create_emplace(sort_arr[mid_ind]);
    if (start_ind < end_ind)
    {
        root->left = get_b_tree(sort_arr, start_ind, mid_ind - 1);
        root->right = get_b_tree(sort_arr, mid_ind + 1, end_ind);
    }

    return root;
}

#endif