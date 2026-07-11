#pragma once
#include <string>
void printErr();
void comingSoon();

int exitMenu();

template <typename T>
void input(T& var, const std::string& prompt){
    while(true){
        std::cout<<prompt;
        std::cin>>var;
        if(std::cin.fail()){
            printErr();
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        }
        std::cin>>std::ws;
        if(std::cin.peek()!='\n'){
            printErr();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }
}
void input(std::string& str, const std::string& prompt);
