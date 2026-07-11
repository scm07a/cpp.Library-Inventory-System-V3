#include <iostream>
#include <limits>
#include <cstdlib>
#include <filesystem>
#include <windows.h>
#include "Utils.h"
void printErr(){
    std::cout<<"Error! Try Again"<<std::endl;
    Sleep(1000);
}
void comingSoon(){
    std::cout<<"Coming Soon..."<<std::endl;
    Sleep(1000);
}

int exitMenu(){
    char choice;
    std::cout<<"Are You Sure You Want To Exit?(Y/n)" <<std::endl;
    std::cin>>choice;
    //! Remember To Validate Input Above
    if (choice == 'y' || choice == 'Y') return 1; 
    Sleep(1000);
    system("cls");
    return 0;
}

void input(std::string& str, const std::string& prompt){
    while (true){
        std::cout<<prompt;
        std::getline(std::cin>>std::ws,str);
        if(std::cin.fail()){
            printErr();
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        }
        break;
    }
}

std::filesystem::path getSavePath(){
    const char* userProfile = std::getenv("USERPROFILE");
    
    if (!userProfile)
        return {};
    std::filesystem::path save_path = std::filesystem::path(userProfile)
                                                            /"Documents"
                                                            /"Library Inventory";
    std::filesystem::create_directories(save_path);
    return save_path/"Library.txt";
}