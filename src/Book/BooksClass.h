#ifndef BooksClass_H
#define BooksClass_H

#include "../Book/Book.h"
#include "../helpers/ReaderModule.h"
using namespace std;

class BooksClass
{
private:
    vector<Book> books;
public:
    BooksClass();
    vector<string> searchByName(string name);
    vector<string> searchByAuther(string auther);
    int findByISBN(string ISBN);
    bool isFree(int bookId);
    void addUserToBook(int userId, int bookId);
    void freeBook(int bookId);
    void printAll();
    ~BooksClass();
};

#endif