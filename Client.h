#ifndef client_h
#define client_h
#include "User.h"
#include "Book.h"

class Client: public User {
    private:
        int rentedBooks;
        /**
        * checks if the book is available and proceeds to rent it
        */
        bool checkBookRent(Book* b);
        /**
        * checks if the book is rented and proceeds to return it
        */
        bool checkBookReturn(Book* b);
    public:
        Client(std::string name, int id);
        ~Client();
        /**
        * rents the book whose name is given as a parameter
        */
        bool rentBook(std::string name, std::vector<Book*>* books);
        /**
        * returns the book whose name is given as a parameter
        */
        bool returnBook(std::string name, std::vector<Book*>* books);
        /**
        * prints all the books the user have rented
        */
        void listAllRentedBooks(std::vector<Book*>* books);
        /**
        *   prints the information of the client
        */
        void printUser();
};

#endif // client_h
