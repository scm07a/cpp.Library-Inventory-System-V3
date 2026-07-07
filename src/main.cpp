#include <iostream>
#include "Library.h"
#include "Book.h"
#include "FileHandlers.h"

int main(){
    int choice;
    bool isRunning = true;
    Library library;
    // Book book;
    
    while(isRunning){
    std::cout<<"===Library Inventory System V3==="
            <<std::endl;
    std::cout<<"1.Add New Book.        2.Display All Books."
            <<std::endl;
    std::cin>>choice;
    std::cin.ignore();
    switch(choice){
        case 0:
            isRunning = false;
            break;
        case 1:
            library.addBook();
            break;
        case 2:
            library.displayAllBooks();
            break;
    }
}
    return 0;
}