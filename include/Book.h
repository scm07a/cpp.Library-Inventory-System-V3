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
        std::string getTitle();
        Book(int id,
            std::string title,
            std::string author,
            double price,
            int quantity);
};