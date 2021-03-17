#include "GetUrlController.h"
#include <cstdio>
#include <map>
#include "drogon/HttpAppFramework.h"
#include "funcs/SnowFlake.h"
#include "funcs/BaseConvert.h"
#include "funcs/Tools.h"
#include "config.h"

namespace shorturl {
namespace controller {
void GetUrlController::asyncHandleHttpRequest(const HttpRequestPtr& req,
                                              std::function<void (const HttpResponsePtr &)> &&callback) {
    const std::string host = req->getHeader("host");
    const std::string SCHEME = funcs::Tools::getScheme(CONFIG_PATH);

    int returnCode = 0;
    auto* parser = new MultiPartParser();
    Json::Value ret;

    if (parser->parse(req) == 0) {
        auto params = parser->getParameters();
        std::map<std::string, std::string>::iterator iter;
        for (iter = params.begin(); iter != params.end(); iter++) {
            if (iter->first == "longUrl") {
                returnCode = 1;
                std::string url = funcs::BaseConvert::base64Decode(iter->second);
                ret["ShortUrl"] = SCHEME + host + "/" + getShortUrl(url);
                break;
            }
        }
        if (!returnCode) {
            ret["Message"] = "Invalid Request!";
        }
    }
    else {
        ret["Message"] = "Invalid Request!";
    }

    ret["Code"] = returnCode;
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    resp->addHeader("Access-Control-Allow-Origin", "*");
    callback(resp);
}

std::string GetUrlController::getShortUrl(const std::string& url) {
    const char* queryFormat = "SELECT * FROM shorturl WHERE url='%s'";
    const char* insertFormat = "INSERT INTO shorturl (abbreviation,url) VALUES ('%s','%s')";
    char querySql[BUFSIZE], insertSql[BUFSIZE];

    auto clientPtr = funcs::Tools::getDbClient(CONFIG_PATH, DB_THREADS);
    if (!clientPtr)
        return "";
    std::sprintf(querySql, queryFormat, url.data());
    auto result = clientPtr->execSqlSync(querySql);

    if (result.empty()) {
        auto* snowFlake = new funcs::SnowFlake(0, 0);
        std::string shortUrl = funcs::BaseConvert::decToBase62(snowFlake->nextId());
        std::sprintf(insertSql, insertFormat, shortUrl.data(), url.data());
        clientPtr->execSqlSync(insertSql);
        return shortUrl;
    }

    return result.at(0).at("abbreviation").as<std::string>();
}
}
}