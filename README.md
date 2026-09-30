# Library Inventory Manager V3

A modern C++23 console application for managing a personal library inventory.

Library Inventory Manager V3 is a complete redesign of my previous C implementation, rebuilt using object-oriented design principles and modern C++ practices. The project focuses on maintainable architecture, modular components, persistent storage, and a clean separation between data management and user interaction.

> **Status:** v1.0.0 Released

---

# Features

## Library Management

- Add new books
- Edit book information
- Delete books
- Display all books
- Automatic ID generation

## Search

Search the library by:

- Book ID
- Title
- Author

## Book Operations

- Purchase books
- Borrow books
- Return books

## Sorting

Sort books by:

- ID (Ascending / Descending)
- Price (Ascending / Descending)

## Statistics

Generate inventory statistics including:

- Total unique books
- Total copies
- Available copies
- Inventory value
- Most expensive book
- Cheapest book
- Average book price

## Data Persistence

- Automatic save and load
- Save files stored in:

```text
C:\Users\<Username>\Documents\Library Inventory\
```

The application automatically creates the save directory when it does not already exist.

## Installer

The project includes a Windows installer built with **Inno Setup**, providing:

- One-click installation
- Desktop shortcut creation
- Start Menu integration
- Automatic uninstaller
- Custom application icon

---

# Technologies

- C++23
- CMake
- Ninja
- Inno Setup

### Standard Library Components

- Containers
- File Streams
- Filesystem
- Algorithms
- Templates

---

# Project Structure

```text
Library-V3/
│
├── assets/
│   ├── library.ico
│   └── LibraryV3.rc
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
├── installer/
│   └── LibraryInstaller.iss
│
├── CMakeLists.txt
└── README.md
```

---

# Software Design

The project follows an object-oriented architecture centered around two primary classes:

### Book

Represents an individual book and encapsulates its data and operations.

### Library

Responsible for:

- Inventory management
- Searching
- Sorting
- Statistics generation
- File persistence
- Book operations

Input handling and utility functionality are separated into reusable helper functions, keeping business logic isolated from user interaction.

---

# Build

## Requirements

- CMake 3.20+
- C++23 compatible compiler
- Ninja (recommended)

## Build Instructions

```bash
cmake -S . -B build -G Ninja
cmake --build build
```

---

# Future Improvements

- Replace manual sorting with `std::sort`
- Improve searching performance
- SQLite database backend
- Qt desktop interface
- Unit testing
- Configuration file support
- Logging system
- Cross-platform support

---

# About This Project

Library Inventory Manager V3 represents my transition from procedural C programming to modern C++ software development.

The project emphasizes:

- Object-oriented design
- Modular architecture
- Maintainable code organization
- Persistent data management
- Build system configuration with CMake
- Windows application packaging

---

# Author

**Mohamed Mourad**

Computer Science student with an interest in software engineering, desktop application development, and modern C++.
