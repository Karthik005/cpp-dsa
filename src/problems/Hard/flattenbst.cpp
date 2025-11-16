#include "../GraphsTrees/b_tree_aux.hpp"
#include "../../Utils/headers.hpp"

using namespace std;

void *flatten(b_node<int> *root, b_node<int> *&start, b_node<int> *&end)
{
    b_node<int> *lstart_node,*rstart_node,*lend_node,*rend_node;
    if (root == nullptr)
        return nullptr;

    if (root->left != nullptr)
    {
        flatten(root->left, lstart_node, lend_node);
        lend_node->right = root;
        root->left = lend_node;
        start = lstart_node;
    }
    else
    {
        start = root;
    }

    if (root->right != nullptr)
    {
        flatten(root->right, rstart_node, rend_node);
        rstart_node->left = root;
        root->right = rstart_node;
        end = rend_node;
    } else {
        end = root;
    }
}

int main(){
    b_node<int> * root = get_b_tree(vector<int>{1,2,3,4,5,6}, 0, 5);
    b_node<int> * start = nullptr;
    b_node<int> * end = nullptr;
    flatten(root, start, end);
    b_node<int> * iter = start;
    while(iter!= nullptr){
        cout << iter->data<<" ,";
        iter = iter->right;
    }
}