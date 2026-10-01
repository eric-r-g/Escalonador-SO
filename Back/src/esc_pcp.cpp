#include "esc_pcp.h"

struct ProcessOnPCP {
    int id;
    int remaining_time;
    int priority;

    ProcessOnPCP(int id_, int remaining_time_, int priority_)
        : id(id_), remaining_time(remaining_time_), priority(priority_) {}

    bool operator <(const ProcessOnPCP& other) const {
        if(priority != other.priority) 
            return priority > other.priority;
        if(remaining_time != other.remaining_time)
            return remaining_time < other.remaining_time;
        return id < other.id;
    }
};

bool atual_is_best(ProcessOnPCP& atual, ProcessOnPCP& other){
    // não existe processo atual ainda
    if (atual.id == -1) return false;

    // a não ser que o novo tenha uma prioridade maior, é melhor manter o atual;
    if (atual.priority != other.priority)
        return atual.priority > other.priority;
    return true;
}


Saida esc_pcp::exec_process(vector <Process> processos){
    //  ordena pela ordem de criação e duração
    sort(processos.begin(), processos.end(), [](Process& a, Process& b){
        return a.creation < b.creation;
    });

    int prox = 0, t = 0;
    ProcessOnPCP atual = {-1, -1, -1};
    set <ProcessOnPCP> fila;
    Saida saida;

    //  enquanto faltar algum processo ser incluido e removido na fila continua
    while(prox < processos.size() || !fila.empty() || atual.id != -1) {
        if(atual.id == -1 && fila.empty()){
            t = max(t, processos[prox].creation);
        }

        //  insere processos que já tem o tempo alcançado
        while(prox < processos.size() && t >= processos[prox].creation){
            Process p = processos[prox];
            prox++;
            fila.emplace(p.id, p.duration, p.priority);
        }

        //  olha para o processo elemento da fila e ver se é melhor que o atual
        if(!fila.empty()){
            ProcessOnPCP p = *fila.begin();
            if(!atual_is_best(atual, p)){
                fila.erase(p);

                if(atual.id != -1)
                    fila.insert(atual);
                atual = p;
            }
        }

        // calcula o intervalo do atual
        if(atual.id != -1){
            Interv i;
            i.id = atual.id;
            i.ini = t;
            // é possivel terminar o processo antes do proximo aparecer
            if(prox == processos.size() || t + atual.remaining_time <= processos[prox].creation){
                i.fim = i.ini + atual.remaining_time;
                t = i.fim;
                atual = {-1, -1, -1};
            } 
            // somente uma parte do processo será feito
            else {
                t = i.fim = processos[prox].creation;
                atual.remaining_time -= i.fim - i.ini;
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

esc_pcp::esc_pcp(){
    id = "esc_pcp";
}
