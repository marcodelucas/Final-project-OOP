#include <iostream>
#include <vector>
#include <string>
#include "Book.h"
#include "User.h"
#include "Librarian.h"
#include "Client.h"
using namespace std;

/**
* load some books into a vector at the beginning of the program
*/
void loadBooks();
/**
* load some users into a vector at the beginning of the program
*/
void loadUsers();
/**
* displays the initial menu on the screen
*/
void initialMenu();
/**
* displays the initial menu text
*/
void initialMenuText();
/**
* manages login options
*/
void logIn();
/**
* manages the process of creating a client
*/
void createAccount();
/**
* Checks that there is no user with the id passed as a parameter
*/
bool checkUserId(int id);
/**
* displays the librarian menu
*/
void librarianMenu();
/**
* displays the initial text of the librarian menu
*/
void librarianMenuText();
/**
* displays the client menu
*/
void clientMenu(Client* c);
/**
* displays the initial text of the client menu
*/
void clientMenuText(string name);
/**
* checks if the string passed as a parameter is a number or not
*/
bool isNumber(const string& str);
/**
* returns the client with the id passed as a parameter
*/
Client* getClientById(int id);

vector<Book*>* books;
vector<Client*> clients;
vector<User*> users;
Librarian* l;

int main()
{
    books = new vector<Book*>;
    l = new Librarian("Mr. Library", 0);
    loadBooks();
    loadUsers();
    initialMenu();
    delete l;
    delete books;
    return 0;
}

void loadBooks() {
    books->push_back(new Book("Don Quixote", "Miguel de Cervantes"));
    books->push_back(new Book("To Kill a Mockingbird", "Harper Lee"));
    books->push_back(new Book("Hamlet", "Shakespeare"));
    books->push_back(new Book("Solaris", "Stanislaw Lem"));
    books->push_back(new Book("The C Programming Language", "Bjarne Stroustrup"));
    books->push_back(new Book("The Da Vinci Code", "Dan Brown"));
    books->push_back(new Book("David Copperfield", "Charles Dickens"));
    books->push_back(new Book("Computer Networking: A Top-Down Approach", "Kurose James"));
    books->push_back(new Book("The Metamorphosis", "Franz Kafka"));
    books->push_back(new Book("The diary of a Young Girl", "Anne Frank"));
}

void loadUsers() {
    clients.push_back(new Client("Marco de Lucas", 1));
    clients.push_back(new Client("Adolfo T", 2));
    users.push_back(l);
    users.push_back(new Client("Marco de Lucas", 1));
    users.push_back(new Client("Adolfo Trocoli", 2));
}

void initialMenu() {
    string option = "0";
    initialMenuText();
    while((stoi(option) < 1) || (stoi(option) > 3)) {
        fflush(stdin);
        do{
            cout << "Choose and option:" << endl << "\t 1 - Log in" << endl << "\t 2 - Create an account" << endl << "\t 3 - Exit" << endl;
            cin >> option;
        } while(!isNumber(option));

        switch(stoi(option)) {
        case 1:
            logIn();
            break;
        case 2:
            createAccount();
            break;
        case 3:
            cout << "Thanks for using the program!" << endl;
        }
        if(stoi(option) != 3) {
            option = "0";
        }
    }
}

void initialMenuText() {
    cout << "******************************************************************************************" << endl;
    cout << "* \t \t \t \t \t LIBRARY APP \t \t \t \t \t *" << endl;
    cout << "*  \t \t Welcome to the first version of the application:    \t \t \t *" << endl;
    cout << "* \t There are three test users, the librarian (id 0) and two clients (id 1 and 2) \t *" << endl;
    cout << "* \t As it is a trial version, everything done in the app is not saved. \t \t *" << endl;
    cout << "* \t \t For future versions filesystem will be implemented. \t \t \t *" << endl;
    cout << "******************************************************************************************" << endl << endl;
}

void logIn() {
    string id = "0";
    int aux;
    do {
        cout << "Option 1: Log in" << endl << "Write your id:" << endl;
        cin >> id;
    } while(!isNumber(id));
    aux = 0;
    while(!checkUserId(stoi(id)) && aux < 2) {
        do {
            cout << "Wrong id, you have " << 2 - aux << " tries left" << endl;
            cin >> id;
            aux++;
            if(aux == 2) {
                break;
            }
        } while(!isNumber(id));
    }

    if(checkUserId(stoi(id))){
        if(stoi(id) == 0) {
            librarianMenu();
        } else {
            clientMenu(getClientById(stoi(id)));
        }
    } else {
        cout << "Wrong id, back to the menu." << endl << endl;
    }
}

