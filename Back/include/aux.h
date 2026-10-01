#ifndef AUX_H
#define AUX_H

#include <map>
#include <vector>
#include <string>

using namespace std;

struct Interv {
    int id;
    int ini, fim;

    Interv() {}

    Interv(int id_, int ini_, int fim_)
        : id(id_), ini(ini_), fim(fim_) {}
};

// TODO: ver alguma forma melhor para saida;
struct Saida {
    vector <Interv> intervalos;
    string id;
    
    double tt;
    double tw;
    double num_trocas;
};

struct Config {
    int quantum;
    int aging;
};

struct Process {
    int id;
    int creation;
    int duration;
    int priority;
};

#endif
