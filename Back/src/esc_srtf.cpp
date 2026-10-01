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

    Saida saida;
    saida.id = "esc_srtf";

    int t = 0;
    int on_execution = -1;
    int remaining = -1;
    int last_switch = -1;
    bool may_switch = false;
    int finished = 0;
    int pos = -1; // começa em -1 para incluir processos[0]

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

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
                remaining = -1; // importante
            }
        }

        // insere todos os processos que chegaram até o tempo t
        while (pos + 1 < processos.size() && processos[pos+1].creation <= t) {
            pos++;
            pq.emplace(processos[pos].duration, processos[pos].id);
            may_switch = true;
        }

        if (may_switch && !pq.empty()) {
            auto [r, id] = pq.top();

            // Se não há processo executando, pega qualquer um.
            // Se há, só troca se o novo tiver menor duração restante.
            if (on_execution == -1 || r < remaining) {
                if (on_execution != -1) {
                    Interv i;
                    i.ini = last_switch;
                    i.fim = t;
                    i.id = on_execution;
                    saida.intervalos.push_back(i);

                    pq.emplace(remaining, on_execution);
                }

                pq.pop();
                last_switch = t;
                on_execution = id;
                remaining = r;
            }
            may_switch = false;
        }

        t++;
    }

    calc_estat(saida);
    return saida;
}

esc_srtf::esc_srtf(){
    id = "esc_srtf";
}
