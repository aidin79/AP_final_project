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
    ~BooksClass();
};

#endif