#include "ShackerSort.hpp"

void ShackerSort::operator()(const shared_ptr<IMagneticHead> &input, const shared_ptr<IMagneticHead> &output) {
    size_t l = 0;
    size_t r = 0;
    while (!input->isEnd()) {
        int32_t val = input->read();
        input->rightShift();

        output->write(val);
        output->rightShift();
        ++r;
    }
    output->rewind();

    bool toRight = true;
    auto shift = [](const shared_ptr<IMagneticHead>& head, bool toRight){
        if (toRight) {
            head->rightShift();
        }
        else {
            head->leftShift();
        }
    };
    auto swap = [&shift](const shared_ptr<IMagneticHead>& head, bool toRight) {
        auto val1 = head->read();
        shift(head, !toRight);
        auto val2 = head->read();
        head->write(val1);
        shift(head, toRight);
        head->write(val2);
    };
    int pos = 0;
    while (l < r) {

        int prev = output->read();
        while ((toRight && pos < r-1) || (!toRight && pos > l+1)) {
            shift(output, toRight);
            auto val = output->read();
            if (toRight) {
                if (prev > val)
                    swap(output, toRight);
            } else {
                if (prev < val)
                    swap(output, toRight);
            }

            prev = val;
            pos += toRight ? 1 : -1;
        }
        if (toRight) --r;
        else ++l;
        toRight = !toRight;
        shift(output, toRight);
    }
}
