#include "MergeSort.hpp"

MergeSort::MergeSort(size_t m, size_t countHead) : magneticHeadFactory(MagneticHeadFactory::getInstance()), m(m) {
    magneticHeads.reserve(countHead);
    for (size_t i = 0; i < countHead; ++i)
        magneticHeads.push_back(make_shared<MagneticHead>(magneticHeadFactory.createMagneticHead("tmp/" + to_string(i) + ".dat")));
}

void MergeSort::operator()(const shared_ptr<IMagneticHead> &input, const shared_ptr<IMagneticHead> &output) {
    preSorting(input);
    size_t partSize = m;
    merge(output, partSize);
    partSize *= magneticHeads.size();
    size_t inputSize = input->getSize();
    for (; partSize < inputSize; partSize *= magneticHeads.size()) {
        partition(output, partSize);
        merge(output, partSize);
    }
}

void MergeSort::preSorting(const shared_ptr<IMagneticHead> &reader) {
    size_t size = reader->getSize();
    size_t partCount = size / m;


    for (size_t i = 0; !reader->isEnd(); ++i) {
        size_t countPartInHead = partCount / magneticHeads.size();
        if (countPartInHead == 0) countPartInHead = 1;
        size_t tapeInd = min(i / (countPartInHead), magneticHeads.size()-1);
        shared_ptr<IMagneticHead> write = magneticHeads[tapeInd];

        size_t sizeBuf = std::min(size, m);
        ram = reader->readBlock(sizeBuf);
        reader->rightShift();
        size -= sizeBuf;

        std::sort(ram.begin(), ram.end());

        write->writeBlock(ram);
        write->rightShift();
    }

    for (auto& head : magneticHeads) {
        head->rewind();
    }
    reader->rewind();
}

void MergeSort::partition(const shared_ptr<IMagneticHead>& reader, size_t partSize) {
    size_t size = reader->getSize();
    size_t partCount = size/ partSize;


    for (size_t i = 0; !reader->isEnd(); ++i) {
        size_t part = i / partSize;
        size_t countPartInHead = partCount / magneticHeads.size();
        if (countPartInHead == 0) countPartInHead = 1;
        size_t headInd = min(part / countPartInHead, magneticHeads.size()-1);
        int32_t val = reader->read();
        magneticHeads[headInd]->write(val);
        magneticHeads[headInd]->rightShift();

        reader->rightShift();
    }

    for (auto& head : magneticHeads) {
        head->rewind();
    }
    reader->rewind();
    reader->clear();
}

void MergeSort::merge(const shared_ptr<IMagneticHead>& writer, size_t partSize) {
    using Pair = pair<size_t, int32_t>;
    vector<size_t> partInd(magneticHeads.size());
    vector<Pair> values;
    values.reserve(magneticHeads.size());

    auto check = [&partSize](const vector<size_t>& partInd, const vector<shared_ptr<IMagneticHead>>& heads){
        for (size_t i = 0; i < heads.size(); ++i)
            if (partInd[i] < partSize && !heads[i]->isEnd())
                return true;

        return false;
    };

    while (check(partInd, magneticHeads)) {
        for (size_t i = 0; i < magneticHeads.size(); ++i)
            if (partInd[i] < partSize && !magneticHeads[i]->isEnd())
                values.emplace_back(i, magneticHeads[i]->read());


        auto &[ind, val] = *std::min_element(values.begin(), values.end(),
                                      [](const Pair& a, const Pair& b) { return a.second < b.second;});

        writer->write(val);
        writer->rightShift();
        magneticHeads[ind]->rightShift();
        ++partInd[ind];
        values.clear();

        if (!check(partInd, magneticHeads))
            partInd = vector<size_t>(magneticHeads.size());

    }

    for (auto& head : magneticHeads) {
        if (!head->isEnd()) {
            writer->write(head->read());
            head->rightShift();
        }
    }

    for (auto& head : magneticHeads) {
        head->rewind();
        head->clear();
    }
    writer->rewind();
}

