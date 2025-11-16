#ifndef DSA_DS_QUEUE_H_
#define DSA_DS_QUEUE_H_

#include<vector>
#include<stdexcept>
#include<iostream>


template<class T>
class Queue{
    private:
    std::vector<T> que_;
    int start_ind_;
    int end_ind_;

    public:
    Queue(int max_size) : 
    que_{std::vector<T>(max_size)}, start_ind_{-1}, end_ind_{-1} {}

    Queue(const Queue<T> &cque) : 
    que_{std::vector<T>(cque.max_size())}, start_ind_{-1}, end_ind_{cque.size()-1} {
        for(int i=0; i<cque.size(); ++i) {
            que_[i] = cque[i];
        }
    }

    void operator=(const Queue<T> &cque) {
        que_ = std::vector<T>(cque.max_size());
        start_ind_ = -1;
        end_ind_ = cque.size() - 1;
        for (int i = 0; i < cque.size(); ++i)
        {
            que_[i] = cque[i];
        }
    }

    int size() const { return (end_ind_ - start_ind_) % que_.size(); }
    
    int max_size() const { return que_.size(); }

    T peek() const { return que_[start_ind_]; }

    void enqueue(T value) {
        
        if (start_ind_ == ((end_ind_+1) % max_size())) {
            throw std::overflow_error("Queue Overflow");
        }

        if (start_ind_ == -1 && end_ind_ == -1) {
            start_ind_ = 0;
        }

        end_ind_++;
        end_ind_%=max_size();
        que_[end_ind_] = value;

    }

    void dequeue() {

        if (start_ind_ == -1) { throw std::underflow_error("Empty Queue");}


        if (start_ind_ == end_ind_) start_ind_ = end_ind_ = -1;
        else {
            start_ind_++;
            start_ind_%=max_size();
        }
    }
    
    T& operator[](int index) {
        if (index >= size() || index < 0 ) throw  std::out_of_range();
        index = (start_ind_+index) % size();
        return que_[index];
    }

};

#endif // DSA_DS_QUEUE_H_
