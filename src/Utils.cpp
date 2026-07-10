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
    if (choice == 'y' || choice == 'Y') return 1; Sleep(1000);
    return 0;
}