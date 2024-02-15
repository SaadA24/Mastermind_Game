cmake_minimum_required(VERSION 3.28) # version can be different

project(Mastermind_Game) #name of your project

enable_testing() #to  discover tests in test explorer 

add_subdirectory(googletest) # add googletest subdirectory.

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

add_executable(getComputerStartSequence tests/getComputerCodemakerStartSequenceTest.cpp) # add this executable

target_link_libraries(getComputerStartSequence PRIVATE gtest) # link google test to this executable

include(GoogleTest)
gtest_discover_tests(getComputerStartSequence) # discovers tests by asking the compiled test executable to enumerate its tests