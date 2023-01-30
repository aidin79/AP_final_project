#include "BooksClass.h"

BooksClass::BooksClass()
{
    books = ReaderModule::readBooksFile("src/Book/books.txt");
}

vector<string> BooksClass::searchByName(string name)
{
    vector<string> res;
    for (Book book : books) {
        if(book.isYourName(name))
            res.push_back(book.toString());
    }
    return res;
}

vector<string> BooksClass::searchByAuther(string auther)
{
    vector<string> res;
    for (Book book : books) {
        if(book.isYourAuther(auther))
            res.push_back(book.toString());
    }
    return res;
}

BooksClass::~BooksClass()
{
}