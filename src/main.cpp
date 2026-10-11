#include <print>
#include <windows.h>
#include "Library.h"
#include "Book.h"
#include "Utils.h"

int main(){
	SetConsoleOutputCP(CP_UTF8);
	int choice;
	Library lib;
	lib.loadData();
	while(true){
		std::println("=============================================");
		std::println("        Library Inventory System V3");
		std::println("=============================================");
		std::println("                  0.Exit");
		std::println("1. Add New Book.          2. Display All Books.");
		std::println("3. Search Books.          4. Statistics.");
		std::println("5. Save Data.             6. Reset Data.");
		input(choice,"Enter Choice:");
		switch(choice){
			case 0:
				if (exitMenu()){
					lib.saveData();
					return 0;
				}
				break;
			case 1:
				lib.addBook();
				lib.saveData();
				system("cls");
				break;
			case 2:
				lib.displayAllBooks();
				system("cls");
				break;
			case 3:
				lib.searchBookMenu();
				system("cls");
				break;
			case 4:
				lib.stats();
				system("cls");
				break;
			case 5:
				lib.saveData();
				system("cls");
				break;
			case 6:
				lib.resetData();
				system("cls");
				break;
			default:
				printErr();
				break;
			}		
		}
	return 0;
}