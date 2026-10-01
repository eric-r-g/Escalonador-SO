#include "../include/esc_rrcp.h"

struct ProcessOn {
    int id;
    int remaining_time;
    int priority;
    int entry_time;

    ProcessOn(int id_, int remaining_time_, int priority_, int entry_time_)
        : id(id_), remaining_time(remaining_time_), priority(priority_), entry_time(entry_time_) {}
};

struct ProcessComparator {
    int ag;
    ProcessComparator (int aging) : ag(aging) {}

    bool operator()(const ProcessOn& a, const ProcessOn& b) const {
        int dap = a.priority - ag * (a.entry_time);
        int dbp = b.priority - ag * (b.entry_time);
        if(dap != dbp) 
            return dap < dbp;
        return a.remaining_time > b.remaining_time;
    }
};

Saida esc_rrcp::exec_process(vector <Process> processos){
    sort(processos.begin(), processos.end(), [](const Process& a, const Process& b){
        return a.creation < b.creation;
    });

    int t = 0;

    Saida saida;
    int prox = 0;

    ProcessComparator comp(aging);
    priority_queue <ProcessOn, vector <ProcessOn>, ProcessComparator> fila(comp);
    ProcessOn needPush = {-1, -1, -1, -1};

    //  enquanto faltar algum processo ser incluido e removido na fila continua
    while(prox < processos.size() || !fila.empty() || needPush.id != -1) {
        if(fila.empty() && needPush.id == -1){
            t = max(t, processos[prox].creation);
        }

        //  insere processos que já tem o tempo alcançado
        while(prox < processos.size() && t >= processos[prox].creation){
            Process p = processos[prox];
            prox++;
            fila.emplace(p.id, p.duration, p.priority, t);
        }

        // insere processo que não tinha sido concluido
        if(needPush.id != -1){
            fila.push(needPush);
            needPush = {-1, -1, -1, -1};
        }

        //  olha para o proximo elemento da fila e calcula seu intervalo
        if(!fila.empty()){
            ProcessOn p = fila.top();
            fila.pop();

            Interv i;
            i.id = p.id;
            i.ini = t;
            // é possivel terminar o processo antes do quantum finalizar
            if(p.remaining_time <= quantum){
                i.fim = i.ini + p.remaining_time;
                t = i.fim;
            } 
            // somente uma parte do processo será feito
            else {
                t = i.fim = i.ini + quantum;
                p.remaining_time -= i.fim - i.ini;
                p.entry_time = t;
                needPush = p;
            }
            
            // verificar se pode juntar o intervalo com o anterior
            int sz = saida.intervalos.size();
            if(sz > 0 && saida.intervalos[sz - 1].id == i.id){
                saida.intervalos[sz - 1].fim = i.fim;
            }
            else saida.intervalos.push_back(i);
        }
    }

    calc_estat(saida);
    return saida;
}

esc_rrcp::esc_rrcp(int qt, int ag){
    quantum = qt;
    aging = ag;
    id = "esc_rrcp";
}
