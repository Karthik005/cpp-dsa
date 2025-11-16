#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include "../../DataStructures/LinkedList.cpp"

using namespace std;

void remove_dups(node<int>* root){
    node<int> *runner = root, *previous = root;
    node<int> *current = previous->next, *interim;
    while(current != NULL){
        runner = root;
        while(runner != current){
            if (runner->val == current->val){
                interim = current;
                previous->next = current->next;
                current = previous->next;
                delete interim;
                break;
            }
            runner = runner->next;
        }
        if (runner == current){
            previous = current;
            current = current->next;
        }
    }
}


int main(int argc, char const *argv[])
{
    LinkedList<int> linkedList = LinkedList<int>();
    node<int>* root = linkedList.createNode(10);
    linkedList.insertEnd(root);
    linkedList.insertEnd(linkedList.createNode(50));
    linkedList.insertEnd(linkedList.createNode(10));
    linkedList.insertEnd(linkedList.createNode(50));
    linkedList.insertEnd(linkedList.createNode(40));
    linkedList.insertEnd(linkedList.createNode(30));
    linkedList.insertEnd(linkedList.createNode(30));
    remove_dups(root);
    linkedList.printList();
    // std::cout << linkedList.search(-10) << std::endl;
    return 0;
}
