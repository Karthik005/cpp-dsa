#if !defined(__ABSTRACT_SORTER__)
#define __ABSTRACT_SORTER__

#include <vector>

template<typename T>
class AbstractSorter
{
  private:
    /* data */
  public:
    AbstractSorter(/* args */){};
    virtual void sort(std::vector<T>&, bool reverse=false) = 0;
    ~AbstractSorter(){};
};

#endif // __ABSTRACT_SORTER__



