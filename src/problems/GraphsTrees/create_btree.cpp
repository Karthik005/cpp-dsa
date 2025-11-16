#include<vector>
#include<iostream>
struct b_node {
    int value;
    b_node* left;
    b_node* right;

    ~b_node() {
        delete left;
        delete right;
    }
};

b_node* create_emplace(int val) {
    b_node* new_node = new b_node;
    new_node->value = val;
    new_node->left = nullptr;
    new_node->right = nullptr;
    return new_node;
}

b_node* get_b_tree(std::vector<int> sort_arr, int start_ind, int end_ind) {
    if (start_ind > end_ind) return nullptr;

    int mid_ind = (start_ind+end_ind)/2;
    std::cout<<mid_ind <<std::endl;
    b_node* root = create_emplace(sort_arr[mid_ind]);
    if (start_ind < end_ind) {
        root->left = get_b_tree(sort_arr, start_ind, mid_ind-1);
        root->right = get_b_tree(sort_arr, mid_ind+1, end_ind);
    }

    return root;
}

void print_tree(b_node* root) {
    if (root == nullptr) return;
    std::cout<<root->value<<"  ";
    print_tree(root->left);
    print_tree(root->right);
}

int main() {
    std::vector<int> alpha{1,2,3,4,5,6,7,8};
    std::vector<int> beta{1,2,3,4,5,6,7};
    std::cout << "Yooheoo" << std::endl;
    b_node* a = get_b_tree(alpha, 0, 7);
    b_node* b = get_b_tree(beta, 0, 6);
    print_tree(a);
    std::cout<<std::endl;
    print_tree(b);
    delete a;
    delete b;
}