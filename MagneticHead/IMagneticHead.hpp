#ifndef TAPEEXTERNSORT_IMAGNETICHEAD_HPP
#define TAPEEXTERNSORT_IMAGNETICHEAD_HPP

#include <fstream>
#include <vector>
#include "../Tape.hpp"

using namespace std;

class IMagneticHead {
public:
    virtual int32_t read() = 0;
    virtual void write(int32_t val) = 0;
    virtual void leftShift() = 0;
    virtual void rightShift() = 0;
    virtual void rewind() = 0;
    virtual bool isStart() = 0;
    virtual bool isEnd() = 0;
    virtual vector<int32_t> readBlock(size_t size) = 0;
    virtual void writeBlock(const vector<int32_t>& data) = 0;
    virtual void clear() = 0;
    virtual size_t getSize() = 0;

    virtual ~IMagneticHead() = 0;
};


inline IMagneticHead::~IMagneticHead() {}

#endif //TAPEEXTERNSORT_IMAGNETICHEAD_HPP
