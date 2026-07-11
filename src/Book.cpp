#include "Book.h"
#include <iostream>

int Book::getID() const{
    return id;
}
std::string Book::getTitle() const{
    return title;
}
std::string Book::getAuthor() const{
    return author;
}
double Book::getPrice() const{
    return price;
}
int Book::getQuantity() const{
    return quantity;
}

void Book::setID(int id){
    this->id=id;
}
void Book::setTitle(const std::string& title){
    this->title=title;
}
void Book::setAuthor(const std::string& author){
    this->author=author;
}
void Book::setPrice(double price){
    this->price=price;
}
void Book::setQuantity(int quantity){
    this->quantity=quantity;
}

Book::Book(
            int id,
            const std::string& title,
            const std::string& author,
            double price,
            int quantity):
                id(id),
                title(title),
                author(author),
                price(price),
                quantity(quantity){}

void Book::printBook() const{
    std::cout<<'\n';
    std::cout<<"ID:# "<<id <<std::endl;
    std::cout<<"Title:"<<title <<std::endl;
    std::cout<<"Author:"<<author <<std::endl;
    std::cout<<"Price:"<<price <<std::endl;
    std::cout<<"Quantity:"<<quantity <<std::endl;
    std::cout<< "Availability:"<< (quantity>0 ? "Available":"UnAvailable")
            <<std::endl;
    std::cout<<"\n=====================================\n"
            <<std::endl;
}