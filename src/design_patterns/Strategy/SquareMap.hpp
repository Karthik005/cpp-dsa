#ifndef CPP_DSA_DESIGNPAT_STRAT_SQUAREMAP_H_
#define CPP_DSA_DESIGNPAT_STRAT_SQUAREMAP_H_

#include <vector>

#include "IMapStrategy.hpp"

class SquareMap : public IMapStrategy {
public:
    void map(std::vector<int> &data);
};

#endif // CPP_DSA_DESIGNPAT_STRAT_SQUAREMAP_H_