#ifndef librarian_h
#define librarian_h
#include "User.h"
#include "Book.h"
#include <vector>

class Librarian: public User {
    private:
        /**
        * checks if the name given as a parameter is not the same as other book names
        */
        bool checkBookName(std::string, std::vector<Book*>* books);
    public:
        Librarian(std::string name, int id);
        ~Librarian();
        /**
        * includes a book in the catalog whose name and author are given as a parameter
        */
        bool includeBook(std::string name, std::string author, std::vector<Book*>* books);
        /**
        * removes a book from the catalog whose name is given as a parameter
        */
        bool removeBook(std::string name, std::vector<Book*>* books);
        /**
        * prints all the books rented by the clients
        */
        void listAllRentedBooks(std::vector<Book*>* books);
        /**
        * prints all the users of the application
        */
        void listUsers(std::vector<User*> users);
        /**
        * prints the information of the librarian
        */
        void printUser();
};

#endif // librarian_h
