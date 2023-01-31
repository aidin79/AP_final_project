#include "LibSystem.h"

bool LibSystem::chooseState()
{
    try
    {
        cout << "Please enter your command: " << endl;
        vector<string> command = ReaderModule::readCommand();
        string operation = command[0];
        if (operation == "login")
            login(command);
        else if (operation == "signup")
            signup(command);
        else if (operation == "logout")
            logout();
        else if (operation == "search")
            search(command);
        else if (operation == "borrow")
            borrow(command);
        else if (operation == "return")
            returnBook(command);
        else if (operation == "showAll")
            showAll();
        else if(operation == "exit")
            return false;
        else
            cerr << "invalid command!\n" << endl;
    }
    catch (const exception& e)
    {
        cerr << e.what() << '\n';
        cout << endl;
    }
    return true;
}

bool LibSystem::isLoggedIn()
{
    if (loggedInUserId == -1)
        return false;
    return true;
}

void LibSystem::login(vector<string> command)
{
    const int LOGIN_COMMAND_SIZE = 3;
    if (command.size() != LOGIN_COMMAND_SIZE)
        throw invalid_argument("login commands format must be: login userName password");
    if (isLoggedIn())
        throw invalid_argument("you have already logged in");
    string userName = command[1];
    string password = command[2];
    int userId = usersClass.validateUser(userName, password);
    if (userId == -1)
        throw invalid_argument("username or password is wrong!");
    loggedInUserId = userId;
    cout << "wellcome:)\n" << endl;
}

void LibSystem::signup(vector<string> command)
{
    const int SIGNUP_COMMAND_SIZE = 6;
    if (command.size() != SIGNUP_COMMAND_SIZE)
        throw invalid_argument("signup commands format must be: signup userName password firstName lastName birthDate");
    if (isLoggedIn())
        throw invalid_argument("please logout first for new signup");
    string userName = command[1];
    string password = command[2];
    string firstName = command[3];
    string lastName = command[4];
    string birthDate = command[5];

    usersClass.add(userName, password, firstName, lastName, birthDate);
    cout << "you have signed up succeessfully!\n" << endl;
    
}

void LibSystem::search(vector<string> command)
{
    const int SEARCH_COMMAND_SIZE = 3;
    if (command.size() != SEARCH_COMMAND_SIZE)
        throw invalid_argument("search commands format must be: search <searchBy> <value>");
    string searchBy = command[1];
    vector<string> res;
    if (searchBy == "name") {
        string name = command[2];
        res = booksClass.searchByName(name);
    }
    else if (searchBy == "auther") {
        string auther = command[2];
        res = booksClass.searchByAuther(auther);
    }
    listPrinter(res);

}

void LibSystem::borrow(vector<string> command)
{
    const int BORROW_COMMAND_SIZE = 2;
    if (command.size() != BORROW_COMMAND_SIZE)
        throw invalid_argument("borrow commands format must be: search <ISBN>.");
    if (loggedInUserId == -1)
        throw invalid_argument("please login first.");
    string ISBN = command[1];
    int bookId = booksClass.findByISBN(ISBN);
    if (bookId == -1)
        throw invalid_argument("we dont have this book:(");
    if (!booksClass.isFree(bookId))
        throw invalid_argument("this book has already borrowed:(");
    if (!usersClass.canBorrow(loggedInUserId))
        throw invalid_argument("you cant borrow more books:(");
    booksClass.addUserToBook(loggedInUserId, bookId);
    usersClass.addBookToUser(bookId, loggedInUserId);
    cout << "you have borrowed successfully\n" << endl;
}

void LibSystem::returnBook(vector<string> command)
{
    const int RETURN_COMMAND_SIZE = 2;
    if (command.size() != RETURN_COMMAND_SIZE)
        throw invalid_argument("borrow commands format must be: search <ISBN>.");
    if (loggedInUserId == -1)
        throw invalid_argument("please login first.");

    string ISBN = command[1];
    int bookId = booksClass.findByISBN(ISBN);

    if (bookId == -1)
        throw invalid_argument("we dont have this book:(");
    if (!usersClass.hasBook(bookId, loggedInUserId))
        throw invalid_argument("you dont have this book");
    booksClass.freeBook(bookId);
    usersClass.returnBook(bookId, loggedInUserId);
    cout << "your book returned successfully\n" << endl;

}

void LibSystem::listPrinter(vector<string> list)
{
    if (list.empty())
        cout << "empty:(" << endl;
    for (string line : list)
        cout << line << endl;
}

void LibSystem::showAll()
{
    booksClass.printAll();
}

void LibSystem::logout()
{
    if (loggedInUserId == -1)
        throw invalid_argument("you are not logged in");
    loggedInUserId = -1;
    cout << "you have logged out succeessfully!\n" << endl;
}

LibSystem::LibSystem()
{
    loggedInUserId = -1;
    // cout << "LibSystem is here!" << endl;
}

void LibSystem::start()
{
    cout << "LibSystem started!" << endl;
    try
    {
        bool state = true;
        while (state)
        {
            state = chooseState();
        }
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
}

LibSystem::~LibSystem()
{
    cout << "LibSystem died!" << endl;
}