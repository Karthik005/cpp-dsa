#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include "../../DataStructures/LinkedList.cpp"
#include "../../DataStructures/Stack.cpp"
using namespace std;

template<typename T>
bool has_cycles(node<T>* root){
    node<T> *behind, *ahead;
    if (root == NULL || root->next == NULL){
        return false;
    }

    behind = root, ahead = root->next;
    while(ahead!=NULL){
        if (ahead  == behind){
            return true;
        }
        if (ahead->next == NULL) break;
        ahead = ahead->next->next, behind = behind->next;
    }

    return false;
}

int main(int argc, char const *argv[])
{
    LinkedList<char> linkedList = LinkedList<char>();
    node<char> *root = linkedList.createNode('a');
    linkedList.insertEnd(root);
    linkedList.insertEnd(linkedList.createNode('b'));
    linkedList.insertEnd(linkedList.createNode('c'));
    // node<int> *del_node = linkedList.createNode(40);
    // linkedList.insertEnd(del_node);
    linkedList.insertEnd(linkedList.createNode('c'));
    linkedList.insertEnd(linkedList.createNode('e'));
    // linkedList.insertEnd(root);
    cout<<has_cycles<char>(root)<<endl;
    // linkedList.printList();
    // std::cout << linkedList.search(-10) << std::endl;
    return 0;
}