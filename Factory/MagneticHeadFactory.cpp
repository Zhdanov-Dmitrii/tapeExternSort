//
// Created by user on 27.06.23.
//

#include "MagneticHeadFactory.hpp"

MagneticHeadFactory::MagneticHeadFactory() : config(Config::getInstance()) {

}

MagneticHeadFactory &MagneticHeadFactory::getInstance() {
    static MagneticHeadFactory instance;
    return instance;
}

MagneticHead MagneticHeadFactory::createMagneticHead(const string& path) {
    Tape tape(path);
    MagneticHead res{config.getReadTime(), config.getWriteTime(), config.getShiftTime(), config.getRewindTime(), tape};
    res.openFile();
    return res;
}
