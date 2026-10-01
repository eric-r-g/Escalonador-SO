#include "esc_abstract.h"

void esc_abstract::calc_estat(Saida& retorno, vector <Process> &processos){
    retorno.tt = 0, retorno.tw = 0;
    map <int, int> last_time;

    for(Process p : processos)
        last_time[p.id] = p.creation;

    for (Interv inter : retorno.intervalos){
        retorno.tt += inter.fim - inter.ini;
        int ident = inter.id;

        double espera = inter.ini - last_time[ident];
        retorno.tt += espera;
        retorno.tw += espera;

        last_time[ident] = inter.fim;
    }

    int num_process = last_time.size();

    retorno.tt /= num_process;
    retorno.tw /= num_process;
    if(retorno.intervalos.size() != 0) retorno.num_trocas = retorno.intervalos.size() - 1;
    else retorno.num_trocas = 0;
    retorno.id = id;
}
