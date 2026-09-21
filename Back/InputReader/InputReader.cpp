#include "InputReader.h"

std::vector<Process> InputReader::readProcesses() {
    std::vector<Process> processes;
    int c, d, p;
    while (std::cin >> c >> d >> p) {
        processes.emplace_back(c, d, p);
    }
    return processes;
}

Config InputReader::readConfig() {
    if (!std::filesystem::exists("./config.txt")) {
        std::cout << "Erro: Crie um arquivo de texto nomeado \"config.txt\" com as informações sobre o tamanho do quantum e o fator de envelhecimento a serem utilizados." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    Config config;
    std::ifstream configFile("./config.txt");

    std::string line;
    while (configFile >> line) {
        int twoDotsPos = line.find(":");
        if (twoDotsPos == line.size()) {
            std::cout << "Erro: Arquivo de configuração fora do padrão." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        std::string key = line.substr(0, twoDotsPos);
        // TODO: Verificar se esse valor é realmente um número inteiro antes de tentar convertê-lo
        std::string value = line.substr(twoDotsPos+1, line.size() - twoDotsPos - 1);
        if (key == "quantum") config.quantum = stoi(value);
        else if (key == "aging") config.aging = stoi(value);
        else {
                std::cout << "Erro: Opção inválida passada no arquivo de configuração." << std::endl;
                std::exit(EXIT_FAILURE);
        }
    }

    configFile.close();

    return config;
}
