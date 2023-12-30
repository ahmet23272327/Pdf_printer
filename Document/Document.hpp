//
//  Document.hpp
//  Pdf_Printer
//
//  Created by Ahmet Sezgin on 28/12/2023.
//
#ifndef Document_hpp
#define Document_hpp

#include <iostream>
#include <string>

class Document {
protected:
    static std::string filePath;
    static std::string pagecount;
    static std::string color;
    static std::string size;
    static std::string frontback;
public:
    Document(const std::string &filePath,const std::string &pagecount,const std::string &color,const std::string &size,const std::string &frontback);
    void ensurePdfExtension();
    static void document();
    static void getpagecount();
    static void getcolor();
    static void getsize();
    static void getfrontback();
};

#endif /* Document_hpp */
