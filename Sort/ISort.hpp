//
// Created by user on 01.07.23.
//

#ifndef TAPEEXTERNSORT_ISORT_HPP
#define TAPEEXTERNSORT_ISORT_HPP


#include "../MagneticHead/IMagneticHead.hpp"

class ISort {
public:
    virtual void operator()(const shared_ptr<IMagneticHead>& input, const shared_ptr<IMagneticHead>& output) = 0;
};


#endif //TAPEEXTERNSORT_ISORT_HPP
