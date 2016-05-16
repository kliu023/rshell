#ifndef PARSED_H
#define PARSED_H

#include <string.h>
#include <vector>
#include <iostream>
#include "Executable.h"
#include "Arguments.h"
#include "Connector.h"
#include <stdio.h>

using namespace std;
class Parsed{
    private:
        const string tokNext, tokSucc, tokFail, tokComm; // connectors
        bool isExec; //returns true if addWord should push back exec type
        vector<Base*> cmds;
        void parseWord(const string&); //parses string containing connectors with no spaces
        void addWord(const string input);//pushes given input to exec/arg. if isExec is true, sets it to false
        void addConnector(const string input);//pushes given connector to cmds. sets isExec to true
    
    
        
    public:
        Parsed();
        Base* at(const int i); //returns inputs.at(index), then increments it by 1
        void parseInput(const string& input); //parses given string input
        int size(); //returns size of cmds
       
        
        
};
#endif
