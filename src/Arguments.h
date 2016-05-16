#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include "Base.h"
using namespace std;
class Arguments : public Base{
    public:
        Arguments(string input);
        virtual const string getType();
};
#endif
