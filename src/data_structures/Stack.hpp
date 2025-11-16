#ifndef DSA_DS_STACK_H_
#define DSA_DS_STACK_H_

#include<vector>

template<class T>
class Stack{
    protected:
        std::vector<T> stack_;
    public:
        Stack(){
        }

        T peek(){
            return stack_[stack_.size()-1];
        }

        T pop(){
            T val = stack_[stack_.size()-1];
            stack_.pop_back();
            return val;
        }

        void push(T val){
            stack_.push_back(val);
        }

        int size(){
            return stack_.size();
        }

        bool is_empty(){
            return stack_.size() == 0;
        }

        void print_stack(){
            for(int i = stack_.size()-1; i>=0;--i){
                cout << stack_[i]<<" ";
            }
            cout <<endl;
        }

};

#endif // DSA_DS_STACK_H_
