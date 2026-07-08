#include <iostream>
#include <windows.h>
#include "Library.h"
#include "Book.h"
#include "Utils.h"

int main(){
        SetConsoleOutputCP(CP_UTF8);
        int choice;
        Library library;

        while(true){
                std::cout<<"============================================="
                        <<std::endl;
                std::cout<<"        Library Inventory System V3"
                        <<std::endl;
                std::cout<<"============================================="
                        <<std::endl;
                std::cout<<"                 0.Exit"        
                        <<std::endl;
                std::cout<<"1. Add New Book.          2. Display All Books."
                        <<std::endl;
                std::cout<<"3. Search Books.          4. Statistics."
                        <<std::endl;
                std::cout<<"5. Save Data.             6. Reset Data."
                        <<std::endl;

                std::cout<<"Choice:";
                std::cin>>choice;
                std::cin.ignore();
                switch(choice){
                        case 0:
                                if (exitMenu())
                                        break;
                        case 1:
                                library.addBook();
                                break;
                        case 2:
                                library.displayAllBooks();
                                break;
                        case 3:
                                comingSoon();
                                Sleep(1000);
                                break;
                        case 4:
                                comingSoon();
                                Sleep(1000);
                                break;
                        case 5:
                                comingSoon();
                                Sleep(1000);
                                break;
                        case 6:
                                comingSoon();
                                Sleep(1000);
                                break;
                        default:
                                printErr();
                                Sleep(1000);
                                break;
                }
        }
        return 0;
}