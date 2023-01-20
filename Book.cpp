#include "Book.h"
#include <iostream>
#include <string>
using namespace std;

Book::Book(string name, string author) {
    this->name = name;
    this->author = author;
    isBooked = false;
    available = true;
    user = "";
}

string Book::getName() {
    return name;
}

string Book::getAuthor() {
    return author;
}

string Book::getUser() {
    return user;
}

bool Book::getAvailability() {
    return available;
}

void Book::setAvailability(bool available) {
    this->available = available;
}

bool Book::getBookability() {
    return isBooked;
}

void Book::setBookability(bool bookability, string user) {
    isBooked = bookability;
    this->user = user;
}

void Book::printBook() {
    cout << "Name: \"" << name << "\", author: \"" << author << "\"." << endl;
}

void Book::printBook(string user) {
     cout << "Name: \"" << name << "\", author: \"" << author << "\", user: \"" << user << "\"." << endl;
}
