#pragma once
#include <vector>
#include "Book.h"

class Library{
    private:
        int nextID;
        std::vector <Book> books;
    public:
        Library();
        void addBook();
        void searchBook();
        void displayAllBooks();
        void removeBook();
};