#ifndef EXECUTABLE_H
#define EXECUTABLE_H

#include "Base.h"
#include <string>
using namespace std;

class Executable : public Base{
    public:
        Executable(string input):data(input){};
        virtual const string getType(){return "exec";};
};
#endif