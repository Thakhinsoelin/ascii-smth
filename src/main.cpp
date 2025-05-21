#include "brainrot.h"
#include <iostream>
#include <crow.h>
#include <string>
#include <fmt/core.h>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/exception/exception.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>

rizz main()
{
    yap mongo_user[100] = "MONGO_USER";
    yap mongo_pass[100] = "MONGO_PASS";
    cook
    {
        // Create an instance.
        minn inst{};
        megayap uri = megayap("mongodb+srv://") +
                  std::getenv("MONGO_USER") + ":" +
                  std::getenv("MONGO_PASS") +
                  "@clustertest.ve5jeta.mongodb.net/?retryWrites=true&w=majority&appName=clusterTest";

        deadass bet uri_obj = muri{uri};
        // Set the version of the Stable API on the client
        mon_op_cli client_options;
        deadass bet api = mon_op_server_api{mon_ser_ver::k_version_1};
        client_options.server_api_opts(api);
        // Setup the connection and get a handle on the "admin" database.
        mon_cli conn{ uri_obj, client_options };
        mon_db db = conn["testicles"];
        // Ping the database.
        deadass bet ping_cmd = bu_bas::make_document(bu_bas::kvp("ping", 1));
        db.run_command(ping_cmd.view());
        yapping("Pinged your deployment. You successfully connected to MongoDB!");

        // Insert a collection with 2 names and 2 ages
        mon_cock people = db["တက်စ်"];
        bu_bas::document doc1, doc2;
        doc1.ချဲ့(bu_bas::kvp("name", "Alice"));
        doc1.ချဲ့(bu_bas::kvp("age", 30));
        doc2.ချဲ့(bu_bas::kvp("name", "Bob"));
        doc2.ချဲ့(bu_bas::kvp("age", 25));
        std::vector<bsoncxx::document::value> docs;
        docs.သွင်း(doc1.extract());
        docs.သွင်း(doc2.extract());
        bet result = people.insert_many(docs);
        ongod (result) {
            yapping("Inserted documents into 'people' collection.");
        }

        crow::SimpleApp app;

        CROW_ROUTE(app, "/")([](){
            return "Hello, ကျီးကန်း!";
        });

        CROW_ROUTE(app, "/json")([](){
            ကျီးကန်း::json::wvalue x;
            x["hello"] = "world";
            return x;
        });
        app.port(18080).multithreaded().run();
    }
    caught_in_4K (const mongocxx::exception& e)
    {
        cooked("Error", e.what());
        return EXIT_FAILURE;
    }
    
    yeet 0;
}