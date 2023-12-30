//
//  Document.cpp
//  Pdf_Printer
//
//  Created by Ahmet Sezgin on 28/12/2023.
//

#include "Document.h"
#include "Printer.h"
std::string Document::filePath;
std::string Document::pagecount;
std::string Document::color;
std::string Document::size;
std::string Document::frontback;
Document::Document(const std::string& newFilePath, const std::string& newpagecount, const std::string& newcolor, const std::string& newsize, const std::string& newfrontback) {
    filePath = newFilePath;
    pagecount = newpagecount;
    color = newcolor;
    size = newsize;
    frontback = newfrontback;
    ensurePdfExtension();
}

void Document::ensurePdfExtension() { // Convert the pdf if necessary
    size_t dotPosition = filePath.find_last_of(".");
    if (dotPosition == std::string::npos) {
        filePath += ".pdf";
        std::cout << "Changed the extension of file to .pdf: " << filePath << std::endl;
    }
    else {
        std::string fileExtension = filePath.substr(dotPosition);
        if (fileExtension != ".pdf") {
            filePath.replace(dotPosition, fileExtension.size(), ".pdf");
            std::cout << "Changed the extension of file to .pdf: " << filePath << std::endl;
        }
    }
}

void Document::document() {//runner function of the class
    std::string inputFilePath;
    std::string inputPageCount;
    std::string inputColor;
    std::string inputsize;
    std::string inputFront_Back;
    std::cout << "Enter file name: ";
    std::cin >> inputFilePath;
    std::cout << "Enter page count: ";
    std::cin >> inputPageCount;
    std::cout << "Color/Black and White(BW for Black and White): ";
    std::getline(std::cin, inputColor);
    std::cin >> inputColor;
    std::cout << "Paper size(A4/A5): ";
    std::cin >> inputsize;
    std::cout << "Print on both sides(yes/no): ";
    std::cin >> inputFront_Back;
    if (inputFront_Back == "yes") {
        inputFront_Back = " back to front ";
    }
    else {
        inputFront_Back = "";
    }
    
    //run Document class
    Document doc(inputFilePath, inputPageCount, inputColor, inputsize, inputFront_Back);
    //run Printer class
    Printer::printDocument();
}

// memorize info
void Document::getpagecount() {
    std::cout << pagecount;
}
void Document::getcolor() {
    std::cout << color;
}
void Document::getsize() {
    std::cout << size;
}
void Document::getfrontback() {
    std::cout << frontback;
}

