#ifndef ReaderModule_H
#define ReaderModule_H

#include <iostream>
#include <vector>
#include <fstream>
#include "../User/User.h"
#include "../Book/Book.h"
using namespace std;

class ReaderModule
{
public:
    static vector<string> split(string line, char separator = ' ');
    static vector<User> readUsersFile(string fileAdr);
    static vector<Book> readBooksFile(string fileAdr);
    static void writeToFile(string data, string filepath);
    static vector<string> readCommand();
};

#endif