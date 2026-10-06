#include "Book.h"
#include <print>

int Book::getID() const{
    return id;
}
const std::string& Book::getTitle() const{
    return title;
}
const std::string& Book::getAuthor() const{
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
    std::println("");
    std::println("ID:# {}", id);
    std::println("Title:{}", title);
    std::println("Author:{}", author);
    std::println("Price:{}", price);
    std::println("Quantity:{}", quantity);
    std::println("Availability:{}", quantity > 0 ? "Available" : "UnAvailable");
    std::println("");
    std::println("=====================================");
    std::println("");
}