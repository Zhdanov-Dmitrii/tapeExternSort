//
// Created by user on 01.07.23.
//

#ifndef TAPEEXTERNSORT_SORTMANAGER_HPP
#define TAPEEXTERNSORT_SORTMANAGER_HPP


#include "../Config/Config.hpp"
#include "../MagneticHead/IMagneticHead.hpp"
#include "ISort.hpp"


class SortManager {
    SortManager();
    SortManager(SortManager&) = delete;
    SortManager& operator=(SortManager&) = delete;

    Config& config;


public:
    static SortManager& getInstance();
    void sort(const shared_ptr<IMagneticHead>& input, const shared_ptr<IMagneticHead>& output);
};


#endif //TAPEEXTERNSORT_SORTMANAGER_HPP
