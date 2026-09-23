#ifndef INPUT_READER_H
#define INPUT_READER_H

#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <vector>
#include "../aux.h"
// TODO: Mover essas declarações de struct para um lugar mais adequado

class InputReader {
    public:
        std::vector<Process> readProcesses();
        Config readConfig();
};

#endif
