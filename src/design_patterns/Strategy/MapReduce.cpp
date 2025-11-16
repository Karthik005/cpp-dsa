#include "MapReduce.hpp"

#include <iostream>
#include <vector>

#include "IMapStrategy.hpp"
#include "IReduceStrategy.hpp"
#include "SumReduce.hpp"
#include "SquareMap.hpp"

MapReduce::MapReduce(std::vector<int> data, IMapStrategy *map_strat, IReduceStrategy *red_strat) :
        data_(data), map_strat_(map_strat), red_strat_(red_strat) {}


void 
MapReduce::map() {
    map_strat_->map(data_);
}

int 
MapReduce::reduce() {
    return red_strat_->reduce(data_);
}


int main() {
    IMapStrategy* mymap = new SquareMap();
    IReduceStrategy* myred = new SumReduce();
    MapReduce mpred(std::vector<int>({1,2,3,4}), mymap, myred); 
    mpred.map();
    std::cout << mpred.reduce() << std::endl;
    delete mymap;
    delete myred;
    return 0;
}