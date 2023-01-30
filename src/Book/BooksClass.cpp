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

bool BooksClass::isFree(int bookId)
{
    if (books[bookId].isFree())
        return true;
    return false;
}

void BooksClass::addUserToBook(int userId, int bookId)
{
    books[bookId].setUserId(userId);
}

int BooksClass::findByISBN(string ISBN)
{
    int booksSize = books.size();
    for (int i = 0; i < booksSize; i++) {
        if(books[i].isYourISBN(ISBN))
            return i;
    }
    return -1;
}

BooksClass::~BooksClass()
{
}