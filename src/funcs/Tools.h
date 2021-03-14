#ifndef SHORTURL_FUNCS_TOOLS_H
#define SHORTURL_FUNCS_TOOLS_H

#include <json/json.h>
#include <string>
#include "drogon/HttpAppFramework.h"

#define BUFSIZE 1000

namespace shorturl {
namespace funcs {
namespace Tools {
std::string getDbType(const std::string& fileName);

std::string getDbInfo(const std::string& fileName);

drogon::orm::DbClientPtr getDbClient(const std::string& fileName, int threads);
}
}
}

#endif //SHORTURL_FUNCS_TOOLS_H
