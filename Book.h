#ifndef Book_h
#define Book_h
#include <string>

class Book {
    private:
        std::string name, author, user;
        bool isBooked, available;
    public:
        Book(std::string name, std::string author);
        /**
        * returns the name of the book
        */
        std::string getName();
        /**
        * returns the name of the user
        */
        std::string getUser();
        /**
        * returns the name of the author
        */
        std::string getAuthor();
        /**
        * returns a boolean indicating if the book is available in the catalog
        */
        bool getAvailability();
        /**
        * sets if the book is available or not
        */
        void setAvailability(bool availability);
        /**
        * returns a boolean indicating if the book is booked
        */
        bool getBookability();
        /**
        * sets if the book is booked or not
        */
        void setBookability(bool bookability, std::string user);
        /**
        * prints the description of the book
        */
        void printBook();
        /**
        * prints the description of the book
        */
        void printBook(std::string user);
};

#endif // book_b
