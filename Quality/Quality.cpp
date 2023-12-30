//
//  Quality.cpp
//  Pdf_Printer
//
//  Created by Ahmet Sezgin on 29/12/2023.
//

#include "Quality.hpp"
std::string Quality::filePath;
std::string Quality::pagecount;
std::string Quality::color;
std::string Quality::size;
std::string Quality::frontback;
Quality::Quality(const std::string&new_FilePath,const std::string&new_PageCount,const std::string & New_Color,const std::string&New_Size,const std::string&New_FrontBack):Document(filePath, pagecount, color, size, frontback){
}

void Quality::getproperties(){
    std::cout<<"Quality Control Message:\n\n\n";
    std::cout<<"Your ";
    getsize();
    std::cout<<" size file has been printed ";
    getpagecount();
    std::cout<<" times in ";
    getcolor();
    std::cout<<" format ";
    getfrontback();
    std::cout<<"\n";
}
