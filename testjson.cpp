#include"json.hpp"
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream file("test.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
    }else {
        std::cout << "File opened successfully." << std::endl;
    }

}