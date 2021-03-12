#include "TestCtrl.h"
#include "funcs/SnowFlake.h"

namespace shorturl {
namespace controller {
void TestCtrl::asyncHandleHttpRequest(const HttpRequestPtr &req,
                                      std::function<void (const HttpResponsePtr &)> &&callback) {
    auto resp = HttpResponse::newHttpResponse();
    auto *snowFlake = new funcs::SnowFlake();
    resp->setStatusCode(k200OK);
    resp->setContentTypeCode(CT_TEXT_HTML);
    resp->setBody(snowFlake->getSnowFlake() + "Hello");
    callback(resp);
}
}
}