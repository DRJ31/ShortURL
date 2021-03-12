#include "drogon/HttpAppFramework.h"
#include "controller/TestCtrl.h"

using namespace shorturl::controller;

int main() {
    drogon::app().loadConfigFile("./config.json");
    drogon::app().run();
    return 0;
}