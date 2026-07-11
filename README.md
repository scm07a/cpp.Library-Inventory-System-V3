# Library Inventory Manager V3

A modern C++23 console application for managing a personal library inventory.

Library Inventory Manager V3 is a complete redesign of my previous **Library V2** project, which was written in C. This version focuses on object-oriented programming, cleaner software architecture, reusable components, and modern C++ practices while remaining lightweight and fully console-based.

> **Status:** Beta (Core Features Complete)

---

# Features

## Library Management

- Add new books
- Display all books
- Edit existing books
- Delete books
- Automatic Book ID generation

## Search

Search books by:

- ID
- Title
- Author

## Book Operations

- Purchase books
- Borrow books
- Return books

## Sorting

Sort the library by:

- ID (Ascending)
- ID (Descending)
- Price (Ascending)
- Price (Descending)

## Statistics

View useful library statistics including:

- Total unique books
- Total copies
- Available copies
- Total inventory value
- Most expensive book
- Cheapest book
- Average book price

## Data Persistence

- Automatic save/load
- Save files stored inside:

```text
C:\Users\<Username>\Documents\Library Inventory\
```

- Automatically creates the save directory if it does not exist.

## Input Validation

- Generic template input function for numeric types
- Overloaded input function for strings
- Handles invalid user input safely

---

# Technologies Used

- C++23
- CMake
- Ninja
- Object-Oriented Programming (OOP)
- Standard Template Library (STL)

Libraries and containers used:

- `std::vector`
- `std::string`
- `std::filesystem`
- `std::fstream`

---

# Project Structure

```text
Library-V3/
│
├── include/
│   ├── Book.h
│   ├── Library.h
│   └── Utils.h
│
├── src/
│   ├── Book.cpp
│   ├── Library.cpp
│   ├── Utils.cpp
│   └── main.cpp
│
├── CMakeLists.txt
└── README.md
```

---

# Concepts Practiced

This project was built as part of my journey toward becoming a Software Engineer.

Topics practiced include:

- Classes and Objects
- Constructors
- Initializer Lists
- Encapsulation
- References
- Const Correctness
- Function Templates
- Function Overloading
- Dynamic Arrays (`std::vector`)
- File Streams
- Filesystem API
- Separation of Responsibilities
- Multi-file Project Organization
- CMake

---

# Future Improvements

- Replace manual sorting algorithms with `std::sort`
- Improve search algorithms
- Better input validation with configurable ranges
- Exception handling
- Installer for Windows
- SQLite database backend
- Graphical interface using Qt
- Improved console formatting
- Unit testing

---

# Building

## Requirements

- CMake 3.20 or newer
- C++23 compatible compiler
- Ninja (recommended)

## Build

```bash
cmake -S . -B build -G Ninja
cmake --build build
```

---

# Roadmap

This project represents my transition from procedural C programming to modern C++.

Planned progression:

- ✅ Procedural Programming (C)
- ✅ Object-Oriented Programming (C++)
- 🔄 Data Structures & Algorithms
- 🔄 Qt Desktop GUI
- 🔄 SQLite Integration
- 🔄 Full Library Management Application

---

# Author

Developed by **Mohamed Mourad** as part of my Software Engineering learning journey.

Library Inventory Manager V3 is focused on learning clean architecture, object-oriented programming, and modern C++ while building a complete real-world application from scratch.