#include "Connector.h"

Connector::Connector(string input):NXT(";"), AND("&&"), XOR("||"){data=input;}

bool Connector::doNext(bool passed){
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
}

const string Connector::getData(){return data;}

const string Connector::getType(){return "conn";}