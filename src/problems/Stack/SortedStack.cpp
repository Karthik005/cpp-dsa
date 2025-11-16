#include <iostream>
#include <vector>
#include "../../DataStructures/Stack.cpp"

using namespace std;

template <typename T>
class SortedStack : public Stack<T> {
    
    public:
        void push(T value){
            Stack<T> temp_stack;
            while (Stack<T>::size() > 0 && Stack<T>::peek() < value){
                temp_stack.push(Stack<T>::pop());
            }
            Stack<T>::push(value);
            while(temp_stack.size()>0){
                Stack<T>::push(temp_stack.pop());
            }
        }

};

int main(){
    SortedStack<int> sorted;
    sorted.push(6);
    sorted.push(7);
    sorted.push(8);
    sorted.push(9);
    sorted.push(10);
    sorted.print_stack();
}