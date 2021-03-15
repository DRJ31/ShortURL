#ifndef SHORTURL_CONTROLLER_REDIRECTCONTROLLER_H
#define SHORTURL_CONTROLLER_REDIRECTCONTROLLER_H

#include "drogon/HttpController.h"

#define REGEX "/(?!short|404|css|js|img).{1,}"

using namespace drogon;

namespace shorturl {
namespace controller {
class RedirectController : public drogon::HttpController<RedirectController> {
public:
    METHOD_LIST_BEGIN
        ADD_METHOD_VIA_REGEX(RedirectController::redirect, REGEX, Get);
    METHOD_LIST_END

    void redirect(const HttpRequestPtr& req,
                  std::function<void (const HttpResponsePtr &)> &&callback);

    std::string getFullUrl(const std::string& host, const std::string& shortUrl);

    std::string getAbbreviation(const std::string& path);
};
}
}

#endif //SHORTURL_CONTROLLER_REDIRECTCONTROLLER_H
