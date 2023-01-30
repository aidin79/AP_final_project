#include "UsersClass.h"

void UsersClass::printUsers()
{

}

int UsersClass::findUserByUsername(string userName)
{
    int usersSize = users.size();
    for (int i = 0; i < usersSize; i++) {
        cout << "i: " << i << endl;
        if (users[i].isYourUser(userName))
            return i;
    }
    return -1;
}

UsersClass::UsersClass()
{
    users = ReaderModule::readUsersFile("src/User/usersFile.txt");
}


void UsersClass::add(string userName, string password, string firstName, string lastName, string birthDate)
{
    int userId = findUserByUsername(userName);
    if (userId != -1)
        throw invalid_argument("this username is duplicate. please choose another one.");
    User tmpUser(userName, password, firstName, lastName, birthDate);
    users.push_back(tmpUser);
    ReaderModule::writeToFile(tmpUser.toString(), "src/User/usersFile.txt");
}

int UsersClass::validateUser(string userName, string password)
{
    int userId = findUserByUsername(userName);
    if (userId > -1 && users[userId].isYou(userName, password))
        return userId;
    return -1;
}

bool UsersClass::canBorrow(int userId)
{
    if (users[userId].canBorrow())
        return true;
    return false;
}

void UsersClass::addBookToUser(int bookId, int userId)
{
    users[userId].addBook(bookId);
}

bool UsersClass::hasBook(int bookId, int userId)
{
    return users[userId].hasBook(bookId);
}

void UsersClass::returnBook(int bookId, int userId)
{
    users[userId].returnBook(bookId);
}

UsersClass::~UsersClass()
{
}