#ifndef UsersClassH
#define UsersClass_H

#include <iostream>
#include <vector>
#include "User.h"
#include "../helpers/ReaderModule.h"
using namespace std;

class UsersClass
{
private:
    vector<User> users;
    void printUsers();
    int findUserByUsername(string userName);
public:
    UsersClass();
    void add(string userName, string password, string firstName, string lastName, string birthDate);
    int validateUser(string userName, string password);
    ~UsersClass();
};

#endif