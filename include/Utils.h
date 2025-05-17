#include <iostream>
#include <fstream>
#include <ostream>
struct Utils
{
    static std::string loadStringFromFile(const char* filePath){
        FILE *file = fopen(filePath, "r");
        char c;
        std::string content;
        c = fgetc(file);
        while(c != EOF){
            content.push_back(c);
            c = fgetc(file);
        }
        fclose(file);
        content.push_back('\n');
        std::cout << content;
        return content.c_str();
    }
};


