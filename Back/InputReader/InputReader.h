#ifndef INPUT_READER_H
#define INPUT_READER_H

#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <vector>

// TODO: Mover essas declarações de struct para um lugar mais adequado
struct Config {
    int quantum;
    int aging;
};

struct Process {
    int creation;
    int duration;
    int priority;
};

class InputReader {
    public:
        std::vector<Process> readProcesses();
        Config readConfig();
};

#endif
