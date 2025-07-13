
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "json.hpp"
#include "httplib.h"

using json = nlohmann::json;

std::map<std::string, std::vector<std::string>> decadeToTracks = {
    {"1960s", {"1960s1.mp3", "1960s2.mp3"}},
    {"1970s", {"1970s1.mp3", "1970s2.mp3"}},
    {"1980s", {"1980s1.mp3", "1980s2.mp3"}},
    {"1990s", {"1990s1.mp3", "1990s2.mp3"}},
    {"2000s", {"2000s1.mp3", "2000s2.mp3"}},
    {"2010s", {"2010s1.mp3", "2010s2.mp3"}}
};

struct RadioPayload {
    std::string decade;
    std::vector<std::string> playlist;
};

json toJSON(const RadioPayload& payload) {
    json j;
    j["decade"] = payload.decade;
    j["playlist"] = payload.playlist;
    return j;
}

RadioPayload generateRadioSession(const std::string& decade) {
    RadioPayload session;
    session.decade = decade;
    session.playlist = decadeToTracks[decade];
    return session;
}

int main() {
    httplib::Server svr;

    svr.Options("/generate", [](const httplib::Request& req, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "POST, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");
        res.status = 204;
    });

    svr.Post("/generate", [](const httplib::Request& req, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");

        try {
            json body_json = json::parse(req.body);
            std::string decade = body_json["decade"];

            RadioPayload session = generateRadioSession(decade);
            json response = toJSON(session);

            res.set_content(response.dump(4), "application/json");
        } catch (const std::exception& e) {
            json error = { {"error", e.what()} };
            res.status = 400;
            res.set_content(error.dump(4), "application/json");
        }
    });

    std::cout << "🚀 C++ backend is running at http://localhost:8080/generate\n";
    svr.listen("0.0.0.0", 8080);
    return 0;
}
