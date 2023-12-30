#ifndef Login_h
#define Login_h

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Document.h"
class Login {
protected:
    std::string username;
    std::string password;
    static std::vector<Login> userDatabase; // data base of the login page

public:

    Login(const std::string& username, const std::string& password);

    // Register users list
    static void initializeUsers();

    // add a new user
    static void addUser(const std::string& username, const std::string& password);

    // validate the users
    static bool validate(const std::string& inputUsername, const std::string& inputPassword);


    static void run();//runner of the class


    static void signup(); //provides to Signup the program


    static bool signin(); //provides to Signin the program


    static void quit();// provides to exit the program
    static void clearScreen();//clear the terminal
};

#endif /* Login_hpp */
