#ifndef DSA_DS_LLADV_H_
#define DSA_DS_LLADV_H_

#include<stdexcept>
#include<iostream>

#include "Node.hpp"

template<class T>
class LinkedListAdv {

    private:
    node<T> *root_;
    int size_;

    public:

    node<T> *create_node(const T &value) {
        node<T> *ret_node = new node<T>{value, nullptr};
        return ret_node;
    }

    LinkedListAdv() : root_{nullptr}, size_{0} {}

    LinkedListAdv(const LinkedListAdv& c_list) : root_{nullptr}, size_{c_list.size_} {
        if (c_list.size_ == 0) return;
        node<T> *c_node = c_list.root_, *prev_node = root_;
        while (c_node != nullptr) {
            node<T> *new_node = create_node(c_node->val);
            if (root_ == nullptr) {
                root_ = new_node;
                prev_node = root_;
            } else {
                prev_node->next = new_node;
                prev_node = new_node;
            }
            c_node = c_node->next;
        }
    }

    node<T>& operator[](const int& index) {
        if (index < 0 || index >= size_) {
            throw std::out_of_range();
        }

        node<T> *ret_node = root_;
        for (int i = 1; i <= index; ++i) ret_node = ret_node->next;
        return *ret_node;
    }

    void insert_beginning(node<T>* const &nodeval) {
        node<T>* temp_node = root_;
        root_ = nodeval;
        root_->next = temp_node;
        size_++;
    }

    void insert_end(node<T>* const &nodeval) {
        node<T> *temp_node = root_;
        if (temp_node == nullptr) {
            root_ = nodeval;
            size_++;
            return;
        }
        for (int i = 1; i < size_; ++i) temp_node = temp_node->next;
        temp_node->next = nodeval;
        size_++;
    }

    void delete_beginning() {
        if (size_ == 0) {
            throw std::underflow_error("");
        }
        node<T>* temp_node = root_;
        root_ = root_->next;
        delete temp_node;
        size_--;
    }

    void delete_end() {
        if (size_ == 0){
            throw std::underflow_error("");
        }

        node<T> *temp_node = root_, *prev_node = root_;
        for (int i = 1; i<size_; ++i) {
            prev_node = temp_node;
            temp_node = temp_node->next;
        }
        delete temp_node;
        if (temp_node != root_) {
            prev_node->next = nullptr;
        } else {
            root_ = nullptr;
        }
        size_--;
    }

    void printList()
    {
        node<T> *iter = root_;
        while (iter != nullptr)
        {
            std::cout << iter->val << " ";
            iter = iter->next;
        }
        std::cout<<std::endl;
    }

    void operator=(const LinkedListAdv<T> &c_list);

    int find(const T& value) {
        node<T>* iter = root_;
        int current_ind = 0;
        do {
            if (iter->val == value) return current_ind;
            iter = iter->next;
            current_ind++;
        } while(iter != nullptr);

        return -1;
    }

    node<T>* get_root(){
        return root_;
    }

    ~LinkedListAdv() {
        while (size_ > 0) {
            delete_beginning();
        }
    }
};

template<typename T>
void LinkedListAdv<T>::operator=(const LinkedListAdv<T> &c_list)
{
    root_ = nullptr;
    size_ = c_list.size_;
    
    if (c_list.size_ == 0)
        return;
    
    node<T> *c_node = c_list.root_, *prev_node = root_;
    while (c_node != nullptr)
    {
        node<T> *new_node = create_node(c_node->val);
        if (root_ == nullptr)
        {
            root_ = new_node;
            prev_node = root_;
        }
        else
        {
            prev_node->next = new_node;
            prev_node = new_node;
        }
        c_node = c_node->next;
    }
}

#endif // DSA_DS_LLADV_H_
