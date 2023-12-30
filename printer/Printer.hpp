//
//  Printer.hpp
//  Pdf_Printer
//
//  Created by Ahmet Sezgin on 28/12/2023.
//

#ifndef Printer_hpp
#define Printer_hpp

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <future>
#include <atomic>
#include "Document.hpp"
#include "Quality.hpp"
#include "Login.hpp"

class Printer : public Document {
private:
    static std::string response;
    static std::string iptalGirdisi;
    static std::string second_print;
    static std::atomic<bool> girdiAlindi;

public:
    Printer(const std::string& filePath);
    static void printDocument();
    static void getresponse();
    static void performPrint();
    static void cancelPrint();
    static void secondprint();
};

#endif /* Printer_hpp */
