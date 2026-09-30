#ifndef ESC_PSP_H
#define ESC_PSP_H

#include "esc_abstract.h"
#include <algorithm>
#include <queue>

class esc_psp : esc_abstract {
    public:
    Saida exec_process(vector <Process> processos);
    esc_psp();
};

#endif
