#include "esc_abstract.h"

void esc_abstract::calc_estat(Saida& retorno){
    retorno.tt = 0, retorno.tw = 0;
    map <int, int> last_time;

    for (Interv inter : retorno.intervalos){
        retorno.tt += inter.fim - inter.ini;
        int id = inter.id;

        if(last_time.count(id) > 0){
            double espera = inter.ini - last_time[id];
            retorno.tt += espera;
            retorno.tw += espera;
        }

        last_time[id] = inter.fim;
    }

    int num_process = last_time.size();

    retorno.tt /= num_process;
    retorno.tw /= num_process;
    retorno.num_trocas = retorno.intervalos.size() - 1;
}