void createAccount() {
    int aux;
    string id = "0";
    string name;
    fflush(stdin);
    do {
        cout << "Option 2: Create an account" << endl << "Write your id:" << endl << "It has to be an integer, don't forget it!" << endl;
        cin >> id;
    } while(!isNumber(id));
    aux = 0;
    while(checkUserId(stoi(id)) && aux < 2) {
        do {
            cout << "Id already in use, you have " << 2 - aux << " tries left" << endl;
            cin >> id;
            aux++;
            if(aux == 2) {
                break;
            }
        } while(!isNumber(id));
    }

    if(!checkUserId(stoi(id))) {
        cout << "Write your name: " << endl;
        fflush(stdin);
        getline(cin, name);
        clients.push_back(new Client(name, stoi(id)));
        users.push_back(new Client(name, stoi(id)));
        cout << "User created!" << endl;
    } else {
        cout << "Error creating the user, back to the menu" << endl;
    }
}

bool checkUserId(int id) {
    bool check = false;
    for(User* u: users) {
        if(u->getId() == id){
            check = true;
        }
    }
    return check;
}

void librarianMenu() {
    string option = "0";
    string name, author;
    librarianMenuText();
    while((stoi(option) < 1) || (stoi(option) > 6)) {
        fflush(stdin);
        do {
            cout << "Choose and option:" << endl << "\t 1 - Include a book" << endl << "\t 2 - Remove a book" <<
            endl << "\t 3 - List rented books" << endl << "\t 4 - List available books" << endl
            << "\t 5 - List users" << endl << "\t 6 - Exit" << endl;
            cin >> option;
        } while(!isNumber(option));

        switch(stoi(option)) {
        case 1:
            cout << "Option 1: Include a book" << endl << "Write the name of the book to include: ";
            fflush(stdin);
            getline(cin, name);
            cout << endl << "Write the name of its author: ";
            getline(cin, author);
            if(l->includeBook(name, author, books)) {
                cout << "The book \"" << name << "\" has been included in the list" << endl;
            } else {
                cout << "The name belongs to an existent book" << endl;
            }
            break;
        case 2:
            cout << "Option 2: Remove a book" << endl << "Write the name of the book to remove: ";
            fflush(stdin);
            getline(cin, name);
            cout << endl;
            if(l->removeBook(name, books)) {
                cout << "The book \"" << name << "\" has been removed in the list" << endl;
            } else {
                cout << "The name does not belong to an existent book" << endl;
            }
            break;
        case 3:
            cout << "Option 3: List rented books" << endl;
            l->listAllRentedBooks(books);
            break;
        case 4:
            cout << "Option 4: List available books" << endl;
            l->listAvailableBooks(books);
            break;
        case 5:
            cout << "Option 5: List users" << endl;
            l->listUsers(users);
        case 6:
            cout << "Back to the menu" << endl;
        }
        if(stoi(option) != 6) {
            option = "0";
        }
    }
}

void librarianMenuText() {
    cout << "******************************************************************************************" << endl;
    cout << "* \t \t \t \t \t LIBRARIAN MENU \t \t \t \t *" << endl;
    cout << "* \t \t \t \t \t Welcome " << l->getName() << "\t \t \t \t *" << endl;
    cout << "* \t As it is a trial version, everything done in the app is not saved. \t \t *" << endl;
    cout << "******************************************************************************************" << endl << endl;
}

void clientMenu(Client* c) {
    string option = "0";
    string name, author;
    clientMenuText(c->getName());
    while((stoi(option) < 1) || (stoi(option) > 5)) {
        fflush(stdin);
        do {
            cout << "Choose and option:" << endl << "\t 1 - Rent a book" << endl << "\t 2 - Return a book" <<
            endl << "\t 3 - List rented books" << endl << "\t 4 - List available books" << endl << "\t 5 - Exit" << endl;
            cin >> option;
        } while(!isNumber(option));

        switch(stoi(option)) {
        case 1:
            cout << "Option 1: Rent a book" << endl << "Write the name of the book to rent: ";
            fflush(stdin);
            getline(cin, name);
            if(c->rentBook(name, books)) {
                cout << "The book has been successfully reserved" << endl;
            }
            break;
        case 2:
            cout << "Option 2: Return a book" << endl << "Write the name of the book to return: ";
            fflush(stdin);
            getline(cin, name);
            cout << endl;
            if(c->returnBook(name, books)) {
                cout << "The book has been successfully returned" << endl;
            }
            break;
        case 3:
            cout << "Option 3: List rented books" << endl;
            c->listAllRentedBooks(books);
            break;
        case 4:
            cout << "Option 4: List available books" << endl;
            c->listAvailableBooks(books);
            break;
        case 5:
            cout << "Back to the menu" << endl;
        }
        if(stoi(option) != 5) {
            option = "0";
        }
    }
}

void clientMenuText(string name) {
    cout << "******************************************************************************************" << endl;
    cout << "* \t \t \t \t \t CLIENT MENU \t \t \t \t \t *" << endl;
    cout << "* \t \t \t \t \t Welcome " << name << "\t \t \t \t *" << endl;
    cout << "* \t As it is a trial version, everything done in the app is not saved. \t \t *" << endl;
    cout << "******************************************************************************************" << endl << endl;
}

Client* getClientById(int id) {
    Client* client;
    for (Client* c : clients) {
        if(c->getId() == id) {
            client = c;
        }
    }
    return client;
}

bool isNumber(const string& str) {
    return str.find_first_not_of( "0123456789" ) == string::npos;
}

