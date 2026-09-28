#include "esc_psp.h"

//  comparador para a fila de prioridade, usando prioridade e duração
struct ProcessComparator {
    bool operator()(const Process& a, const Process& b) const {
        if(a.priority != b.priority) 
            return a.priority < b.priority;
        return a.duration > b.duration;
    }
};

Saida esc_psp::exec_process(vector <Process> processos){
    sort(processos.begin(), processos.end(), [](const Process& a, const Process& b){
        return a.creation < b.creation;
    });

    int prox = 0, t = 0;
    priority_queue <Process, vector <Process>, ProcessComparator> fila;
    Saida saida;

    //  enquanto faltar algum processo ser incluido e removido na fila continua
    while(prox < processos.size() || !fila.empty()) {
        if(fila.empty()){
            t = max(t, processos[prox].creation);
        }

        //  insere processos que já tem o tempo alcançado
        while(prox < processos.size() && t >= processos[prox].creation){
            fila.push(processos[prox]);
            prox++;
        }

        //  olha para o processo elemento da fila e calcula seu intervalo
        if(!fila.empty()){
            Process p = fila.top();
            fila.pop();

            Interv i;
            i.id = p.id;
            i.ini = t;
            t = i.fim = i.ini + p.duration;
            saida.intervalos.push_back(i);
        }
    }

    calc_estat(saida);
    return saida;
}

esc_psp::esc_psp(){
    id = "esc_psp";
}