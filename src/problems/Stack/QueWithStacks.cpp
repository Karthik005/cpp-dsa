#include<iostream>

#include "../../DataStructures/Stack.cpp"

using namespace std;

template<typename T>
class QueWithStacks {
    private:
    Stack<T> inStack;
    Stack<T> outStack;

    public:
    QueWithStacks(){}

    void push(T val){
        inStack.push(val);
    }

    T pop(){
        if (outStack.size() <=0){
            while(inStack.size() > 0){
                outStack.push(inStack.pop());
            }
        }
        return outStack.pop();
    }

    T peek(){
        if (outStack.size() <=0){
            while(inStack.size() > 0){
                outStack.push(inStack.pop());
            }
        }
        return outStack.peek();
    }

    int size(){
        return inStack.size() + outStack.size();
    }

};

int main()
{
    QueWithStacks<int> sorted;
    sorted.push(6);
    sorted.push(7);
    cout << sorted.pop() << endl;
    cout << sorted.pop() << endl;

}