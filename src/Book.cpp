#include "Book.h"
#include <iostream>

std::string Book::getTitle(){
    return title;
}

Book::Book(
            int id,
            std::string& title,
            std::string& author,
            double price,
            int quantity):
                id(id),
                title(title),
                author(author),
                price(price),
                quantity(quantity){}

void Book::printBook(){
    std::cout<<"ID:# "<<id <<std::endl;
    std::cout<<"Title:"<<title <<std::endl;
    std::cout<<"Author:"<<author <<std::endl;
    std::cout<<"Price:"<<price <<std::endl;
    std::cout<<"Quantity:"<<quantity <<std::endl;
}