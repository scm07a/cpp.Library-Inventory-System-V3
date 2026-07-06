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

int Library::maxNoBooks(){
    int count=0;
    for (size_t i=0;i<books.size();i++)
        count++;
    return count;
}

void Library::searchBook(){
    std::cout<<"No. Of Books: " <<maxNoBooks() <<std::endl;
    
}