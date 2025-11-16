#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include "../../DataStructures/LinkedList.cpp"
#include "../../DataStructures/Stack.cpp"
using namespace std;

#define TOT_SIZE 99
#define THRESH 100

template<typename T>
class StackOfStacks{
    private:
        Stack<Stack<T>> stack_o_stacks;
    public:
        void push(T value){
            if (stack_o_stacks.peek().size() < THRESH){
                stack_o_stacks.peek().push(value);
            } else {
                Stack<T> new_stack;
                new_stack.push(value);
                stack_o_stacks.push(new_stack);
            }
        }

        T pop(){
            T value = stack_o_stacks.peek().pop();
            if (stack_o_stacks.peek().size() == 0){
                stack_o_stacks.pop();
            }
            return value;
        }

        T peek(){
            return stack_o_stacks.peek().peek();
        }

        bool is_empty(){
            return stack_o_stacks.is_empty();
        }
};