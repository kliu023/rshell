#ifndef RSHELL_H
#define RSHELL_H

#include <vector>
#include <string>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <errno.h>
#include "Parsed.h"

using namespace std;

class rshell{
    private:
        string input; //user's input 
        vector<string> cmds;
        Parsed execs; //class name for the parsed
    
    public:
        rshell();
        bool run(vector<string>);
        void getCmd();//get userinput
        void execute();
};
#endif
