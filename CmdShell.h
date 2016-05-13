#ifndef CMDSHELL_H
#define CMDSHELL_H

#include <string>

using namespace std;

class CmdShell{
    private:
        string input; //user's input 
        Parsed execs; //class name for the parsed
    
    public:
        bool run(vector <char*> command);
        void getCmd();//get userinput
        void execute();
    
};
#endif