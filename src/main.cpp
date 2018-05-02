#include <iostream>

#include "FileReader/FileReader.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::clog << "Knapsack [FILE]" << std::endl;
        return EXIT_FAILURE;
    }

    FileReader input{argv[1]};

    return EXIT_SUCCESS;
}