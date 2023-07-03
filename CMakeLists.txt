cmake_minimum_required(VERSION 3.25)
project(tapeExternSort)

set(CMAKE_CXX_STANDARD 17)

add_executable(tapeExternSort main.cpp Tape.hpp MagneticHead/IMagneticHead.hpp MagneticHead/MagneticHead.cpp MagneticHead/MagneticHead.hpp Factory/MagneticHeadFactory.cpp Factory/MagneticHeadFactory.hpp Config/Config.cpp Config/Config.hpp Sort/MergeSort.cpp Sort/MergeSort.hpp Tape.cpp Sort/ISort.hpp Sort/ShackerSort.cpp Sort/ShackerSort.hpp Sort/SortManager.cpp Sort/SortManager.hpp)
