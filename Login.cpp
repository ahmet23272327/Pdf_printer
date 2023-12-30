//
//  Login.cpp
//  Pdf_Printer
//
//  Created by Ahmet Sezgin on 28/12/2023.
//

#include "Login.h"

std::vector<Login> Login::userDatabase = {};// data base of the login page

Login::Login(const std::string& username, const std::string& password)
    : username(username), password(password) {}
// Register users list
void Login::initializeUsers() {
    addUser("user1", "pass1");
    addUser("user2", "pass2");
}
// add a new user
void Login::addUser(const std::string& username, const std::string& password) {
    userDatabase.emplace_back(username, password);
}
// validate the users
bool Login::validate(const std::string& inputUsername, const std::string& inputPassword) {
    for (const auto& user : userDatabase) {
        if (user.username == inputUsername && user.password == inputPassword) {
            return true;
        }
    }
    return false;
}
//provides to Signup the program
void Login::signup() {
    std::string username, password;
    std::cout << "New Username: ";
    std::cin >> username;
    std::cout << "New Password: ";
    std::cin >> password;
    addUser(username, password);
    std::cout << "You have successfuly signed up, please sign in." << std::endl;
}
//provides to Signin the program
bool Login::signin() {
    std::string username, password;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (validate(username, password)) {
        std::cout << "Succesful login!" << std::endl;
        return true;
    }
    else {
        std::cout << "Invalid username or password!" << std::endl;
        return false;
    }
}
// provides to exit the program
void Login::quit() {
    std::cout << "Have a nice day!" << std::endl;
    exit(0);
}
//clear the terminal
void Login::clearScreen() {
    std::system("cls");
}
//runner of the class
void Login::run() {
    initializeUsers();
    std::string loginpage;
    bool loggedIn = false;
    while (!loggedIn) {
        std::cout << "Enter Signup, Signin or Quit: ";
        std::cin >> loginpage;

        if (loginpage == "Signup") {
            signup();
            loggedIn = signin(); // Kullanýcýyý kayýt olduktan sonra giriþ yapmaya yönlendir
        }
        else if (loginpage == "Signin") {
            loggedIn = signin();
        }
        else if (loginpage == "Quit") {
            quit();
        }
        else {
            std::cout << "Invalid input. Please Try Again." << std::endl;
        }
    }
    //call the clearScreen
    Login::clearScreen();
    //call Runner function of the Document class runner.
    Document::document();
}
