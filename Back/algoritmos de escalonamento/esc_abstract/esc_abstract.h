#ifndef ESC_ABSTRACT_H
#define ESC_ABSTRACT_H

#include "../../aux.h"
#include <map>
#include <string>

class esc_abstract{
    public:
    virtual Saida exec_process(vector <Process> processos) = 0;
    void calc_estat(Saida& retorno);
};

#endif