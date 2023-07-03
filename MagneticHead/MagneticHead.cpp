#include "MagneticHead.hpp"

MagneticHead::MagneticHead(int readTime, int writeTime, int shiftTime, int rewindTime, Tape& tape)
    : rewindTime(rewindTime), writeTime(writeTime), shiftTime(shiftTime), readTime(rewindTime), tape(tape) {

}

int32_t MagneticHead::read() {
    int32_t res;
    data.read((char*) &res, sizeof(int32_t));

    //возвращаем на прошлую позицию файловый указатель
    data.seekg(- (int) sizeof(int32_t), ios::cur);
    timePrevOperation = readTime;
    return res;
}

void MagneticHead::write(int32_t val) {
    data.write((char*) &val, sizeof(int32_t));
    data.seekg(- (int) sizeof(int32_t), ios::cur);
    data.flush();
    timePrevOperation = writeTime;
}

void MagneticHead::leftShift() {
    data.seekg(- (int) sizeof(int32_t), ios::cur);
    timePrevOperation = shiftTime;
}

void MagneticHead::rightShift() {
    data.seekg(sizeof(int32_t), ios::cur);
    timePrevOperation = shiftTime;
}

void MagneticHead::rewind() {
    data.clear();
    data.seekg(0, ios::beg);
    timePrevOperation = rewindTime;
}

bool MagneticHead::isStart() {
    return data.tellg() == ios::beg;
}

bool MagneticHead::isEnd() {
    data.get();
    data.seekg(-1, ios::cur);
    return data.fail();
}

vector<int32_t> MagneticHead::readBlock(size_t size) {
    vector<int32_t> res;
    res.reserve(size);
    for (size_t i = 0; i < size; ++i) {
        res.push_back(read());
        rightShift();
    }
    leftShift();

    timePrevOperation = readTime * size;
    return res;
}

void MagneticHead::writeBlock(const vector<int32_t> &vec) {
    for (int32_t i : vec) {
        write(i);
        rightShift();
    }
    leftShift();

    timePrevOperation = writeTime * vec.size();
}

void MagneticHead::openFile() {
    data.open(tape.getPath(), ios::binary|ios::in|ios::out);
    if (!data) {
        data.open(tape.getPath(), ios::out);
        data.close();
        data.open(tape.getPath(), ios::binary|ios::in|ios::out);
    }

    data.seekg (0, ios::end);
    data.seekg(0, std::ios::beg);

}

void MagneticHead::clear() {
    data.close();
    data.open(tape.getPath(), ios::binary|ios::in|ios::out|ios::trunc);
}

size_t MagneticHead::getSize() {
    auto pos = data.tellg();
    data.seekg(0, ios::end);
    auto res = data.tellg() / sizeof(int32_t);
    data.seekg(pos, ios::beg);
    return res;
}
