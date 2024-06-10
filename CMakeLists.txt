cmake_minimum_required(VERSION 3.26)
project(SRX_Data_To_Wave)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SRX_Data_To_Wave
        BIQUAD.cpp
        BIQUAD.h
        ByteReader.h
        RIAA.cpp
        RIAA.h
        "SRX Data To Wave.cpp")
