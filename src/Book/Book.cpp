#include "Book.h"

Book::Book()
{
}

Book::Book(string _title, string _numberShelf, string _authors, int _edition, string _publisher,
    int _yearPublished, string _ISBN, int _length, string _subjects, int _userId) {

    title = _title;
    numberShelf = _numberShelf;
    authors = _authors;
    edition = _edition;
    publisher = _publisher;
    yearPublished = _yearPublished;
    ISBN = _ISBN;
    length = _length;
    subjects = _subjects;
    userId = _userId;
}

bool Book::isYourName(string name)
{
    if (name == title) 
        return true;
    return false;
}

bool Book::isYourAuther(string _auther)
{
    if (authors == _auther) 
        return true;
    return false;
}

bool Book::isYourISBN(string _ISBN)
{
    if (ISBN == _ISBN) 
        return true;
    return false;
}

bool Book::isFree()
{
    if (userId == -1)
        return true;
    return false;
}

void Book::setUserId(int _userId)
{
    userId = _userId;
}

void Book::setFree()
{
    userId = -1;
}

string Book::toString(bool toWrite)
{
    string freeState = userId == -1 ? "free" : "borrowed";

    string res = title + ' ' + numberShelf + ' ' + authors + ' ' + to_string(edition) + ' ' + publisher + ' ' + 
        to_string(yearPublished) + ' ' + ISBN + ' ' + to_string(length) + ' ' + subjects + ' ';

    if (toWrite) res += to_string(userId);
    else res += freeState;
    return res;
}

Book::~Book()
{
}
