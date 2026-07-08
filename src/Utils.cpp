#include <iostream>

void printErr(){
    std::cout<<"Error! Try Again"<<std::endl;
}
void comingSoon(){
    std::cout<<"Coming Soon..."<<std::endl;
}
int exitMenu(){
    char choice;
    std::cout<<"Are You Sure You Want To Exit?(Y/n)" <<std::endl;
    std::cin>>choice;
    if (choice == 'y' || choice == 'Y') return 1;
    return 0;
}