#include "User.h"

User::User()
{
}

User::User(string _userName, string _password, string _firstName, string _lastName, string _birthDate, bool _isAdmin)
{
    userName = _userName;
    password = _password;
    firstName = _firstName;
    lastName = _lastName;
    birthDate = _birthDate;
    isAdmin = _isAdmin;
}

string User::to_string() {
    char isAdminChar = isAdmin ? '1' : '0';
    cout << "isAdminChar: " << isAdminChar << endl;
    cout << "userName: " << userName << endl;
    string res = userName + ' ' + password + ' ' + firstName + ' ' + lastName + ' ' + birthDate + ' ' + isAdminChar;
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

User::~User()
{
}
