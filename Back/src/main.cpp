#include "InputReader.h"
#include "httplib.h"

int main() {
    //InputReader ir;
    //Config config = ir.readConfig();
    //std::vector<Process> processes = ir.readProcesses();

    httplib::Server svr;

    // TODO: Colocar esses endpoints dentro de alguma(s) classe(s)
    svr.Put("/config", [](const httplib::Request &req, httplib::Response &res) {
            string config = req.body;
            ofstream configFile("config.txt");
            configFile << config;
            configFile.close();

            // TODO: Fazer uma checagem de validez do arquivo de configuração
            // antes de aceitá-lo como válido
            res.status = 201;
            res.set_content("Configurações definidas", "text/plain");
    });

    svr.Post("/procs", [](const httplib::Request &req, httplib::Response &res) {
            string procsDesc = req.body;
    });

    if (!svr.bind_to_port("0.0.0.0", 8080)) {
        std::cerr << "Falha ao tentar abrir uma conexão na porta 8080" << std::endl;
    }

    std::cout << "Servidor ouvindo na porta 8080" << std::endl;

    svr.listen_after_bind();

    return 0;
}
