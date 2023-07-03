#ifndef TAPEEXTERNSORT_SHACKERSORT_HPP
#define TAPEEXTERNSORT_SHACKERSORT_HPP


#include "ISort.hpp"

class ShackerSort : public ISort{
public:
    void operator()(const shared_ptr<IMagneticHead>& input, const shared_ptr<IMagneticHead>& output) override;
};


#endif //TAPEEXTERNSORT_SHACKERSORT_HPP
