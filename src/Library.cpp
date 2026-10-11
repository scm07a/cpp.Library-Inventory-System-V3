#include <print>
#include <string>
#include <fstream>
#include <windows.h>
#include "Book.h"
#include "Library.h"
#include "Utils.h"

Library::Library()=default;

void Library::addBook(){
    system("cls");
    int quantity;
    std::string title,author;
    double price;
    input(title,"Enter Title:");
    input(author,"Enter Author's Name:");
    input(price,"Enter Price:");
    input(quantity,"Enter Quantity:");
    Book newBook=Book(nextID,title,author,price,quantity);
    books.push_back(newBook);
    nextID++;
}

void Library::displayAllBooks(){
    system("cls");
    if (books.empty()){
        std::println("The Library Is Empty...");
        Sleep(1000);
    return;
    }
    int choice;
    for (const Book &book: books)
        book.printBook();
    while (true){
        std::println("1. Sort By ID ↑.         2. Sort By Price ↑.");
        std::println("3. Sort By ID ↓.         4. Sort By Price ↓.");
        std::println("          5.Return To Main Menu. ");
        input(choice,"Enter Choice:");
        switch(choice){
            case 1: fAscendingID();  break;
            case 2: fAscendingPrice(); break;
            case 3: fDescendingID(); break;
            case 4: fDescendingPrice(); break;
            case 5: return;
            default:
                printErr(); 
                Sleep(1000);
                break;
        }
    }
}

void Library::fAscendingID(){
    std::size_t n =books.size();
    std::vector <Book> books_copy = books;
    for (std::size_t i=0;i<n-1;i++){
        for (std::size_t j=0;j<n-i-1;j++){
            if (books_copy[j].getID()>books_copy[j+1].getID())
                std::swap(books_copy[j],books_copy[j+1]);
        }
    }
    for (const Book& book : books_copy)
        book.printBook();
}

void Library::fAscendingPrice(){
    std::size_t n = books.size();
    std::vector <Book> books_copy = books;
    for (std::size_t i=0;i<n-1;i++){
        for (std::size_t j=0;j<n-i-1;j++){
            if (books_copy[j].getPrice()>books_copy[j+1].getPrice())
                std::swap(books_copy[j],books_copy[j+1]);
        }
    }
    for (const Book& book: books_copy)
        book.printBook();
}

void Library::fDescendingID(){
    std::size_t n =books.size();
    std::vector <Book> books_copy = books;
    for (std::size_t i=0;i<n-1;i++){
        for (std::size_t j=0;j<n-i-1;j++){
            if (books_copy[j].getID()<books_copy[j+1].getID())
                std::swap(books_copy[j],books_copy[j+1]);
        }
    }
    for (const Book& book : books_copy)
        book.printBook();
}

void Library::fDescendingPrice(){
    std::size_t n = books.size();
    std::vector <Book> books_copy = books;
    for (std::size_t i=0;i<n-1;i++){
        for (std::size_t j=0;j<n-i-1;j++){
            if (books_copy[j].getPrice()<books_copy[j+1].getPrice())
                std::swap(books_copy[j],books_copy[j+1]);
        }
    }
    for (const Book& book: books_copy)
        book.printBook();
}

void Library::stats(){
    system("cls");
    char menu_return = 'f';
    if (books.empty()){
    std::println("The Library Is Empty...");
    Sleep(1000);
    return;
    }

    std::size_t totalBooks=books.size(),
            totalCopies=0,
            availableCopies=0;
    std::string expensiveTitle, cheapTitle;
    double invValue=0, expensivePrice=-999, cheapPrice=999, avgPrice=0;
    for(const Book& book:books){
        //* Calculates Total Copies*
        totalCopies+=book.getQuantity();
        //* Calculates Total Available Copies*
        if(book.getQuantity()>0)
            availableCopies+=book.getQuantity();
        //* Calculates Inventory Value*
        invValue+=book.getPrice()*book.getQuantity();
        //* Sums All Book Prices In Loop*
        avgPrice+=book.getPrice();
        //* Expensive Book Search*
        if(book.getPrice()>expensivePrice){
            expensivePrice=book.getPrice();
            expensiveTitle=book.getTitle();
        }
        //* Cheap Book Search*
        if(book.getPrice()<cheapPrice){
            cheapPrice=book.getPrice();
            cheapTitle=book.getTitle();
        }
    }
    //* Divides By Total Books To Get Average*
    avgPrice/=totalBooks;
    //* Stats Menu*
    while (true){
        std::println("============");
        std::println(" Statistics");
        std::println("============\n");
        std::println("Total Books: {}",totalBooks);
        std::println("Total Copies: {}",totalCopies);
        std::println("Total Available Copies: {}\n",availableCopies);
        std::println("Average Book Price: ${}",avgPrice);
        std::println("Inventory Value: ${}\n",invValue);
        std::println("The Most Expensive Book: {} (${})",expensiveTitle,expensivePrice);
        std::println("The Cheapest Book: {} (${})\n\n",cheapTitle,cheapPrice);
        // std::cout<<"Average Book Price: $" <<avgPrice <<std::endl <<"\n\n";
        input(menu_return,"Return To Main Menu(Y/n):");
        if (menu_return == 'Y' || menu_return == 'y') break;
        else system("cls");
    }

}

