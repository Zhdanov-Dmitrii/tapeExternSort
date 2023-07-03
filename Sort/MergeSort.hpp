#ifndef TAPEEXTERNSORT_MERGESORT_HPP
#define TAPEEXTERNSORT_MERGESORT_HPP

#include <memory>
#include <algorithm>

#include "../Config/Config.hpp"
#include "../Tape.hpp"
#include "../MagneticHead/IMagneticHead.hpp"
#include "../Factory/MagneticHeadFactory.hpp"
#include "ISort.hpp"

using namespace std;

class MergeSort : public ISort {
    MagneticHeadFactory& magneticHeadFactory;
    size_t m;
    vector<int32_t> ram;

    vector<shared_ptr<IMagneticHead>> magneticHeads;

    void preSorting(const shared_ptr<IMagneticHead>& reader);
    void partition(const shared_ptr<IMagneticHead>& read, size_t partSize);
    void merge(const shared_ptr<IMagneticHead>& write, size_t partSize);

public:
    MergeSort(size_t m, size_t countHead);
    void operator()(const shared_ptr<IMagneticHead>& input, const shared_ptr<IMagneticHead>& output) override;

};


#endif //TAPEEXTERNSORT_MERGESORT_HPP
