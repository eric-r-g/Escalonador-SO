#include "esc_fcfs.h"

Saida esc_fcfs::exec_process(vector <Process> processos){
    sort(processos.begin(), processos.end(), [](Process& a, Process& b){
        if(a.creation != b.creation) 
            return a.creation < b.creation;
        return a.duration < b.duration;
    });

    int t = 0, cont = 0;
    Saida saida;
    for(Process p : processos){
        Interv i;
        i.ini = max(t, p.creation);
        i.fim = i.ini + p.duration;
        t = i.fim;
        i.id = p.id;
        saida.intervalos.push_back(i);
    }

    calc_estat(saida);
    return saida;
}