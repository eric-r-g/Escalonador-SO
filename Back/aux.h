#ifndef AUX_H
#define AUX_H

#include <map>
#include <vector>
#include <string>

using namespace std;

// TODO: ver alguma forma melhor para saida;
struct saida {
    vector <interv> intervalos;
    string identif;
    double tt;
    double tw;
    double num_trocas;
};

struct interv {
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
};

#endif