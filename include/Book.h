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
        std::string getTitle() const;
        std::string getAuthor() const;
        double getPrice() const;
        int getQuantity() const;
        
        void setID(int id);
        void setTitle(std::string& title);
        void setAuthor(std::string& author);
        void setPrice(double price);
        void setQuantity(int quantity);

        Book(int id,
            std::string& title,
            std::string& author,
            double price,
            int quantity);
        void printBook() const;
};