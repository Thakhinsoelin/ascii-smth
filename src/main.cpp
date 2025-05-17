#include "crow.h"
#include <fmt/core.h>
int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Hello, Crow!";
    });
    CROW_ROUTE(app, "/json")([](){
        crow::json::wvalue x;
        x["hello"] = "world";
        return x;
    });
    app.port(18080).multithreaded().run();
    return 0;
}