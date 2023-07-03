#include <iostream>
#include <string>
#include <memory>
#include "MagneticHead/IMagneticHead.hpp"
#include "Factory/MagneticHeadFactory.hpp"
#include "Sort/MergeSort.hpp"
#include "Sort/SortManager.hpp"

using namespace std;

int main() {
    string inputPath, outputPath;
    cin >> inputPath >> outputPath;

    MagneticHeadFactory& factory = MagneticHeadFactory::getInstance();
    SortManager& sortManager = SortManager::getInstance();

    shared_ptr<IMagneticHead> input = make_shared<MagneticHead>(factory.createMagneticHead(inputPath));
    shared_ptr<IMagneticHead> output = make_shared<MagneticHead>(factory.createMagneticHead(outputPath));

    sortManager.sort(input, output);

    return 0;
}
