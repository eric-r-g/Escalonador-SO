#include "InputReader.h"

int main() {
    InputReader ir;
    Config config = ir.readConfig();
    std::vector<Process> processes = ir.readProcesses();
    std::cout << "quantum: " << config.quantum << ", aging: " << config.aging << std::endl;
    for (Process p : processes) {
        std::cout << p.creation << ", " << p.duration << ", " << p.priority << std::endl;
    }
    return 0;
}
