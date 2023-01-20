#ifndef user_h
#define user_h
#include <string>
#include <vector>
#include "Book.h"

class User {
    protected:
        std::string name;
        int id;
    public:
        User(std::string name, int id);
        virtual ~User();
        /**
        * returns the name of the user
        */
        std::string getName();
        /**
        * returns the id of the user
        */
        int getId();
        /**
        * prints all the available books in the catalog
        */
        void listAvailableBooks(std::vector<Book*>* books);
        /**
        * prints the description of the user
        */
        virtual void printUser() = 0;
};

#endif
