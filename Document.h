#ifndef Document_h
#define Document_h

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
    Document(const std::string& filePath, const std::string& pagecount, const std::string& color, const std::string& size, const std::string& frontback);
    
    void ensurePdfExtension();// // Convert the pdf if necessary
    static void document();//runner function of the class
    static void getpagecount();// memorize info
    static void getcolor();// memorize info
    static void getsize();// memorize info
    static void getfrontback();// memorize info
};

#endif /* Document_hpp */
