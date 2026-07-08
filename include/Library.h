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

        void displayAllBooks();
        void fAscendingID();
        void fAscendingPrice();
        void fDescendingID();
        void fDescendingPrice();

        void stats();

        void searchBookMenu();
        void searchID();
        void searchTitle();
        void searchAuthor();
        int available();
        void removeBook();

        void saveData();
        void loadData();
        void resetData();
};