# Library Inventory Manager V3

A modern C++ console application for managing a library inventory.

This project is a complete redesign of my previous Library V2 project with a stronger focus on object-oriented programming, clean architecture, and modern C++ practices. Instead of writing everything in a single source file, the application is built using multiple classes, separated responsibilities, and reusable components.

> **Project Status:** In Development

---

## Features

### Implemented

- Object-oriented `Book` class
- Object-oriented `Library` class
- Add new books to the library
- Automatic book ID generation
- Constructor initialization using initializer lists
- Dynamic book storage using `std::vector`

### In Progress

- Display individual books
- Display all books
- Remove books
- Search books
- Edit book information

### Planned

- File saving and loading
- Input validation
- Improved console interface
- Better error handling
- Cleaner project architecture

---

## Technologies Used

- C++23
- Object-Oriented Programming (OOP)
- Standard Template Library (STL)
  - `std::vector`
  - `std::string`

---

## Project Structure

```text
Library-V3/
│
├── include/
│   ├── Book.h
│   └── Library.h
│
├── src/
│   ├── Book.cpp
│   ├── Library.cpp
│   └── main.cpp
│
└── README.md
```

---

## Goals

This project is helping me strengthen my understanding of:

- Classes and Objects
- Constructors
- Initializer Lists
- Encapsulation
- Composition
- Separation of Responsibilities
- Working with Multiple Source Files
- STL Containers
- Writing maintainable C++ code

---

## Future Improvements

- Persistent data storage
- Better search algorithms
- Sorting books
- Borrowing and returning books
- Statistics dashboard
- Optional graphical interface using SDL2/OpenGL in the future

---

## Build

Compile the project using a C++23 compatible compiler.

Example:

```bash
g++ src/*.cpp -Iinclude -std=c++23 -o LibraryV3
```

---

## Author

Developed by **Mohamed Mourad** as part of my journey toward becoming a Software Engineer.

Feedback and suggestions are always welcome!
