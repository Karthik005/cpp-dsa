#ifndef CPP_DSA_DESIGNPAT_STRAT_IREDUCESTRATEGY_H_
#define CPP_DSA_DESIGNPAT_STRAT_IREDUCESTRATEGY_H_

#include <vector>

class IReduceStrategy{
public:
    virtual int reduce(std::vector<int> &data) = 0;
};

#endif // CPP_DSA_DESIGNPAT_STRAT_IREDUCESTRATEGY_H_