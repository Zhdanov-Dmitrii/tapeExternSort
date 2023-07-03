#include "Tape.hpp"

Tape::Tape(string_view path) : path(path) {

}

const string& Tape::getPath() const {
    return path;
}
