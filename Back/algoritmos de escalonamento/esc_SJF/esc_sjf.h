#ifndef ESC_SJF_H
#define ESC_SJF_H

#include "../esc_abstract/esc_abstract.h"
#include <algorithm>

class esc_sjf : esc_abstract {
    public:
    Saida exec_process(vector <Process> processos);
    esc_sjf();
};

#endif
