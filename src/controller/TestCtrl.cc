#include "TestCtrl.h"
#include "funcs/SnowFlake.h"
#include "funcs/BaseConvert.h"

namespace shorturl {
namespace controller {
void TestCtrl::asyncHandleHttpRequest(const HttpRequestPtr &req,
                                      std::function<void (const HttpResponsePtr &)> &&callback) {
    auto resp = HttpResponse::newHttpResponse();
    auto *snowFlake = new funcs::SnowFlake(0, 0);
    resp->setStatusCode(k200OK);
    resp->setContentTypeCode(CT_TEXT_HTML);
    resp->setBody(funcs::BaseConvert<long>::decToBase62(snowFlake->nextId()));
    callback(resp);
}
}
}