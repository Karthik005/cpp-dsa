#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include "../../DataStructures/LinkedList.cpp"
#include "../../DataStructures/Stack.cpp"
using namespace std;

template<typename T>
bool is_palindrome(node<T>* root){
    node<T>* base, *runner;
    if (root == NULL || root->next == NULL){
        return true;
    }
    base = root, runner = root->next;
    int length = 2, cur_ind = 0;
    Stack<T> pal_stack;

    while(base!=NULL){
        if (runner == NULL){
            // if (length%2 == 1 && cur_ind == (length/2)){
            //     pal_stack.pop();
            // }
            if (cur_ind >= (length+1)/2){
                cout <<"Popping value "<<pal_stack.peek()<<endl;
                if (pal_stack.pop() != base->val){
                    return false;
                }
            }
        } else {
                        
            pal_stack.push(base->val);
            cout <<"Pushing value "<<pal_stack.peek()<<endl;
            length+=((runner->next == NULL) ? 0 : (runner->next->next == NULL) + 1);
            runner = (runner->next == NULL) ? runner->next : runner->next->next;
        }
        cur_ind++;
        base = base->next;
    }
    return true;
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
    linkedList.insertEnd(linkedList.createNode('a'));
    cout<<is_palindrome<char>(root)<<endl;
    // linkedList.printList();
    // std::cout << linkedList.search(-10) << std::endl;
    return 0;
}

    



