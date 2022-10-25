#include <iostream>
#include <json/json.h>

using namespace std;

int main()
{
    Json::Reader reader;
    Json::Value root;

    string json = "{\n"
                  "    \"my-encoding\" : \"UTF-8\",\n"
                  "    \"my-plug-ins\" : [\n"
                  "        \"python\",\n"
                  "        \"c++\",\n"
                  "        \"ruby\"\n"
                  "        ],\n"
                  "    \"my-indent\" : { \"length\": 3, \"use_space\": true }\n"
                  "}";

    bool parseSuccess = reader.parse(json, root, false);

    if (parseSuccess)
    {
        const Json::Value resultValue = root["result"];
        cout << "Result is " << resultValue.asString() << "\n";
    }

    Json::StyledWriter styledWriter;
    Json::FastWriter fastWriter;
    Json::Value newValue;
    newValue["result"] = "ok";

    cout << styledWriter.write(newValue) << "\n";
    cout << fastWriter.write(newValue) << "\n";

    cout << "Hello World!";

    return 0;
}