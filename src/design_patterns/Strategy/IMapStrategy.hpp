#ifndef CPP_DSA_DESIGNPAT_STRAT_IMAPSTRATEGY_H_
#define CPP_DSA_DESIGNPAT_STRAT_IMAPSTRATEGY_H_

#include <vector>

class IMapStrategy {
public:
    virtual void map(std::vector<int> &data) = 0;
};

#endif // CPP_DSA_DESIGNPAT_STRAT_IMAPSTRATEGY_H_
