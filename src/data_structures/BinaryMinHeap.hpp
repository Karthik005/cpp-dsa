#ifndef DSA_DS_BINMINHEAP_H_
#define DSA_DS_BINMINHEAP_H_

#include<stdexcept>

using namespace std;

template<class T>
class BinaryMinHeap {
    private:
    T * heap_arr_;
    int max_size_;
    int size_;

    int get_parent(int index) {
        return (index-1)/2;
    }

    int get_left(int index) {
        return (index*2)+1;
    }

    int get_right(int index) {
        return (index*2) + 2;
    }

    void swap(int ind1, int ind2) {
        T temp = heap_arr_[ind1];
        heap_arr_[ind1] = heap_arr_[ind2];
        heap_arr_[ind2] = temp;
    }

    int get_min_index(int l_ind, int r_ind) {
        if (r_ind == size_) return l_ind;
        return (heap_arr_[l_ind] <= heap_arr_[r_ind]) ? l_ind : r_ind;
    }

    void heapify(int root_ind) {
        int left_ch = get_left(root_ind);
        int right_ch = get_right(root_ind);
        if (left_ch >= size_) return;

        int min_ind = get_min_index(left_ch, right_ch);
        if (heap_arr_[min_ind] < heap_arr_[root_ind]){
            swap(min_ind, root_ind);
            heapify(min_ind);
        } else {
            return;
        }
    }


    public:
    BinaryMinHeap(int size) {
        heap_arr_ = new T[size];
        size_ = 0;
        max_size_ = size;
    }

    T extract_min() {
        if (size_ <= 0) {
            throw underflow_error("Empty Heap");
        }

        T value = heap_arr_[0];
        heap_arr_[0] = heap_arr_[size_-1];
        size_--;
        heapify(0);
        return value;
    }

    void insert(T value) {
        if (size_ == max_size_) throw overflow_error("Heap is full");
        heap_arr_[size_] = value;
        size_++;
        
        int i = size_-1;
        while(i != 0 && heap_arr_[get_parent(i)] > heap_arr_[i]) {
            swap(i, get_parent(i));
            i = get_parent(i);
        }

    }

};

#endif // DSA_DS_BINMINHEAP_H_
