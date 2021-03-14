#include "Tools.h"
#include <cstdio>
#include <fstream>

namespace shorturl {
namespace funcs {
namespace Tools {
std::string getDbType(const std::string& fileName) {
    std::ifstream is;
    Json::Value root;
    Json::Reader reader;
    std::string dbType;

    is.open(fileName, std::ios::binary);
    if (reader.parse(is, root)) {
        is.close();
        if (!root["db_clients"].isNull()) {
            if (!root["db_clients"][0].isNull()) {
                dbType = root["db_clients"][0]["rdbms"].asString();
                return dbType;
            }
        }
    }
    is.close();
    return "";
}

std::string getDbInfo(const std::string& fileName) {
    std::ifstream is;
    Json::Value root;
    Json::Reader reader;
    std::string host, port, dbname, user, passwd, filename;
    char result[BUFSIZE];
    const char* format = "host=%s port=%s dbname=%s user=%s password=%s";
    const char* sqliteFormat = "filename=%s";
    const std::string dbType = getDbType(fileName);

    is.open(fileName, std::ios::binary);
    if (reader.parse(is, root)) {
        is.close();
        if (!root["db_clients"].isNull()) {
            if (!root["db_clients"][0].isNull()) {
                if (dbType == "sqlite3") {
                    filename = root["db_clients"][0]["filename"].asString();
                    std::sprintf(result, sqliteFormat, filename.data());
                }
                else {
                    host = root["db_clients"][0]["host"].asString();
                    port = root["db_clients"][0]["port"].asString();
                    dbname = root["db_clients"][0]["dbname"].asString();
                    user = root["db_clients"][0]["user"].asString();
                    passwd = root["db_clients"][0]["passwd"].asString();
                    std::sprintf(result, format, host.data(), port.data(), dbname.data(), user.data(), passwd.data());
                }
                return result;
            }
        }
    }
    is.close();
    return "";
}

drogon::orm::DbClientPtr getDbClient(const std::string& fileName, int threads) {
    const std::string dbType = getDbType(fileName);
    const std::string connInfo = getDbInfo(fileName);

    if (dbType == "mysql") {
        return drogon::orm::DbClient::newMysqlClient(connInfo, threads);
    }
    else if (dbType == "postgresql") {
        return drogon::orm::DbClient::newPgClient(connInfo, threads);
    }
    else if (dbType == "sqlite3") {
        return drogon::orm::DbClient::newSqlite3Client(connInfo, threads);
    }
    return nullptr;
}
}
}
}