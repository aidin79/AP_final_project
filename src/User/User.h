#ifndef User_H
#define User_H

#include <iostream>
#include <vector>
using namespace std;

class User
{
private:
    string userName;
    string password;
    string firstName;
    string lastName;
    string birthDate;
    vector<int> borrowedBooksId;
    bool isAdmin;
public:
    User();
    User(string _userName, string _password, string _firstName, string _lastName, 
        string _birthDate, vector<int> _borrowedBooksId = vector<int>(), bool _isAdmin = false);
    string toString();
    bool isYou(string _userName, string _password);
    bool isYourUser(string _userName);
    bool canBorrow();
    void addBook(int bookId);
    ~User();
};

#endif