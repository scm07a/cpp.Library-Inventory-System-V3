#include "Book.h"

std::string Book::getTitle(){
    return title;
}

Book::Book(
            std::string title,
            std::string author,
            double price,
            int quantity):
                title(title),
                author(author),
                price(price),
                quantity(quantity){}