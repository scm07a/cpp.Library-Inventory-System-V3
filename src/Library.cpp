#include <iostream>
#include "Book.h"
#include "Library.h"

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

void Library::searchBook(){
    std::cout<<"No. Of Books: " <<books.size() <<std::endl;

}

void Library::displayAllBooks(){
    for (const Book &book: books)
        book.printBook();
}