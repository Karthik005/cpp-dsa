#include <vector>
#include <iostream>
#include "AbstractSorter.hpp"

template <typename T>
class BubbleSorter : public AbstractSorter<T>
{
private:
public:
    BubbleSorter();
    void sort(std::vector<T> &, bool reverse = false);
};

template <typename T>
BubbleSorter<T>::BubbleSorter()
{
}

template <typename T>
void BubbleSorter<T>::sort(std::vector<T> &src_vec, bool reverse)
{
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 1; i < src_vec.size(); i++)
        {
            int val = src_vec[i];
            int prev_val = src_vec[i-1];
            if ((!reverse && val < prev_val) ||
                (reverse && val > prev_val)) {
                    src_vec[i] = prev_val;
                    src_vec[i-1] = val;
                    swapped = true;
                }
        }
        
    } while (swapped);

}
