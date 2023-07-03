//
// Created by user on 27.06.23.
//

#ifndef TAPEEXTERNSORT_CONFIG_HPP
#define TAPEEXTERNSORT_CONFIG_HPP

#include <fstream>
#include "../Utils/json.hpp"

using namespace std;

class Config {
    Config();
    Config(Config&) = delete;
    Config& operator=(Config&) = delete;

    int readTime = 0;
    int writeTime = 0;
    int shiftTime = 0;
    int rewindTime = 0;
    size_t ramSize = 8;
    int tmpTapeCount = 3;
public:
    static Config& getInstance();
    void load();

    int getReadTime();
    int getWriteTime();
    int getShiftTime();
    int getRewindTime();
    int getRamSize();
    int getTmpTapeCount();

};


#endif //TAPEEXTERNSORT_CONFIG_HPP
