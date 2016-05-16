#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "Base.h"
#include <string>
using namespace std;
class Connector : public Base{
    private:
        const string NXT, AND, XOR;
    public:
        Connector(string input):NXT(";"), AND("&&"), XOR("||"){data=input;};
        
        //returns true/false based on connector type and whether the parameter is true/false
        bool doNext(bool passed){
            if(data.compare(NXT)==0){ //if ;
                return true;
            }
            else if(data.compare(AND)==0){ //if &&
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
