#pragma once
#include <string>
class Book{
    private:
        int id;
        std::string title;
        std::string author;
        double price;
        int quantity;
    public:
        int getID() const;
        std::string getTitle() const;//*For Sorting And Searching
        std::string getAuthor() const;
        double getPrice() const;
        int getQuantity() const;
        Book(int id,
            std::string& title,
            std::string& author,
            double price,
            int quantity);
        void printBook() const;
};