#include "../../DataStructures/DataStructures.hpp"
#include "../../DataStructures/LinkedListAdv.cpp"
#include "b_tree_aux.hpp"
#include <vector>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void find_common_ancestor(b_node<int> *root, const pair<int,int>& val_pair, pair<bool,bool>& pres_pair, int& store_val) {
    if (root == nullptr){
        pres_pair = pair<bool, bool>{false, false};
        return;
    }

    pair<bool, bool> l_pair, r_pair;
    int lstore, rstore;
    find_common_ancestor(root->left, val_pair, l_pair,lstore);
    find_common_ancestor(root->right, val_pair, r_pair,rstore);

    if ((l_pair.first && l_pair.second) ||
        (r_pair.first && r_pair.second)) {
        store_val = (lstore * l_pair.first * l_pair.second) +
                    (rstore * r_pair.first * r_pair.second);
        pres_pair = pair<bool, bool>{true, true};
        return;
    }

    if ((l_pair.first && r_pair.second) ||
        (l_pair.second && r_pair.first) ||
        ((l_pair.first || r_pair.first) && root->data == val_pair.second) ||
        ((l_pair.second || r_pair.second) && root->data == val_pair.first)) {
        pres_pair = pair<bool, bool>{true, true};
        store_val = root->data;
        return;
    }

    if (l_pair.first || r_pair.first) {
        pres_pair = pair<bool, bool>{true, false};
    } else if (r_pair.second || l_pair.second) {
        pres_pair = pair<bool, bool>{false, true};
    }

    if (root->data == val_pair.first) {
        pres_pair = pair<bool, bool>{true, false};
        return;
    } else if (root->data == val_pair.second){
        pres_pair = pair<bool, bool>{false, true};
        return;
    }

}

void common_ancestor(b_node<int> *root, const pair<int, int> &val_pair) {
    pair<bool, bool> root_pair{false, false};
    int store_val;
    find_common_ancestor(root, val_pair, root_pair, store_val);
    if (root_pair.first && root_pair.second) {
        cout <<"Common ancestor is "<<store_val;

    }else {
        cout <<"No common ancestor";
    }
}

int main()
{
    std::vector<int> alpha{1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> beta{1, 2, 3, 5, 4, 6, 7};
    // b_node<int> *a = get_b_tree(alpha, 0, 7);
    b_node<int> *b = get_b_tree(alpha, 0, 7);
    pair<int, int> val_pair{1,8};
    common_ancestor(b, val_pair);
}
