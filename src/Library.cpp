#include <iostream>
#include <fstream>
#include <windows.h>
#include "Book.h"
#include "Library.h"
#include "Utils.h"

Library::Library():nextID(1){}

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
        std::cin>>choice;
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

void Library::saveData(){
    std::ofstream file("Data/Library.txt");

    if(!file.is_open()){
        std::cout<<"Error Opening The File..."<<std::endl;
        return;
    }

    for (const Book& book: books){
        file<<book.getID() <<'\n';
        file<<book.getTitle() <<'\n';
        file<<book.getAuthor() <<'\n';
        file<<book.getPrice() <<'\n';
        file<<book.getQuantity() <<'\n';
        file<<nextID <<'\n';
    }
    file.close();
}
void Library::loadData(){
    std::ifstream file("Data/Library.txt");
    if(!file.is_open()){
        std::cout<<"Error! No Save File Found..."<<std::endl;
        return;
    }
}
void Library::resetData(){
    std::ofstream file("Data/Library.txt");

    if(!file.is_open()){
        std::cout<<"Error Resetting The File..."<<std::endl;
        return;
    }
    file.clear();
    file.close();
}

void Library::searchBookMenu(){
    int choice;
    std::cout<<"================="<<std::endl;
    std::cout<<"Search For A Book"<<std::endl;
    std::cout<<"================="<<std::endl;
    std::cout<<"Search By:-"<<std::endl;
    std::cout<<"1. ID. 2. Title. 3.Author."<<std::endl;
    std::cin>>choice;
    switch(choice){
        case 1:
            searchID();
            break;
        case 2:
            searchTitle();
            break;
        case 3:
            searchAuthor();
            break;
        default:
            printErr();
            break;
    }
}

void Library::searchID(){
    int IDChoice;
    std::cout<<"";
}