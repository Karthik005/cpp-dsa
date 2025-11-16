#ifndef CPP_DSA_DESIGNPAT_STRAT_DUCK_H_
#define CPP_DSA_DESIGNPAT_STRAT_DUCK_H_

#include <vector>

#include "IMapStrategy.hpp"
#include "IReduceStrategy.hpp"

class MapReduce{
public:
    
    MapReduce(std::vector<int> data, IMapStrategy* map_strat, IReduceStrategy* red_strat);
    void map();
    int reduce();

    
private:
    std::vector<int> data_;
    IMapStrategy* map_strat_;
    IReduceStrategy* red_strat_;
};

#endif // CPP_DSA_DESIGNPAT_STRAT_DUCK_H_