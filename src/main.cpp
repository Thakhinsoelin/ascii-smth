#include "crow.h"
#include <fmt/core.h>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/exception/exception.hpp>


int main()
{
    try
    {
        // Create an instance.
        mongocxx::instance inst{};
        const auto uri = mongocxx::uri{"mongodb+srv://<db_username>:<db_password>@clustertest.ve5jeta.mongodb.net/?retryWrites=true&w=majority&appName=clusterTest"};
        // Set the version of the Stable API on the client
        mongocxx::options::client client_options;
        const auto api = mongocxx::options::server_api{mongocxx::options::server_api::version::k_version_1};
        client_options.server_api_opts(api);
        // Setup the connection and get a handle on the "admin" database.
        mongocxx::client conn{ uri, client_options };
        mongocxx::database db = conn["admin"];
        // Ping the database.
        const auto ping_cmd = bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("ping", 1));
        db.run_command(ping_cmd.view());
        std::cout << "Pinged your deployment. You successfully connected to MongoDB!" << std::endl;
        
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
    }
    catch (const mongocxx::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    
    return 0;
}