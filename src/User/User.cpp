#include "User.h"

User::User()
{
}

User::User(string _userName, string _password, string _firstName, string _lastName,
    string _birthDate, vector<int> _borrowedBooksId, bool _isAdmin)
{
    userName = _userName;
    password = _password;
    firstName = _firstName;
    lastName = _lastName;
    birthDate = _birthDate;
    borrowedBooksId = _borrowedBooksId;
    isAdmin = _isAdmin;
}

string User::toString() {
    char isAdminChar = isAdmin ? '1' : '0';
    cout << "isAdminChar: " << isAdminChar << endl;
    cout << "userName: " << userName << endl;
    string res = userName + ' ' + password + ' ' + firstName + ' ' + lastName + ' ' + birthDate + 
        ' ' + isAdminChar + ' ' + to_string(borrowedBooksId.size());
    for (int id : borrowedBooksId)
        res = res + ' ' + to_string(id);
    cout << "res: " << res << endl;
    return res;
}

bool User::isYou(string _userName, string _password)
{
    if (userName == _userName && password == _password)
        return true;
    return false;
}

bool User::isYourUser(string _userName)
{
    if (userName == _userName)
        return true;
    return false;
}

bool User::canBorrow()
{
    if (borrowedBooksId.size() >= 2)
        return false;
    return true;
}

void User::addBook(int bookId)
{
    borrowedBooksId.push_back(bookId);
}

User::~User()
{
}
