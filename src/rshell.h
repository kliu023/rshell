#ifndef RSHELL_H
#define RSHELL_H
#include <vector>
#include <string>
#include "Parsed.h"
#include "Executable.h"
#include "Base.h"
#include "Arguments.h"
#include "Connector.h"

using namespace std;

class rshell{
    private:
        string input; //user's input 
        vector<string> cmds;
        Parsed execs; //class name for the parsed
    
    public:
        bool run(vector<string>);
        void getCmd();//get userinput
        void execute();
};
#endif
