#include "Librarian.h"
#include "User.h"
#include "Book.h"
#include <string>

#include <iostream>
using namespace std;

Librarian::Librarian(string name, int id):User(name, id) {}

Librarian::~Librarian() {
    cout << "Librarian deleted" << endl;
}

bool Librarian::includeBook(string name, string author, vector<Book*>* books) { //sumar en el main uno en numBooks
    if(checkBookName(name, books)){
        books->push_back(new Book(name, author));
        return true;
    }else {
        return false;
    }
}

bool Librarian::removeBook(string name, vector<Book*>* books) {
    bool aux = false;
    for(Book* b : *books) {
        if(b->getName() == name) {
            b->setAvailability(false);
            aux = true;
        }
    }
    return aux;
}

void Librarian::listAllRentedBooks(vector<Book*>* books) {
    for(Book* b : *books) {
        if(b->getBookability()) {
            b->printBook(b->getUser());
        }
    }
}

bool Librarian::checkBookName(string name, vector<Book*>* books) {
    bool aux = true;
    for(Book* b : *books) {
        if(b->getName() == name) {
            aux = false;
            if(!b->getAvailability()) {
                b->setAvailability(true);
                cout << "The book is available again" << endl;
            }
        }
    }
    return aux;
}

void Librarian::listUsers(vector<User*> users) {
    for(User* u : users) {
        u->printUser();
    }
}

void Librarian::printUser() {
    cout << "Name: \"" << name << "\", id: \"" << id << "\", type: \"librarian\"." << endl;
}
