#ifndef ESC_FCFS_H
#define ESC_FCFS

#include "../esc_abstract/esc_abstract.h"
#include <algorithm>

class esc_fcfs : esc_abstract {
    public:
    Saida exec_process(vector <Process> processos);
};

#endif