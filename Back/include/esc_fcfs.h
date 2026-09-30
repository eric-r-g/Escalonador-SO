#ifndef ESC_FCFS_H
#define ESC_FCFS_H

#include "esc_abstract.h"
#include <algorithm>

class esc_fcfs : esc_abstract {
    public:
    Saida exec_process(vector <Process> processos);
    esc_fcfs();
};

#endif
