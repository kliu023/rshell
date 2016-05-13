#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "Base.h"
#include <string>
using namespace std;
class Connector : public Base{
    private:
        const string NXT, AND, XOR;
    public:
        Connector(string input): data(input), NXT(";"), AND("&&"), XOR("||"){};
        
        //returns true/false based on connector type and whether the parameter is true/false
        bool doNext(bool passed){
            if(connector.compare(NXT)==1){ //if ;
                return true;
            }
            else if(connector.compare(AND)==1){ //if &&
                if(passed==true)
                    return true;
                else
                    return false;
            }
            else{ //if ||
                if(passed==true)
                    return false;
                else
                    return true;
            }
        }; 
        
        //returns string of the type of connector
        const string getData(){return data;}; 
        virtual const string getType(){return "conn";};
};
#endif