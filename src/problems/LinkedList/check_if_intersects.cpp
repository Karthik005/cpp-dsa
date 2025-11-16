#include<unordered_set>
#include<iostream>

#include "../../DataStructures/DataStructures.hpp"
#include "../../DataStructures/LinkedListAdv.cpp"


using namespace std;

bool check_and_insert(node<int> * pointr, unordered_set<node<int>*>& pointr_set) {
    if (pointr == nullptr) return false;
    if (pointr_set.find(pointr) == pointr_set.end()) {
        pointr_set.insert(pointr);
        return false;
    } else {
        return true;
    }
}

bool intersects(node<int> * one_root, node<int>* two_root, node<int>* &intersect_node) {
    if (one_root == nullptr || two_root == nullptr) return false;

    node<int> *first = one_root, *second = two_root;
    unordered_set<node<int>*> pointr_set;

    while(first != nullptr || second != nullptr) {
        if (check_and_insert(first, pointr_set)) {
                intersect_node = first;
                return true;
        }
        if  (check_and_insert(second, pointr_set)) {
                intersect_node = second;
                return true;
        }
        cout << "Enters here " << endl;
        first = (first == nullptr) ? nullptr : first->next;
        second = (second == nullptr) ? nullptr : second->next;
    }
    return false;
}


int main() {
    LinkedListAdv<int> list1, list2;
    list1.insert_beginning(list1.create_node(3));
    node<int> *common_node = list1.create_node(3);//, *ret_node;
    list1.insert_end(common_node);
    list2.insert_beginning(list2.create_node(3));
    list2.insert_end(common_node);
    // list2.insert_end(list2.create_node(3));
    
    // cout << common_node << " " << intersects(list1.getRoot(), list2.getRoot(), ret_node) <<" "<<ret_node << endl;
    return 0;
}