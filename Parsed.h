#ifndef PARSED_H
#define PARSED_H

#include <string>
#include <vector>
#include <iostream>
#include "Base.h"
#include "Executable.h"
#include "Arguments.h"
#include "Connector.h"

using namespace std;
class Parsed{
    private:
        const string tokNext, tokSucc, tokFail; // connectors
        int index; //index of current word in inputs
        bool isExec;
        vector<string> inputs; //stores input into separate words
        vector<Base*> cmds;
        void parseWord(const string&); //parses string containing connectors with no spaces
        void addWord(const string input);//pushes given input to exec/arg. if isExec is true, sets it to false
        void addConnector(const string input);//pushes given connector to cmds. sets isExec to true
    
    
        
    public:
        Parsed(): isExec(true), index(0), tokNext(";"), tokSucc("&&"), tokFail("||"){};
        string getNext(); //returns inputs.at(index), then increments it by 1
        void parseInput(const string&); //parses given string input
       
        
        
};
#endif