#include "../include/esc_sjf.h"

Saida esc_sjf::exec_process(vector <Process> processos){
    //  ordena pela duração
    sort(processos.begin(), processos.end(), [](Process& a, Process& b){
        return a.duration < b.duration;
    });

    //  como o vetor já está ordenado, basta percorrer o vetor atualizando os valores
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

esc_sjf::esc_sjf(){
    id = "esc_sjf";
}
