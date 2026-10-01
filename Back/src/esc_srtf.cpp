#include "esc_srtf.h"
#include <queue>
#include <iostream>

// TODO: Reorganizar esse código para que essa função fique mais enxuta
// TODO: Testar esse código

Saida esc_srtf::exec_process(vector <Process> processos){
    //  ordena pela ordem de criação e duração, inicialmente
    sort(processos.begin(), processos.end(), [](Process& a, Process& b){
        if(a.creation != b.creation) 
            return a.creation < b.creation;
        return a.duration < b.duration;
    });

    int t = 0;
    int on_execution = -1; // id do processo em execução
    int remaining = -1;    // tempo restante para o processo em execução ser concluído
    int last_switch = -1;
    bool may_switch = false;
    int finished = 0;      // quantidade de processos que já foram finalizados
    int pos = 0;           // posição atual na lista de processos
    // fila de prioridade que guarda o próximo processo a ser executado no topo
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    Saida saida;

    saida.id = "esc_srtf";
    
    while (finished < processos.size()) {
        if (on_execution != -1) {
            remaining--;
            if (remaining == 0) {
                Interv i;
                i.ini = last_switch;
                i.fim = t;
                i.id = on_execution;
                saida.intervalos.push_back(i);

                finished++;
                may_switch = true;
                on_execution = -1;
            }
        }

        while (pos < processos.size()-1 && processos[pos+1].creation == t) {
            pos++;
            pq.emplace(processos[pos].duration, processos[pos].id);
            may_switch = true;
        }

        if (may_switch && !pq.empty()) {
            auto[r, id] = pq.top();
            if (r < remaining) {
                Interv i;
                i.ini = last_switch;
                i.fim = t;
                i.id = on_execution;
                saida.intervalos.push_back(i);

                pq.emplace(remaining, on_execution);

                pq.pop();
                last_switch = t;
                on_execution = id;
                remaining = r;
            }
            may_switch = false;
        }
        t++;
        std::cout << finished << std::endl;
    }

    calc_estat(saida);
    return saida;
}

esc_srtf::esc_srtf(){
    id = "esc_srtf";
}
