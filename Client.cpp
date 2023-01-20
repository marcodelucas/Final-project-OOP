#include "Client.h"
#include "User.h"
#include "Book.h"
#include <string>
#include <iostream>
using namespace std;

Client::Client(string name, int id):User(name, id) {
    rentedBooks = 0;
}

Client::~Client() {
    cout << "Client deleted" << endl;
}

bool Client::rentBook(string nameBook, vector<Book*>* books) {
    bool aux = false;
    if(rentedBooks < 3) {
        for(Book* b : *books) {
            if(b->getName() == nameBook){
                aux = checkBookRent(b);
                break;
            }
        }
        if(aux) {
            rentedBooks++;
        }else {
            cout << "There is not any book with that name" << endl;
        }
    } else {
        cout << "You can only rent 3 books maximum" << endl;
    }
    return aux;
}

bool Client::returnBook(string nameBook, vector<Book*>* books) {
    bool aux = false;
    if(rentedBooks > 0) {
        for(Book* b : *books) {
            if(b->getName() == nameBook){
                aux = checkBookReturn(b);
                break;
            }
        }
        if(aux) {
            rentedBooks--;
        }else {
            cout << "There is not any book with that name" << endl;
        }
    } else {
        cout << "You don't have any book to return" << endl;
    }
    return aux;
}

void Client::listAllRentedBooks(vector<Book*>* books) {
    for(Book* b : *books) {
        if(b->getUser() == this->getName()){
            cout << "Name: \"" << b->getName() << "\", author: \"" << b->getAuthor() << "\"." << endl;
        }
    }
}

bool Client::checkBookRent(Book* b) {
    bool aux = false;
    if(!b->getBookability() && b->getAvailability() && (b->getUser() == "")) {
        b->setBookability(true, name);
        aux = true;
    } else {
        cout << "The book is already reserved or is not available" << endl;
    }
    return aux;
}

bool Client::checkBookReturn(Book* b) {
    bool aux = false;
    if(b->getBookability() && b->getAvailability() && (b->getUser() == name)) {
        b->setBookability(false, "");
        aux = true;
    } else {
        cout << "The book is not reserved or is not available" << endl;
    }
    return aux;
}

void Client::printUser() {
    cout << "Name: \"" << name << "\", id: \"" << id << "\", type: \"client\"." << endl;
}
