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
        int maxNoBooks();
        void searchBook();
        void displayAllBooks();
        void removeBook();
};