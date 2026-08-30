# Bank Management System

Bank Management System is a C++ console application designed to manage clients, banking transactions, users, permissions, and currencies.

The project was built as a practical learning project to apply Object-Oriented Programming, file handling, data management, and clean code concepts.

## Features

### Client Management

* Add new clients
* Delete clients
* Update client information
* Find clients
* List all clients

### Banking Transactions

* Deposit
* Withdraw
* Transfer
* View transaction history
* Calculate total balances

### User Management

* Add users
* Delete users
* Update users
* Find users
* Manage user permissions

### Authentication & Access Control

* User login
* Login records
* Access control based on user permissions

### Currency Management

* List currencies
* Find currencies
* Update currency exchange rates
* Currency conversion

## Technologies & Concepts

* C++
* Object-Oriented Programming (OOP)
* Encapsulation
* Inheritance
* File Handling
* Exception Handling
* STL Containers (`std::vector`)
* Clean Code Principles

## Project Structure

The project is organized into several parts, with each part responsible for a specific area of the application.

```text
projict_Bank/
│
├── include/
│   ├── Core/
│   ├── Lib/
│   └── Screen/
│       ├── Client/
│       └── User/
│
├── src/
│   ├── Core/
│   ├── Lib/
│   └── Screen/
│       ├── Client/
│       └── User/
│
├── data/
│
├── projict_Bank.sln
├── README.md
└── .gitignore
```

### Core

Contains the main classes responsible for the application's core functionality.

### Lib

Contains utility and helper classes used throughout the application.

### Screen

Contains the console user interface and screens used to interact with the system.

* `Client/` — Client management screens
* `User/` — User management screens

### Data

Contains the text files used for persistent application data, transaction records, login records, currency data, and error logs.

## Data Storage

The application uses text files to store and retrieve data.

This approach was used as part of the learning process to practice file handling and persistent data management in C++.

## Learning Goals

This project was built to apply and strengthen practical programming concepts, including:

* Object-Oriented Programming
* Class design
* Encapsulation
* Inheritance
* File handling
* Exception handling
* Data management
* User permissions
* Clean code and code organization

## Project Status

This is an educational project developed as part of my programming learning journey.

The project may be improved and extended in the future as I continue developing my programming skills.

## Author

**Kozman Salib**

GitHub: [kozman-eg](https://github.com/kozman-eg)
