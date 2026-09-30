#ifndef ESC_RRCP_H
#define ESC_RRCP_H

#include "esc_abstract.h"
#include <algorithm>
#include <queue>

class esc_rrcp : esc_abstract {
    public:
    Saida exec_process(vector <Process> processos);
    esc_rrcp(int qt, int ag);

    private:
    int quantum;
    int aging;
};

#endif