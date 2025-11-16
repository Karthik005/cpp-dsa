#include <vector>
#include <iostream>
#include "AbstractSorter.hpp"

template <typename T>
class QuickSorter : public AbstractSorter<T>
{
private:
    bool reverse_;
    int partition(std::vector<T> &src_vec, int left, int right);
    void qsort(std::vector<T> &src_vec, int left, int right);
public: 
    QuickSorter();
    void sort(std::vector<T> &, bool reverse = false);
};

template <typename T>
QuickSorter<T>::QuickSorter()
{
    reverse_ = false;
}

template <typename T>
void QuickSorter<T>::sort(std::vector<T> &src_vec, bool reverse)
{
    reverse_ = reverse;
    qsort(src_vec, 0, src_vec.size()-1);
}

template <typename T>
void QuickSorter<T>::qsort(std::vector<T> &src_vec, int left, int right)
{
    int index = partition(src_vec, left, right);
    if (left < index-1)
        qsort(src_vec, left, index - 1);
    if (right > index)
        qsort(src_vec, index, right);
}

template <typename T>
void swap(std::vector<T> &src_vec, int left, int right) {
    int val = src_vec[left], rval = src_vec[right];

    src_vec[right] = val;
    src_vec[left] = rval;
}

template <typename T>
int QuickSorter<T>::partition(std::vector<T> &src_vec, int left, int right)
{
    int center = (left+right)/2;
    T key = src_vec[center];

    while(left <= right) {
        
        if (reverse_) {
            while (src_vec[left] > key)
                left++;
            while (src_vec[right] < key)
                right--;
        } else {
            while(src_vec[left] < key)
                left++;
            while(src_vec[right] > key)
                right--;
        }

        if (left<=right){
            swap(src_vec, left, right);
            left++;
            right--;
        }

    }
    return left;
}
