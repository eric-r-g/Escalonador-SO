#ifndef ESC_SRTF_H
#define ESC_SRTF_H

#include "esc_abstract.h"
#include <algorithm>

class esc_srtf : esc_abstract {
    public:
    Saida exec_process(vector <Process> processos);
    esc_srtf();
};

#endif
