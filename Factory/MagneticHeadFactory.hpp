#ifndef TAPEEXTERNSORT_MAGNETICHEADFACTORY_HPP
#define TAPEEXTERNSORT_MAGNETICHEADFACTORY_HPP

#include "../MagneticHead/MagneticHead.hpp"
#include "../Config/Config.hpp"

class MagneticHeadFactory {
    MagneticHeadFactory();
    MagneticHeadFactory (MagneticHeadFactory&) = delete;
    MagneticHeadFactory& operator= (MagneticHeadFactory&) = delete;

    Config& config;

public:
    static MagneticHeadFactory& getInstance();

    MagneticHead createMagneticHead(const string& path);
};


#endif //TAPEEXTERNSORT_MAGNETICHEADFACTORY_HPP
