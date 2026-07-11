#include <iostream>
#include <windows.h>
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
    return 0;
}

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