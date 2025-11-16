#ifndef DSA_DS_ARRAYLIST_H_
#define DSA_DS_ARRAYLIST_H_

#include<iostream>
#include <initializer_list>
#include <iostream>

#define NOT_FOUND -1

template<class T>
class ArrayList {
    typedef unsigned int uint;
    
    private:
    T *array_;
    uint size_;
    uint max_size_;

    void resize(const uint& new_size){
        T *temp = array_;
        array_ = new T[new_size];
        uint i = 0;
        for (int iter = 0; iter < size_; ++iter) {
            array_[iter] = temp[iter];
        }
        max_size_ = new_size;
        delete[] temp;
    }


    public:
    ArrayList(): 
        size_{0}, max_size_{1}, array_{new T[1]} {} 
    
    ArrayList(const std::initializer_list<T>& list) {
        size_ = list.size();
        max_size_ = list.size();
        array_ = new T[list.size()];
        // int iter = 0;
        // for()
        }
    
    ArrayList(const ArrayList<T> &list) : 
        size_{list.size()}, max_size_{list.max_size()}, array_{new T[list.max_size()]} {
            for (int i = 0; i < list.size; ++i) {
                array_[i] = list[i];
            }
        }

    void operator=(const ArrayList<T> &list) {
        size_ = list.size();
        max_size_ = list.max_size();
        array_ = new T[list.max_size()];
    }

    uint size() const { return size_;}

    uint max_size() const { return max_size_;}

    T& operator[](const uint& index) {
        return array_[index];
    }

    void push_back(const T& value) {
        if (size_ == max_size_) {
            resize(max_size_*2);
        }
        array_[size_] = value;
        size_++;
    }

    void pop_back() {
        if (size_ == 0) {
            throw std::out_of_range("Size of ArrayList object is 0");
        }
        size--;
        if (size_ == max_size_/2) {
            resize(max_size_/2);
        }
    }

    int search(const T& value) {
        for (int i = 0; i < size_; ++i) {
            if (value == array_[i]) return i;
        }
        return NOT_FOUND;
    }

};

#endif // DSA_DS_ARRAYLIST_H_
