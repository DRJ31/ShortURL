#include "drogon/HttpAppFramework.h"
#include "controller/TestCtrl.h"

using namespace shorturl::controller;

int main() {
    drogon::app().loadConfigFile("../etc/config.json");
    drogon::app().run();
    return 0;
}