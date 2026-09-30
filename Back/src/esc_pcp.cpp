#include "esc_pcp.h"

struct ProcessComparator {
    bool operator()(const Process& a, const Process& b) const {
        if(a.priority != b.priority) 
            return a.priority < b.priority;
        return a.duration > b.duration;
    }
};

Saida esc_pcp::exec_process(vector <Process> processos){
    //  ordena pela ordem de criação e duração
    sort(processos.begin(), processos.end(), [](Process& a, Process& b){
        if(a.creation != b.creation) 
            return a.creation < b.creation;
    });

    int atual = -1, prox = 0, t = 0;
    priority_queue <Process, vector <Process>, ProcessComparator> fila;
    Saida saida;

    // TODO:


    calc_estat(saida);
    return saida;
}

esc_pcp::esc_pcp(){
    id = "esc_pcp";
}