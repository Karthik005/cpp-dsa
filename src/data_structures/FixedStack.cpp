#ifndef DSA_DS_FIXEDSTACK_H_
#define DSA_DS_FIXEDSTACK_H_

#include <vector>
#include <stdexcept>

template <class T>
class FixedStack {
    private:
    std::vector<T> stack_arr_;
    int end_ind_;

    public:
    FixedStack(const int& max_size) :
        stack_arr_{std::vector<T>(max_size)}, end_ind_{-1} {}

    FixedStack(const FixedStack &c_stack) {
        stack_arr_ = c_stack.stack_arr_;
        end_ind_ = c_stack.end_ind_;
    }

    void operator=(const FixedStack &c_stack) {
        stack_arr_ = c_stack.stack_arr_;
        end_ind_ = c_stack.end_ind_;
    }

    T& operator[](const int& index) {
        if (index <0 || index > end_ind_) {
            throw std::out_of_range("Index out of range");
        }

        return stack_arr_[index];
    }

    void push(const T& value) {
        if (end_ind_ == stack_arr_.size() -1) {
            throw std::overflow_error("Stack Overflow");
        }

        stack_arr_[++end_ind_] = value;
    }

    T peek() const {
        if (end_ind_ < 0) {
            throw std::out_of_range("Empty stack");
        }
        
        return stack_arr_[end_ind_];
    }

    void pop() {
        if (end_ind_ < 0) {
            throw std::underflow_error("Empty stack");
        }

        end_ind_--;
    }

    int size() const {
        return end_ind_+1;
    }

    bool is_empty() const {
        return (end_ind_ == -1);
    }
};

#endif // DSA_DS_FIXEDSTACK_H_
