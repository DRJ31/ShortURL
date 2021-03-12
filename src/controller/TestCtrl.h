#ifndef SHORTURL_CONTROLLER_TESTCTRL_H
#define SHORTURL_CONTROLLER_TESTCTRL_H

#include "drogon/HttpSimpleController.h"

using namespace drogon;

namespace shorturl {
namespace controller {
class TestCtrl : public drogon::HttpSimpleController<TestCtrl> {
public:
    virtual void asyncHandleHttpRequest(const HttpRequestPtr &req,
                                        std::function<void (const HttpResponsePtr &)>&&callback) override;

    PATH_LIST_BEGIN
    PATH_ADD("/test", Get);
    PATH_LIST_END
};
}
}

#endif //SHORTURL_CONTROLLER_TESTCTRL_H
