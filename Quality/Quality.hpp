//
//  Quality.hpp
//  Pdf_Printer
//
//  Created by Ahmet Sezgin on 29/12/2023.
//

#ifndef Quality_hpp
#define Quality_hpp

#include <iostream>
#include <string>
#include "Document.hpp"
class Quality:public Document{
private:
    static std::string filePath;
    static std::string pagecount;
    static std::string color;
    static std::string size;
    static std::string frontback;
public:
    Quality(const std::string &filePath,const std::string &pagecount,const std::string &color,const std::string &size,const std::string &frontback);
    static void getproperties();
};

#endif /* Quality_hpp */
