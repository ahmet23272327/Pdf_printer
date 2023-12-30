#ifndef runner_hpp
#define runner_hpp

#include <iostream>
#include <string>
#include "Document.hpp"
#include "Printer.hpp"
#include "Login.hpp"

class Runner {
public:
    void run();
private:
    std::string filePath;
};

#endif /* runner_hpp */