void Library::searchBookMenu(){
    system("cls");
    int choice;

    std::println("=================");
    std::println("Search For A Book");
    std::println("=================");
    std::println("Search By:-");
    std::println("1. ID. 2. Title. 3. Author. 4. Return To Main Menu.");

    input(choice,"Enter Choice:");
    Book* book = nullptr;
    switch(choice){
        case 1:
            book = searchID();
            bookOptions(book);
            break;
        case 2:
            book = searchTitle();
            bookOptions(book);
            break;
        case 3:{
            auto matches = searchAuthor();
            if (matches.empty()){
                std::println("No Books Found...");
                Sleep(1000);
                break;
            }
            for(std::size_t i=0;i<matches.size();i++){
                std::println("{}. ",i+1);
                matches[i]->printBook();
            }
            int matchChoice;
            input(matchChoice,"Choose Book:");
            if (matchChoice>=1 && static_cast<std::size_t>(matchChoice) <= matches.size())
                bookOptions(matches[matchChoice-1]);
            break;
        }
        case 4:
            return;
        default:
            printErr();
            break;
    }
}

void Library::bookOptions(Book* book){
    if (book == nullptr){
        std::println("Book not found.");
        return;
    }
    int choice;
    int quantity = book->getQuantity();
    book->printBook();
    std::println("1. Purchase. 2. Borrow. 3. Return.");
    std::println("4. Edit.     5. Delete  6. Return To Main Menu.");
    input(choice,"Enter Choice:");
    switch(choice){
        case 1:
            book->setQuantity(quantity-1);
            std::println("Book Purchase Successful !");
            break;
        case 2:
            book->setQuantity(quantity-1);
            std::println("Book Borrowed Successfully !");
            break;
        case 3:
            book->setQuantity(quantity+1);
            std::println("Book Returned Successfully !");
            break;
        case 4:
            std::println();
            editBook(book);
            break;
        case 5:
            removeBook(book);
            break;
        case 6:
            return;
    }
}

Book* Library::searchID(){
    int IDChoice;
    input(IDChoice,"Enter The Book ID:");
    for (std::size_t i=0;i<books.size();i++){
        if (IDChoice == books[i].getID())
            return &books[i];
    }
    return nullptr;
}

Book* Library::searchTitle(){
    std::string titleChoice;
    input(titleChoice,"Enter The Book Title(Case Sensitive):");
    for(std::size_t i=0;i<books.size();i++){
        if(titleChoice==books[i].getTitle())
            return &books[i];
    }
    return nullptr;
}

std::vector<Book*> Library::searchAuthor(){
    std::string authorChoice;
    std::vector <Book*> authBooks;
    input(authorChoice,"Enter Author's Full Name (Case Sensitive):");
    for (Book &book:books){
        if(book.getAuthor()==authorChoice)
            authBooks.push_back(&book);
    }
    return authBooks;
}

void Library::editBook(Book* book){
    int choice, quantity;
    std::string title, author;
    double price;
    std::println("What Do You Want To Edit?");
    std::println("1. Title. 2.Author. 3.Price. 4. Quantity");
    std::print("Choice:");
    input(choice,"Enter Choice:");
    switch(choice){
        case 1:
            input(title,"Set New Title:");
            book->setTitle(title);
            std::println("New Title Set Successfully...");
            break;
        case 2:
            input(author,"Set New Author Name:");
            book->setAuthor(author);
            std::println("New Author Name Set Successfully...");
            break;
        case 3:
            input(price,"Set New Price:");
            book->setPrice(price);
            std::println("New Price Set Successfully...");
            break;
        case 4:
            input(quantity,"Set New Quantity:");
            book->setQuantity(quantity);
            std::println("New Quantity Set Successfully...");
            break;
        default:
            printErr();
            break;
    }
    saveData();
}

void Library::removeBook(Book* book){
    for (auto it=books.begin(); it!=books.end();++it){
        if(&(*it) == book){
            books.erase(it);
            std::println("Book Removed Successfully...");
            saveData();
            return;
        }
    }
    std::println("Book Not Found...");
}

void Library::saveData(){
    if (books.empty()){
        std::println("The Inventory Is Empty...");
        return;
    }
    std::ofstream file(getSavePath());
    if(!file.is_open()){
        std::println("Error Opening The File...");
        return;
    }
    file<<nextID <<'\n';
    for (const Book& book: books){
        file<<book.getID() <<'\n';
        file<<book.getTitle() <<'\n';
        file<<book.getAuthor() <<'\n';
        file<<book.getPrice() <<'\n';
        file<<book.getQuantity() <<'\n';
    }
    file.close();
    std::println("Data Saved Successfully");
    Sleep(1000);
}

void Library::loadData(){
    int id, quantity;
    std::string title, author;
    double price;
    std::ifstream file(getSavePath());
    if(!file.is_open()){
        std::println("Error Loading Data...");
        return;
    }
    file>> nextID;
    file.ignore();
    while(file>>id){
        file.ignore();
        std::getline(file,title);
        std::getline(file,author);
        file>>price;
        file>>quantity;
        file.ignore();
        books.push_back(Book(id,title,author,price,quantity));
    }
    file.close();
}

void Library::resetData(){
    if (books.empty()){
        std::println("The Inventory Is Empty");
        return;
    }
    char choice;
    input(choice,"Are You Sure You Want To Reset Your Data? This Action Can't Be Undone!!!(Y/n):");
    if (choice =='Y' || choice=='y'){
        std::ofstream file(getSavePath());
        if(!file.is_open()){
            std::println("Error Resetting The File...");
            return;
        }
        books.clear();
        nextID=1;
        std::println("Data Reset Successfully !");
        Sleep(1000);
        file.close();
    }
    else return;
}
