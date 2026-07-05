#include "Book.h"

std::string Book::getTitle(){
    return title;
}

Book::Book(
            int id,
            std::string title,
            std::string author,
            double price,
            int quantity):
                id(id),
                title(title),
                author(author),
                price(price),
                quantity(quantity){}