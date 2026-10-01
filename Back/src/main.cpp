#include "httplib.h"

#include "esc_abstract.h"
#include "esc_fcfs.h"
#include "esc_pcp.h"
#include "esc_psp.h"
#include "esc_rrsp.h"
#include "esc_rrcp.h"
#include "esc_sjf.h"
#include "esc_srtf.h"
#include "InputReader.h"

int main() {
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
            InputReader ir;

            std::cout << procsDesc << std::endl;

            Config config = ir.readConfig();
            std::vector<Process> processes = ir.readProcesses(procsDesc);

            esc_fcfs fcfs;
            esc_pcp pcp;
            esc_psp psp;
            esc_rrsp rrsp(config.quantum);
            esc_rrcp rrcp(config.quantum, config.aging);
            esc_sjf sjf;
            esc_srtf srtf;
            esc_srtf srtf;

            vector<Saida> saidas;

            saidas.push_back(fcfs.exec_process(processes));
            saidas.push_back(pcp.exec_process(processes));
            saidas.push_back(psp.exec_process(processes));
            saidas.push_back(rrsp.exec_process(processes));
            saidas.push_back(rrcp.exec_process(processes));
            saidas.push_back(sjf.exec_process(processes));
            saidas.push_back(srtf.exec_process(processes));

            std::string json = "";
            json += "[\n";
            for (int i = 0; i < saidas.size(); i++) {
                Saida saida = saidas[i];
                json += "{\n";
                
                json += "\"intervalos\": [\n";

                for (int j = 0; j < saidas[i].intervalos.size(); j++) {
                    auto[iid, iini, ifim] = saidas[i].intervalos[j];
                    json += "{\n";

                    json += "\"id\": " + std::to_string(iid) + ",\n";
                    json += "\"ini\": " + std::to_string(iini) + ",\n";
                    json += "\"fim\": " + std::to_string(ifim) + "\n";

                    json += "}";
                    if (j < saidas[i].intervalos.size()-1) json += ",";
                    json += "\n";
                }

                json += "],\n";


                json += "\"id\": \"" + saida.id + "\",\n";
                json += "\"tt\": " + std::to_string(saida.tt) + ",\n";
                json += "\"tw\": " + std::to_string(saida.tw) + ",\n";
                json += "\"num_trocas\": " + std::to_string(saida.num_trocas) + "\n";

                json += "}";
                if (i < saidas.size()-1) json += ",";
                json += "\n";
            }
            json += "]\n";

            std::cout << json;

            res.status = 201;
            res.set_content(json, "application/json");
    });

    svr.set_post_routing_handler([](const httplib::Request& req, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "POST, PUT, GET, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");
    });

    svr.Options(R"(.*)", [](const auto& req, auto& res) {
        res.status = 204;
    });

    if (!svr.bind_to_port("0.0.0.0", 8080)) {
        std::cerr << "Falha ao tentar abrir uma conexão na porta 8080" << std::endl;
    }

    std::cout << "Servidor ouvindo na porta 8080" << std::endl;

    svr.listen_after_bind();

    return 0;
}
