#ifndef ESC_ABSTRACT_H
#define ESC_ABSTRACT_H

#include "../../aux.h"
#include <map>
#include <string>

class esc_abstract{

    public:
    virtual saida exec_process() = 0;
    void calc_estat(saida& retorno, vector <interv>& intervalos);
};

#endif