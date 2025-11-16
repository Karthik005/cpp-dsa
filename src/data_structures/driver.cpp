#include <iostream>

#include"LinkedList.hpp"
#include "ArrayList.hpp"

int main_LL(int argc, char const *argv[])
{
    LinkedList<int> linkedList = LinkedList<int>();
    linkedList.insertEnd(linkedList.createNode(10));
    linkedList.insertEnd(linkedList.createNode(34));
    linkedList.printList();
    std::cout << linkedList.search(-10)<<std::endl;
    return 0;
}


int main(){
    ArrayList<int> intList({2});
    intList.push_back(10);
    intList.push_back(12);
    intList.push_back(12);
    intList.push_back(12);
    intList.push_back(12);
    std::cout<<intList.search(10)<<std::endl;
}