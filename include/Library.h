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
        void bookOptions(Book* book);
        Book* searchID();
        Book* searchTitle();
        std::vector<Book*> searchAuthor();
        void editBook(Book* book);
        void removeBook(Book* book);

        void saveData();
        void loadData();
        void resetData();
};