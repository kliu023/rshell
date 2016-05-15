#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include "Base.h"
#include <vector>
using namespace std;
class Arguments : public Base{
    public:
        Arguments(string input){data = input;};
        virtual const string getType(){return "args";};
};
#endif
