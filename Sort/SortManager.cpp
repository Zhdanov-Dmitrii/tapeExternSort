//
// Created by user on 01.07.23.
//

#include "SortManager.hpp"
#include "ShackerSort.hpp"
#include "MergeSort.hpp"

SortManager::SortManager() : config(Config::getInstance()) {

}

SortManager &SortManager::getInstance() {
    static SortManager instance;
    return instance;
}

void SortManager::sort(const shared_ptr<IMagneticHead> &input, const shared_ptr<IMagneticHead> &output) {
    shared_ptr<ISort> sort;
    if (config.getTmpTapeCount() < 2)
        sort = make_shared<ShackerSort>(ShackerSort());
    else
        sort = make_shared<MergeSort>(MergeSort(config.getRamSize(), config.getTmpTapeCount()));

    (*sort)(input, output);
}
