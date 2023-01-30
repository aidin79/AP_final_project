#include "ReaderModule.h"

vector<string> ReaderModule::split(string line, char separator)
{
    string s;
    vector<string> res;
    int i = 0;
    if (line.find(separator) == string::npos)
        res.push_back(line);
    else 
        while (line[i] != '\0') {
            if (line[i] != separator) {
                // Append the char to the temp string.
                s += line[i]; 
            } else {
                res.push_back(s);
                s.clear();
            }
            i++;
        }
    res.push_back(s);
    return res;
}

vector<User> ReaderModule::readUsersFile(string fileAdr)
{
    ifstream infile(fileAdr);
    vector<User> users;
    string userName, password, firstName, lastName, birthDate;
    bool isAdmin;
    cout << "readUsersFile" << endl;
    while (infile >> userName >> password >> firstName >> lastName >> birthDate >> isAdmin)
    {
        cout << userName << ' ' << password << ' ' << firstName << ' ' << lastName << ' ' << birthDate << ' ' << isAdmin << ' ' << endl;
        users.push_back(User(userName, password, firstName, lastName, birthDate, isAdmin));
    }
    return users;
}

vector<Book> ReaderModule::readBooksFile(string fileAdr)
{
    ifstream infile(fileAdr);
    vector<Book> books;
    string title, numberShelf , authors, publisher, ISBN, subjects;
    int edition, yearPublished, length, userId;
    cout << "readUsersFile" << endl;
    while (infile >> title >> numberShelf >> authors >> edition >> publisher >> yearPublished >> ISBN >> length >> subjects >> userId)
    {
        cout << title << ' ' << numberShelf << ' ' << authors << ' ' << publisher << ' ' << yearPublished << ' ' << userId << endl;
        books.push_back(Book(title, numberShelf, authors, edition, publisher, yearPublished, ISBN, length, subjects, userId));
    }
    return books;
}

void ReaderModule::writeToFile(string data, string filepath)
{
    ofstream out;
    out.open(filepath, ios::app);
    out << data << endl;
    out.close();
}

vector<string> ReaderModule::readCommand()
{
    string line;
    getline(cin, line);
    // cout << "line: " << line << endl;
    vector<string> result = split(line);
    return result;
}