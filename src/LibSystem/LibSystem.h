#ifndef LibSystem_H
#define LibSystem_H

#include <iostream>
#include "../Book/BooksClass.h"
#include "../User/UsersClass.h"
#include "../helpers/ReaderModule.h"

using namespace std;

class LibSystem
{
private:
    int loggedInUserId;
    BooksClass booksClass;
    UsersClass usersClass;
    bool chooseState();
    bool isLoggedIn();
    void login(vector<string> command);
    void signup(vector<string> command);
    void search(vector<string> command);
    void listPrinter(vector<string> list);
    void logout();
public:
    LibSystem();
    void start();
    ~LibSystem();
};

#endif