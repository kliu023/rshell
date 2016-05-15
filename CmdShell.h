#ifndef CMDSHELL_H
#define CMDSHELL_H
#include <vector>
#include <string>
#include "Parsed.h"
#include "Executable.h"
#include "Base.h"
#include "Arguments.h"

using namespace std;

class CmdShell{
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
