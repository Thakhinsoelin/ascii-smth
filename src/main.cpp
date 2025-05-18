#include <iostream>
#include "crow.h"
#include <fmt/core.h>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/exception/exception.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>

int main()
{
    try
    {
        // Create an instance.
        mongocxx::instance inst{};
        std::string uri = std::string("mongodb+srv://") +
                  std::getenv("MONGO_USER") + ":" +
                  std::getenv("MONGO_PASS") +
                  "@clustertest.ve5jeta.mongodb.net/?retryWrites=true&w=majority&appName=clusterTest";

        const auto uri_obj = mongocxx::uri{uri};
        // Set the version of the Stable API on the client
        mongocxx::options::client client_options;
        const auto api = mongocxx::options::server_api{mongocxx::options::server_api::version::k_version_1};
        client_options.server_api_opts(api);
        // Setup the connection and get a handle on the "admin" database.
        mongocxx::client conn{ uri_obj, client_options };
        mongocxx::database db = conn["ascii"];
        // Ping the database.
        const auto ping_cmd = bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("ping", 1));
        db.run_command(ping_cmd.view());
        std::cout << "Pinged your deployment. You successfully connected to MongoDB!" << std::endl;

        // Insert a collection with 2 names and 2 ages
        mongocxx::collection people = db["people"];
        bsoncxx::builder::basic::document doc1, doc2;
        doc1.append(bsoncxx::builder::basic::kvp("name", "Alice"));
        doc1.append(bsoncxx::builder::basic::kvp("age", 30));
        doc2.append(bsoncxx::builder::basic::kvp("name", "Bob"));
        doc2.append(bsoncxx::builder::basic::kvp("age", 25));
        std::vector<bsoncxx::document::value> docs;
        docs.push_back(doc1.extract());
        docs.push_back(doc2.extract());
        auto result = people.insert_many(docs);
        if (result) {
            std::cout << "Inserted documents into 'people' collection." << std::endl;
        }

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