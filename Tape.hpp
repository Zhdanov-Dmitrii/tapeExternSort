//
// Created by user on 27.06.23.
//

#ifndef TAPEEXTERNSORT_TAPE_HPP
#define TAPEEXTERNSORT_TAPE_HPP

#include <iostream>
#include <memory>
#include <list>
#include <fstream>

using namespace std;

class Tape {
    string path;

public:
    Tape(string_view path);

    const string& getPath() const;
};


#endif //TAPEEXTERNSORT_TAPE_HPP
