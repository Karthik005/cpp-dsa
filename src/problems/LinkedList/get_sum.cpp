#include "../../DataStructures/DataStructures.hpp"
#include "../../DataStructures/LinkedList.cpp"
#include<iostream>
#include<stdexcept>

using namespace std;

int get_num(node<int> *current, int multiplier) {
    if (current == nullptr) return 0;

    return ((current->val*multiplier) + get_num(current->next, 10*multiplier));
}

int get_num_wrapper(node<int> * root) {
    return get_num(root, 1);
}

int get_sum(node<int> *root_one, node<int> *root_two) {
    if (root_one == nullptr || root_two == nullptr) {
        throw invalid_argument("One or more linked lists empty");
    }

    return (get_num_wrapper(root_one) + get_num_wrapper(root_two));
}

int main(){
    LinkedList<int> list1,list2;
    list1.insertBeginning(list1.createNode(3));
    list1.insertBeginning(list1.createNode(3));
    list2.insertBeginning(list2.createNode(3));
    list2.insertBeginning(list2.createNode(3));
    cout << get_sum(list1.getRoot(), list2.getRoot()) << endl;
}