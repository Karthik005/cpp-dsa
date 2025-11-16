#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include "../../DataStructures/LinkedList.cpp"

using namespace std;


template<typename T>
node<T>* get_kth_to_last(node<T>* root, int k){
    node<T> *ahead, *behind;
    ahead = behind = root;
    
    for(int i = 0; i < k; i++)
    {
        ahead = ahead->next;
        if (ahead == NULL){
            return NULL;
        }
    }

    while(ahead != NULL){
        ahead = ahead->next;
        behind = behind->next;
    }

    return behind;

}

int main(int argc, char const *argv[])
{
    LinkedList<int> linkedList = LinkedList<int>();
    node<int> *root = linkedList.createNode(10);
    linkedList.insertEnd(root);
    linkedList.insertEnd(linkedList.createNode(50));
    linkedList.insertEnd(linkedList.createNode(10));
    linkedList.insertEnd(linkedList.createNode(50));
    linkedList.insertEnd(linkedList.createNode(40));
    linkedList.insertEnd(linkedList.createNode(30));
    linkedList.insertEnd(linkedList.createNode(30));
    cout << get_kth_to_last(root, 3)->val<<endl;
    // linkedList.printList();
    // std::cout << linkedList.search(-10) << std::endl;
    return 0;
}