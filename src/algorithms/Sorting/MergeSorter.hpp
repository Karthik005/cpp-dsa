#include<vector>
#include<iostream>
#include "AbstractSorter.hpp"

template <typename T>
class MergeSorter : public AbstractSorter<T>
{
private:
    void merge(std::vector<T> &src_vec, int low, int mid, int high, bool reverse);
    void mergeSort(std::vector<T> &src_vec, int low, int high, bool reverse);

public:
    MergeSorter(/* args */);
    void sort(std::vector<T> &src_vec, bool reverse = false);
};

template<typename T>
MergeSorter<T>::MergeSorter(/* args */)
{
}

template<typename T>
void MergeSorter<T>::sort(std::vector<T>& src_vec, bool reverse)
{
    std::vector<int>& src_vec_ref = src_vec;
    mergeSort(src_vec_ref, 0, src_vec.size()-1, reverse);
    return;
}

template<typename T>
void MergeSorter<T>::merge(std::vector<T>& src_vec, int low, int mid, int high, bool reverse)
{
    
    T low_arr[mid-low+1];
    T hi_arr[high-mid];
    int l_in = 0, h_in = 0;
    //copy low and high
    for(int i = 0; i < mid-low+1; i++)
    {
        low_arr[i] = src_vec[low+i];
    }
    
    for(int i = 0; i < high-mid; i++)
    {
        hi_arr[i] = src_vec[mid+i+1];
    }
    

    for(int i = low; i <= high; i++)
    {
        if ((((!reverse && low_arr[l_in] <= hi_arr[h_in]) ||
             ( reverse && low_arr[l_in] >= hi_arr[h_in]))
             || h_in > high-mid-1)
             && l_in < mid-low+1) {
            src_vec[i] = low_arr[l_in];
            l_in++;
        }
        else {
            src_vec[i] = hi_arr[h_in];
            h_in++;
        }

    }

}

template<typename T>
void MergeSorter<T>::mergeSort(std::vector<T>& src_vec, int low, int high, bool reverse)
{
    if (low == high){
        return;
    }
    int mid = ((high+low) / 2);
    mergeSort(src_vec, low, mid, reverse);
    mergeSort(src_vec, mid+1, high, reverse);
    merge(src_vec, low, mid, high, reverse);
    return;
}
