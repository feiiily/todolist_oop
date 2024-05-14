#include <iostream>
#include <sstream>
#include <fstream>
#include "json/json.h"
#include "jsoncpp.cpp"
std::string json2str(const Json::Value &v, bool needFormat)
{
    if (needFormat)
    {
        Json::StreamWriterBuilder writer;
        std::string jsonString = Json::writeString(writer, v);
        return jsonString;
    }
    else
    {
        Json::FastWriter fastWriter;
        return fastWriter.write(v);
    }
}

bool str2json(const std::string &str, Json::Value &v)
{
    Json::CharReaderBuilder readerBuilder;
    std::istringstream iss(str);

    std::string errs;
    bool parsingSuccessful = Json::parseFromStream(readerBuilder, iss, &v, &errs);
    if (!parsingSuccessful)
    {
        std::cout << "Failed to parse JSON: " << errs << std::endl;
        return false;
    }

    return true;
}

bool str2file(const std::string &path, const std::string &data)
{
    std::ofstream file(path);
    if (!file.is_open())
    {
        return false;
    }

    file << data;
    file.close();

    return true;
}

bool file2json(const std::string &file, Json::Value &v)
{
    std::ifstream inputFile(file);
    if (!inputFile.is_open())
    {
        std::cout << "Failed to open file: " << file << std::endl;
        return false;
    }

    Json::CharReaderBuilder readerBuilder;
    std::string errs;

    bool parsingSuccessful = Json::parseFromStream(readerBuilder, inputFile, &v, &errs);
    inputFile.close();

    if (!parsingSuccessful)
    {
        std::cout << "Failed to parse JSON: " << errs << std::endl;
        return false;
    }

    return true;
}
void testjson()
{
    // 创建一个Json::Value对象
    Json::Value root;
    Json::Value rootaddress;

    // 添加数据到Json对象
    root["name"] = "xiaolan";              // 字符串
    root["age"] = 18;                      // 数字
    root["isStudent"] = true;              // bool类型
    Json::Value hobbies(Json::arrayValue); // 创建包含兴趣爱好的 JSON 数组
    hobbies.append("running");
    hobbies.append("traveling");
    root["hobbies"] = hobbies;

    Json::Value address; // 创建嵌套的 JSON 对象
    address["street"] = "321 Main St";
    address["city"] = "hangzhou";
    root["address"] = address;
    std::cout << "root: " << root << std::endl;

    // 生成 JSON 字符串
    std::string jsonString = json2str(root, true); // 转换为带格式的 JSON 字符串
    std::cout << "带格式jsonString: " << jsonString << std::endl;

    jsonString = json2str(root, false); // 转换为紧凑的 JSON 字符串
    std::cout << "紧凑jsonString: " << jsonString << std::endl;

    // 字符串变为json
    std::string jsonString1 = "{\"address\":{\"city\":\"hangzhou\",\"street\":\"999 Main St\"},\"age\":18,\"hobbies\":[\"running\",\"traveling\"],\"isStudent\":true,\"name\":\"xiaolan\"}";
    Json::Value root1;
    if (str2json(jsonString, root1))
    {
        std::cout << "root1: " << root1 << std::endl;
        // JSON 解析成功，可以访问解析后的数据
        // std::string name = root1["name"].asString();
        // int age = root1["age"].asInt();
        // bool isStudent = root1["isStudent"].asBool();
        // std::string street = root1["address"]["street"].asString();
        // std::string city = root1["address"]["city"].asString();

        // std::cout << "Name: " << name << std::endl;
        // std::cout << "Age: " << age << std::endl;
        // std::cout << "Is Student: " << (isStudent ? "true" : "false") << std::endl;
        // std::cout << "Street: " << street << std::endl;
        // std::cout << "City: " << city << std::endl;
    }

    // 字符串写入文件
    str2file("data/tempfile.json", json2str(root1, true));

    // 从文件当中读出来JSON
    std::string filePath = "tempfile.json";

    Json::Value root2;

    if (file2json(filePath, root2))
    {
        std::cout << "root2: " << root2 << std::endl;
        // JSON 解析成功，可以访问解析后的数据
        // std::string name = root2["name"].asString();
        // int age = root2["age"].asInt();
        // bool isStudent = root2["isStudent"].asBool();
        // std::string street = root2["address"]["street"].asString();
        // std::string city = root2["address"]["city"].asString();

        // std::cout << "Name: " << name << std::endl;
        // std::cout << "Age: " << age << std::endl;
        // std::cout << "Is Student: " << (isStudent ? "true" : "false") << std::endl;
        // std::cout << "Street: " << street << std::endl;
        // std::cout << "City: " << city << std::endl;
    }

}
