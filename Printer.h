#ifndef Printer_h
#define Printer_h

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <future>
#include <atomic>
#include "Document.h"
#include "Quality.h"
#include "Login.h"
//inheritance class
class Printer : public Document {
private:
    static std::string response;
    static std::string iptalGirdisi;
    static std::string second_print;
    static std::atomic<bool> girdiAlindi;

public:
    Printer(const std::string& filePath);
    
    static void printDocument();//runner of the Document Class
    static void getresponse();//does it want to write the file
    //sends the file to the printer and allows the printer to cancel the outgoing file while it is printing
    static void performPrint();
    //provide the cancel printing
    static void cancelPrint();
    //provide the 2nd time printing
    static void secondprint();
};

#endif /* Printer_hpp */
