cmake_minimum_required(VERSION 3.13)
project(InstrumentToStringedInstruments)

set(CMAKE_CXX_STANDARD 14)

add_executable(InstrumentToStringedInstruments main.cpp Instrument.cpp Instrument.h StringedInstrument.cpp StringedInstrument.h ElectricGuitar.cpp ElectricGuitar.h Violin.cpp Violin.h BassGuitar.cpp BassGuitar.h)