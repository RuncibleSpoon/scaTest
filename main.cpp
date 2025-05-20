#include <iostream>
#include "nlohmann/json.hpp" // Include the header-only library
#include "yhorise/httplib.h"
// for convenience
using json = nlohmann::json;

// HTTP
httplib::Client cli("http://yhirose.github.io");

auto res = cli.Get("/hi");
res->status;
res->body;

int main() {
    // Creating a JSON object
    json user_profile = {
        {"name", "Robert"},
        {"age", 54},
        {"skills", {"C++", "API Security", "Technical Marketing"}},
        {"active", true}
    };

    // Serialize the JSON object to a string
    std::string serialized = user_profile.dump(4); // Pretty print with indentation
    std::cout << "Serialized JSON:\n" << serialized << "\n\n";

    // Deserialize JSON back to an object
    std::string input_json = R"(
        {
            "name": "Alice",
            "age": 30,
            "skills": ["Python", "Machine Learning"],
            "active": false
        }
    )";

    json deserialized = json::parse(input_json);

    // Access data
    std::string name = deserialized["name"];
    int age = deserialized["age"];
    bool active = deserialized["active"];

    std::cout << "Deserialized Data:\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Age: " << age << "\n";
    std::cout << "Active: " << (active ? "Yes" : "No") << "\n";

    return 0;
}
