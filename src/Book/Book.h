#ifndef Book_H
#define Book_H

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Book
{
private:
    string title;
    string numberShelf;
    string authors;
    int edition;
    string publisher;
    int yearPublished;
    string ISBN;
    int length;
    string subjects;
    int userId;
public:
    Book();
    Book(string title, string numberShelf, string authors, int edition, string publisher,
        int yearPublished, string ISBN, int length, string subjects, int userId);
    bool isYourName(string name);
    bool isYourAuther(string _auther);
    string toString();
    ~Book();
};

#endif