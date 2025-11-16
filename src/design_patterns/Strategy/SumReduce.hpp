#ifndef CPP_DSA_DESIGNPAT_STRAT_SUMREDUCE_H_
#define CPP_DSA_DESIGNPAT_STRAT_SUMREDUCE_H_

#include <vector>

#include "IReduceStrategy.hpp"

class SumReduce : public IReduceStrategy
{
public:
    int reduce(std::vector<int> &data);
};

#endif // CPP_DSA_DESIGNPAT_STRAT_SUMREDUCE_H_