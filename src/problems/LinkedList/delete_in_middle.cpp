#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include "../../DataStructures/LinkedList.cpp"

using namespace std;

template<typename T>
void delete_in_middle(node<T>* del_node){
    node<T>* del_next = del_node->next;
    if(del_next != NULL){
        del_node->next = del_next->next;
        del_node->val = del_next->val;
    }
    delete del_next;
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
    linkedList.insertEnd(linkedList.createNode(30));
    delete_in_middle(del_node);
    linkedList.printList();
    // std::cout << linkedList.search(-10) << std::endl;
    return 0;
}