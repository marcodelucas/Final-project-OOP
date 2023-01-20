#include "User.h"
#include "Book.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

User::User(string name, int id) {
    this->name = name;
    this->id = id;
}

User::~User() {
    cout << "User deleted" << endl;
}

string User::getName() {
    return name;
}

int User::getId() {
    return id;
}

void User::listAvailableBooks(vector<Book*>* books) {
    for(Book* b : *books) {
        if(b->getAvailability() && !b->getBookability()) {
            b->printBook();
        }
    }
}

void User::printUser() {
    cout << "Name: \"" << name << "\", id: \"" << id << "\"." << endl;
}
