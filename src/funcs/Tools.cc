#include "Tools.h"
#include <cstdio>
#include <fstream>

namespace shorturl {
namespace funcs {
namespace Tools {
std::string getDbInfo(const std::string& fileName) {
    std::ifstream is;
    Json::Value root;
    Json::Reader reader;
    std::string host, port, dbname, user, passwd;
    char result[BUFSIZE];
    const char* format = "host=%s port=%s dbname=%s user=%s password=%s";

    is.open(fileName, std::ios::binary);
    if (reader.parse(is, root)) {
        if (!root["db_clients"].isNull()) {
            if (!root["db_clients"][0].isNull()) {
                host = root["db_clients"][0]["host"].asString();
                port = root["db_clients"][0]["port"].asString();
                dbname = root["db_clients"][0]["dbname"].asString();
                user = root["db_clients"][0]["user"].asString();
                passwd = root["db_clients"][0]["passwd"].asString();
                std::sprintf(result, format, host.data(), port.data(), dbname.data(), user.data(), passwd.data());
                return result;
            }
        }
    }
    return "";
}
}
}
}