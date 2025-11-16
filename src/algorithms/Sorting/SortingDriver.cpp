#include "AbstractSorter.hpp"
#include "InsertionSorter.hpp"
#include "MergeSorter.hpp"
#include "QuickSorter.hpp"
#include "BubbleSorter.hpp"
#include <stdlib.h>
#include <vector>
#include <iostream>

void printSortedVec(const char* prepend, const std::vector<int>& sorted_vec){
    std::cout << prepend;
    for (size_t i = 0; i < sorted_vec.size(); i++)
    {
        std::cout << sorted_vec[i] << " ";
    }
    std::cout << std::endl;
}


main(int argc, char const *argv[])
{
    std::vector<int> src_vec(atoi(argv[1]));
    AbstractSorter<int> *sorterm = new QuickSorter<int>;

    for(size_t i = 0; i < src_vec.size(); i++)
    {
        src_vec[i] = atoi(argv[2+i]);
    }

    std::vector<int> src_vec_rev(src_vec);

    sorterm->sort(src_vec);
    printSortedVec("Sorted:", src_vec);
    
    sorterm->sort(src_vec_rev, true);
    printSortedVec("Sorted rev:", src_vec_rev);

    return 0;
}

