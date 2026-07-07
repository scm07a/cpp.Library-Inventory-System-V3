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
        std::string getTitle();//*For Sorting And Searching
        Book(int id,
            std::string& title,
            std::string& author,
            double price,
            int quantity);
        void printBook() const;
};