#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include "../../DataStructures/LinkedList.cpp"

using namespace std;

template <typename T>
void delete_node(node<T> *del_node)
{
    node<T> *del_next = del_node->next;
    del_node->next = del_next->next;
    del_node->val = del_next->val;
    delete del_next;
}

template<typename T>
void insert(node<T>* at_node, node<T>* val_node){

    val_node->next = at_node->next;
    at_node->next = val_node;
}

template<typename T>
void partition_ll(node<T>* root, T p_val){
    
    node<T> *low = root, *high = root;
    node<T> *tmp, *runner, *low_prev = NULL;
    int low_ind = 0, high_ind = 0;

    while(high-> val < p_val && high != NULL) {
        high = high->next;
        high_ind++;
    }
    
    while (low->val >= p_val && low != NULL)
    {
        low = low->next;
        if (low_prev == NULL){
            low_prev = root;
        } else {
            low_prev = low_prev->next;
        }
        low_ind++;
    }

    if (high == NULL || low == NULL){
        /*already partitioned*/
        return;
    }
    
    if (low_ind > high_ind){
        /*swap the two*/
        low_prev->next = low->next;
        low->next = high;
    }

    runner = high;
    while(runner->next != NULL){
        tmp = runner->next;
        if (tmp-> val < p_val){
            runner->next = tmp->next;
            tmp->next = low->next;
            low->next = tmp;
        } else{
            runner = runner->next;
        }
    }
    
}

int main(int argc, char const *argv[])
{
    LinkedList<int> linkedList = LinkedList<int>();
    node<int> *root = linkedList.createNode(10);
    linkedList.insertEnd(root);
    linkedList.insertEnd(linkedList.createNode(50));
    linkedList.insertEnd(linkedList.createNode(10));
    linkedList.insertEnd(linkedList.createNode(50));
    node<int> *del_node = linkedList.createNode(40);
    linkedList.insertEnd(del_node);
    linkedList.insertEnd(linkedList.createNode(30));
    linkedList.insertEnd(linkedList.createNode(20));
    linkedList.insertEnd(linkedList.createNode(30));
    partition_ll<int>(root, 30);
    linkedList.printList();
    // std::cout << linkedList.search(-10) << std::endl;
    return 0;
}
