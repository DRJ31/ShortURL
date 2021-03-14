#include "drogon/HttpAppFramework.h"
#include "controller/controller.h"
#include "config.h"


int main() {
    drogon::app().loadConfigFile(CONFIG_PATH);
    drogon::app().run();
    return 0;
}