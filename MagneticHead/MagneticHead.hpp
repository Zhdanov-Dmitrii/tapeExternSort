#ifndef TAPEEXTERNSORT_MAGNETICHEAD_HPP
#define TAPEEXTERNSORT_MAGNETICHEAD_HPP

#include "IMagneticHead.hpp"

class MagneticHead: public IMagneticHead {
    fstream data;
    Tape tape;

    int readTime;
    int writeTime;
    int shiftTime;
    int rewindTime;

    int timePrevOperation;
public:
    MagneticHead(int readTime, int writeTime, int shiftTime, int rewindTime, Tape& tape);
    int32_t read() override;
    void write(int32_t val) override;
    void leftShift() override;
    void rightShift() override;
    void rewind() override;
    bool isStart() override;
    bool isEnd() override;
    vector<int32_t> readBlock(size_t size) override;
    void writeBlock(const vector<int32_t>& vec) override;
    void clear() override;
    size_t getSize() override;

    void openFile();
};


#endif //TAPEEXTERNSORT_MAGNETICHEAD_HPP
