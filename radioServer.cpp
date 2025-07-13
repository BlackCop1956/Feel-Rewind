
// DecadeDive C++ Backend with Song Thumbnails and Titles

// DecadeDive C++ Backend with Song Thumbnails, Titles, Fun Facts, and News Snippets

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "json.hpp"
#include "httplib.h"

using json = nlohmann::json;

// Each song includes file, title, and thumbnail
std::map<std::string, std::vector<json>> decadeToTracks = {
    {"1960s", {
        { {"file", "1960s1.mp3"}, {"title", "Aajkal Tere Mere Pyar Ke Charche"}, {"thumbnail", "thumbnails/1960s1.jpg"} },
        { {"file", "1960s2.mp3"}, {"title", "Mere Samnewali Khidki Mein"}, {"thumbnail", "thumbnails/1960s2.jpg"} }
    }},
    {"1970s", {
        { {"file", "1970s1.mp3"}, {"title", "O Mere Dil Ke Chain"}, {"thumbnail", "thumbnails/1970s1.jpg"} },
        { {"file", "1970s2.mp3"}, {"title", "Bahon Mein Chale Aao"}, {"thumbnail", "thumbnails/1970s2.jpg"} }
    }},
    {"1980s", {
        { {"file", "1980s1.mp3"}, {"title", "Mere Rang Mein Rangne"}, {"thumbnail", "thumbnails/1980s1.jpg"} },
        { {"file", "1980s2.mp3"}, {"title", "Neele Neele Ambar Par"}, {"thumbnail", "thumbnails/1980s2.jpg"} }
    }},
    {"1990s", {
        { {"file", "1990s1.mp3"}, {"title", "Tujhe Dekha To"}, {"thumbnail", "thumbnails/1990s1.jpg"} },
        { {"file", "1990s2.mp3"}, {"title", "Tip Tip Barsa Paani"}, {"thumbnail", "thumbnails/1990s2.jpg"} }
    }},
    {"2000s", {
        { {"file", "2000s1.mp3"}, {"title", "Kal Ho Naa Ho"}, {"thumbnail", "thumbnails/2000s1.jpg"} },
        { {"file", "2000s2.mp3"}, {"title", "Tum Se Hi"}, {"thumbnail", "thumbnails/2000s2.jpg"} }
    }},
    {"2010s", {
        { {"file", "2010s1.mp3"}, {"title", "Tum Hi Ho"}, {"thumbnail", "thumbnails/2010s1.jpg"} },
        { {"file", "2010s2.mp3"}, {"title", "Balam Pichkari"}, {"thumbnail", "thumbnails/2010s2.jpg"} }
    }}
};

std::map<std::string, std::string> decadeToFunFact = {
    {"1960s", "India's first satellite Aryabhata was conceptualized."},
    {"1970s", "The Green Revolution transformed Indian agriculture."},
    {"1980s", "Doordarshan launched color TV in India."},
    {"1990s", "India opened its economy to globalization in 1991."},
    {"2000s", "The IT boom reshaped India's global identity."},
    {"2010s", "India launched the Mangalyaan Mars Orbiter in 2013."}
};

std::map<std::string, std::string> decadeToNews = {
    {"1960s", "Lal Bahadur Shastri became PM after Nehru's death."},
    {"1970s", "Emergency was declared in India from 1975-77."},
    {"1980s", "Indira Gandhi was assassinated in 1984."},
    {"1990s", "Pokhran-II nuclear tests were conducted in 1998."},
    {"2000s", "India won the inaugural T20 World Cup in 2007."},
    {"2010s", "Article 370 was abrogated in 2019."}
};

std::map<std::string, json> decadeToInfluential = {
    {"1960s", { {"name", "Dr. Homi Bhabha"}, {"description", "Pioneer of India's nuclear program."}, {"image", "influentials/1960s_bhabha.jpg"} }},
    {"1970s", { {"name", "Verghese Kurien"}, {"description", "Father of the White Revolution."}, {"image", "influentials/1970s_kurien.jpg"} }},
    {"1980s", { {"name", "Amitabh Bachchan"}, {"description", "Cultural icon and film superstar."}, {"image", "influentials/1980s_bachchan.jpg"} }},
    {"1990s", { {"name", "Narayana Murthy"}, {"description", "Infosys founder, changed India's tech scene."}, {"image", "influentials/1990s_murthy.jpg"} }},
    {"2000s", { {"name", "Dr. A.P.J. Abdul Kalam"}, {"description", "President and Missile Man of India."}, {"image", "influentials/2000s_kalam.jpg"} }},
    {"2010s", { {"name", "Virat Kohli"}, {"description", "Led India into a new cricketing era."}, {"image", "influentials/2010s_kohli.jpg"} }}
};

struct RadioPayload {
    std::string decade;
    std::vector<json> playlist;
    std::string funFact;
    std::string news;
    json influential;
};

json toJSON(const RadioPayload& payload) {
    json j;
    j["decade"] = payload.decade;
    j["playlist"] = payload.playlist;
    j["funFact"] = payload.funFact;
    j["news"] = payload.news;
    j["influential"] = payload.influential;
    return j;
}

RadioPayload generateRadioSession(const std::string& decade) {
    RadioPayload session;
    session.decade = decade;
    session.playlist = decadeToTracks[decade];
    session.funFact = decadeToFunFact[decade];
    session.news = decadeToNews[decade];
    session.influential = decadeToInfluential[decade];
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
