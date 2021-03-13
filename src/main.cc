#include "drogon/HttpAppFramework.h"
#include "controller/GetUrlController.h"


int main() {
    drogon::app().loadConfigFile("./config.json");
    drogon::app().run();
    return 0;
}