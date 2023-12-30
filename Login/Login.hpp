//
//  Login.hpp
//  Pdf_Printer
//
//  Created by Ahmet Sezgin on 28/12/2023.
//

#ifndef Login_hpp
#define Login_hpp

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Document.hpp"
class Login {
protected:
    std::string username;
    std::string password;
    static std::vector<Login> userDatabase; // Kullanıcı veritabanını saklayan statik vektör

public:
    // Kullanıcı adı ve şifre ile yeni bir Login nesnesi oluşturan yapıcı metod
    Login(const std::string &username, const std::string &password);

    // Başlangıçta bazı örnek kullanıcıları ekleyen statik metod
    static void initializeUsers();

    // Yeni bir kullanıcıyı veritabanına ekleyen statik metod
    static void addUser(const std::string &username, const std::string &password);

    // Verilen kullanıcı adı ve şifrenin doğruluğunu kontrol eden statik metod
    static bool validate(const std::string &inputUsername, const std::string &inputPassword);

    // Ana çalışma döngüsünü yöneten statik metod
    static void run();

    // Kullanıcı kaydı işlemini gerçekleştiren statik metod
    static void signup();

    // Kullanıcı giriş işlemini gerçekleştiren statik metod
    static bool signin();

    // Programdan çıkış yapmayı sağlayan statik metod
    static void quit();
    static void clearScreen();
};

#endif /* Login_hpp */
