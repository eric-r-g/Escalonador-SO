#ifndef ESC_PCP_H
#define ESC_PCP_H

#include "esc_abstract.h"
#include <algorithm>
#include <set>

class esc_pcp : esc_abstract {
    public:
    Saida exec_process(vector <Process> processos);
    esc_pcp();
};

#endif
