//
//  Printer.cpp
//  Pdf_Printer
//
//  Created by Ahmet Sezgin on 28/12/2023.
//


#include "Printer.hpp"

std::string Printer::response;
std::string Printer::iptalGirdisi;
std::string Printer::second_print;
std::atomic<bool> Printer::girdiAlindi(false);

Printer::Printer(const std::string& filePath) : Document(filePath,pagecount,color,size,frontback) {
    std::cout << "Would you like to print the file? (yes/no): ";
    std::cin >> response;
    getresponse();
}

void Printer::printDocument() {
    Printer file_print(filePath);
}

void Printer::getresponse() {
    if (response == "yes") {
        performPrint();
    } else {
        std::cout << "Printing Cancelled." << std::endl;
    }
}

void Printer::performPrint() {
    std::cout << filePath << "File is printing" << std::endl;
    std::cout << "You can cancel('cancel')" << std::endl;

    auto future = std::async(std::launch::async, []() {
        std::cin>>iptalGirdisi;
        return iptalGirdisi;
    });

    if (future.wait_for(std::chrono::seconds(5)) == std::future_status::ready) {
        if (iptalGirdisi == "cancel") {
            cancelPrint();
            return;
        }
    }
    Login::clearScreen();
    std::cout << "Printed file." << std::endl;
    Quality::getproperties();
    secondprint();
    Document::document();
}
void Printer::cancelPrint() {
    std::cout << "Cancelled printing." << std::endl;
    std::cout<<" Would you like to print another file(yes/no)"<<std::endl;
    std::cin>>second_print;
    if (second_print=="yes") {
        Document::document();
    }
}
void Printer::secondprint(){
    std::cout<<"Would you like to print another file(yes/no please write double)"<<std::endl;
    std::cin>>second_print;
    if (second_print=="yes") {
        
    }else{exit(0);}
}
