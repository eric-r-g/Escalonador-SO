#ifndef ESC_RRSP_H
#define ESC_RRSP_H

#include "esc_abstract.h"
#include <algorithm>
#include <queue>

class esc_rrsp : esc_abstract {
    public:
    Saida exec_process(vector <Process> processos);
    esc_rrsp(int qt);

    private:
    int quantum;
};

#endif