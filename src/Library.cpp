#include <iostream>
#include <fstream>
#include <windows.h>
#include "Book.h"
#include "Library.h"
#include "Utils.h"

Library::Library():nextID(1){}
//! Validate Input In addBook Method
void Library::addBook(){
    int quantity;
    std::string title,author;
    double price;

    std::cout<<"Enter Title:";
    std::getline(std::cin,title);

    std::cout<<"Enter Author:";
    std::getline(std::cin,author);

    std::cout<<"Enter Price:" ;
    std::cin>>price;

    std::cout<<"Enter Quantity:";
    std::cin>>quantity;

    Book newBook=Book(nextID,title,author,price,quantity);
    books.push_back(newBook);
    nextID++;
}

void Library::displayAllBooks(){
    int choice;
    for (const Book &book: books)
        book.printBook();
    while (true){
        std::cout<<"1. Sort By ID ↑.         2. Sort By Price ↑."
                <<std::endl;
        std::cout<<"3. Sort By ID ↓.         4. Sort By Price ↓."
                <<std::endl;
        std::cout<<"          5.Return To Main Menu. "
                <<std::endl;

        std::cout<<"Choice: ";
        std::cin>>choice;//! Remember To Validate Input
        switch(choice){
            case 1: fAscendingID(); break;
            case 2: fAscendingPrice(); break;
            case 3: fDescendingID(); break;
            case 4: fDescendingPrice(); break;
            case 5: return;
            default:
                printErr(); 
                Sleep(1000);
                break;
        }
    }
    
}

void Library::fAscendingID(){
    size_t n =books.size();
    std::vector <Book> books_copy = books;
    for (size_t i=0;i<n-1;i++){
        for (size_t j=0;j<n-i-1;j++){
            if (books_copy[j].getID()>books_copy[j+1].getID())
                std::swap(books_copy[j],books_copy[j+1]);
        }
    }
    for (const Book& book : books_copy)
        book.printBook();
}

void Library::fAscendingPrice(){
    size_t n = books.size();
    std::vector <Book> books_copy = books;
    for (size_t i=0;i<n-1;i++){
        for (size_t j=0;j<n-i-1;j++){
            if (books_copy[j].getPrice()>books_copy[j+1].getPrice())
                std::swap(books_copy[j],books_copy[j+1]);
        }
    }
    for (const Book& book: books_copy)
        book.printBook();
}

void Library::fDescendingID(){
    size_t n =books.size();
    std::vector <Book> books_copy = books;
    for (size_t i=0;i<n-1;i++){
        for (size_t j=0;j<n-i-1;j++){
            if (books_copy[j].getID()<books_copy[j+1].getID())
                std::swap(books_copy[j],books_copy[j+1]);
        }
    }
    for (const Book& book : books_copy)
        book.printBook();
}

void Library::fDescendingPrice(){
    size_t n = books.size();
    std::vector <Book> books_copy = books;
    for (size_t i=0;i<n-1;i++){
        for (size_t j=0;j<n-i-1;j++){
            if (books_copy[j].getPrice()<books_copy[j+1].getPrice())
                std::swap(books_copy[j],books_copy[j+1]);
        }
    }
    for (const Book& book: books_copy)
        book.printBook();
}

void Library::stats(){}

void Library::searchBookMenu(){
    int choice;
    std::cout<<"================="<<std::endl;
    std::cout<<"Search For A Book"<<std::endl;
    std::cout<<"================="<<std::endl;
    std::cout<<"Search By:-"<<std::endl;
    std::cout<<"1. ID. 2. Title. 3. Author. 4. Return To Main Menu."
            <<std::endl;
    std::cin>>choice;//! Remember To Validate Input
    Book* book = nullptr;
    switch(choice){
        case 1:
            std::cout<<"Enter The Book ID:";
            book = searchID();
            bookOptions(book);
            break;
        case 2:
            std::cout<<"Enter The Book Title(Case Sensitive):";
            comingSoon();
            // book = searchTitle();
            // bookOptions(book);
            break;
        case 3:
            std::cout<<"Enter Author's Full Name (Case Sensitive):";
            comingSoon();
            // book = searchAuthor();
            // bookOptions(book);
            break;
        case 4:
            return;
        default:
            printErr();
            break;
    }
}

void Library::bookOptions(Book* book){
    if (book == nullptr){
        std::cout << "Book not found." <<std::endl;
        return;
    }

    int choice;
    int quantity = book->getQuantity();
    book->printBook();
    std::cout<<"1. Purchase. 2. Borrow. 3. Return." <<std::endl;
    std::cout<<"4. Edit.     5. Delete  6. Return To Main Menu."<<std::endl;
    std::cout<<"Choice:";
    std::cin>>choice;//! Remember To Validate Input
    switch(choice){
        case 1:
            book->setQuantity(quantity-1);
            std::cout<<"Book Purchase Successful !" <<std::endl;
            break;
        case 2:
            book->setQuantity(quantity-1);
            std::cout<<"Book Borrowed Successfully !"<<std::endl;
            break;
        case 3:
            book->setQuantity(quantity+1);
            std::cout<<"Book Returned Successfully !"<<std::endl;
            break;
        case 4:
            comingSoon();
            // editBook(book);
            break;
        case 5:
            comingSoon();
            // removeBook(book);
            break;
        case 6:
            return;
    }
}

Book* Library::searchID(){
    int IDChoice;
    std::cin>>IDChoice;//! Remember To Validate Input
    std::cin.ignore();//! Remember To Validate Input
    for (size_t i=0;i<books.size();i++){
        if (IDChoice == books[i].getID())
            return &books[i];
    }
    return nullptr;
}

void Library::saveData(){
    std::ofstream file("../Data/Library.txt");

    if(!file.is_open()){
        std::cout<<"Error Opening The File..."<<std::endl;
        return;
    }
    file<<nextID <<'\n';
    for (const Book& book: books){
        file<<book.getID() <<'\n';
        file<<book.getTitle() <<'\n';
        file<<book.getAuthor() <<'\n';
        file<<book.getPrice() <<'\n';
        file<<book.getQuantity() <<'\n';
    }
    file.close();
    std::cout<<"Data Saved Successfully" <<std::endl;
    Sleep(1000);
}
void Library::loadData(){
    int id, quantity;
    std::string title, author;
    double price;
    std::ifstream file("../Data/Library.txt");
    if(!file.is_open()){
        std::cout<<"Error! No Save File Found..."<<std::endl;
        return;
    }
    file>> nextID;
    file.ignore();
    while(file>>id){
        file.ignore();
        std::getline(file,title);
        std::getline(file,author);
        file>>price;
        file>>quantity;
        file.ignore();
        books.push_back(Book(id,title,author,price,quantity));
    }
    file.close();
}
void Library::resetData(){
    std::ofstream file("../Data/Library.txt");

    if(!file.is_open()){
        std::cout<<"Error Resetting The File..."<<std::endl;
        return;
    }
    books.clear();
    nextID=1;
    std::cout<<"Data Reset Successfully !" <<std::endl;
    Sleep(1000);
    file.close();
}