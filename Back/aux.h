#ifndef AUX_H
#define AUX_H

#include <map>
#include <vector>
#include <string>

using namespace std;

// TODO: ver alguma forma melhor para saida;
struct Saida {
    vector <Interv> intervalos;
    string id;
    
    double tt;
    double tw;
    double num_trocas;
};

struct Interv {
    int id;
    int ini, fim;
};

struct Config {
    int quantum;
    int aging;
};

struct Process {
    int creation;
    int duration;
    int priority;
    int id;
};

#endif