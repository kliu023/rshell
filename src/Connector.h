#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "Base.h"
#include <string>
using namespace std;
class Connector : public Base{
    private:
        const string NXT, AND, XOR;
    public:
        Connector(string input);
        
        //returns true/false based on connector type and whether the parameter is true/false
        bool doNext(bool passed); 
        
        //returns string of the type of connector
        const string getData(); 
        virtual const string getType();
};
#endif
