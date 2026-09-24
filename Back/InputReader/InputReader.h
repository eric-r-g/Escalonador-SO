#ifndef INPUT_READER_H
#define INPUT_READER_H

#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <vector>
#include "../aux.h"

class InputReader {
    public:
        std::vector<Process> readProcesses();
        Config readConfig();
};

#endif
