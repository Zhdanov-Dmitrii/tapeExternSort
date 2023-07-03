//
// Created by user on 27.06.23.
//

#include "Config.hpp"

Config::Config() {
    load();
}

Config &Config::getInstance() {
    static Config instance;
    return instance;
}

void Config::load() {
    ifstream fin("config.json");
    if (!fin) {
        return;
    }

    using Json = nlohmann::json;
    Json json =Json::parse(fin);

    readTime = json["readTime"];
    writeTime = json["writeTime"];
    shiftTime = json["shiftTime"];
    rewindTime = json["rewindTime"];
    ramSize = json["ramSize"];
    tmpTapeCount = json["tmpTapeCount"];
}

int Config::getReadTime() {
    return readTime;
}

int Config::getWriteTime() {
    return writeTime;
}

int Config::getShiftTime() {
    return shiftTime;
}

int Config::getRewindTime() {
    return rewindTime;
}

int Config::getRamSize() {
    return ramSize;
}

int Config::getTmpTapeCount() {
    return tmpTapeCount;
}
