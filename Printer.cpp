#include "Printer.h"

std::string Printer::response;
std::string Printer::iptalGirdisi;
std::string Printer::second_print;
std::atomic<bool> Printer::girdiAlindi(false);

Printer::Printer(const std::string& filePath) : Document(filePath, pagecount, color, size, frontback) {
    std::cout << "Would you like to print the file? (yes/no): ";
    std::cin >> response;
    getresponse();
}
//runner of the Document Class
void Printer::printDocument() {
    Printer file_print(filePath);
}
//does it want to write the file
void Printer::getresponse() {
    if (response == "yes") {
        performPrint();
    }
    else {
        std::cout << "Printing Cancelled." << std::endl;
    }
}
//sends the file to the printer and allows the printer to cancel the outgoing file while it is printing
void Printer::performPrint() {
    std::cout << filePath << "File is printing" << std::endl;
    std::cout << "You can cancel('cancel')" << std::endl;
    //allows the user to write input during the waiting period
    auto future = std::async(std::launch::async, []() {
        std::cin >> iptalGirdisi;
        return iptalGirdisi;
        });
    //file will be ready in 5 seconds, gives you the option to cancel while the file is being written
    if (future.wait_for(std::chrono::seconds(5)) == std::future_status::ready) {
        if (iptalGirdisi == "cancel") {
            cancelPrint();
            return;
        }
    }
    Login::clearScreen();
    std::cout << "Printed file." << std::endl;
    //call the getproperties function from Quality class
    Quality::getproperties();
    secondprint();
    //runner of the Document class, provides the loop of the program
    Document::document();
}
//provide the cancel printing
void Printer::cancelPrint() {
    std::cout << "Cancelled printing." << std::endl;
    std::cout << " Would you like to print another file(yes/no)" << std::endl;
    std::cin >> second_print;
    if (second_print == "yes") {
        Document::document();
    }
}
//provide the 2nd time printing
void Printer::secondprint() {
    std::cout << "Would you like to print another file(yes/no please write double)" << std::endl;
    std::cin >> second_print;
    if (second_print == "yes") {

    }
    else { exit(0); }
}
