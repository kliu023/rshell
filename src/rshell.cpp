#include <string.h>
#include "rshell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <errno.h>



void rshell::getCmd(){
    cout << "$ ";
    getline(cin,input);
    execs.parseInput(input);
}

bool rshell::run(vector<string> cmds)
{
    int status;
    bool result=true;
    char* commands = new char[cmds.size()];
    if(cmds.at(0).compare("exit")==0)
        exit(1);
    for(unsigned i = 0; i < cmds.size(); ++i){
        commands[i] = *const_cast<char*>(cmds.at(i).c_str());
    }
    pid_t pid = fork();
    if(pid < 0) //this retunrns false
    {
        perror("Forking Error");
        exit(0);
    }
    else if(pid == 0) //this is the child counter
    {
        
        if(execvp(&commands[0], &commands) < 0)
        {
            perror("exec");
            result = false;
        }
        result = true;
    }
    else{
        while (wait(&status) != pid);      /* wait for completion  */
        return result;
    }
    return result;
}


void rshell::execute()
{
    string command;
    int numArgs;
    bool success;
    for(int index = 0; index < execs.size(); ++index){
        numArgs = 0;
        cmds.clear();
        cmds.push_back(execs.at(index)->getData());
        while(index+numArgs+1 < execs.size()){
            if(execs.at(index+numArgs+1)->getType().compare("args")==0){
                cmds.push_back(execs.at(index+numArgs+1)->getData());
                ++numArgs;
            }
            else
                break;
        }
        index+= numArgs;
        success = run(cmds);
        if(index+1 < execs.size()) //check if there are more inside execs(see if is less than size)
        {
            ++index; //index is now at connector
            if(!execs.at(index)->doNext(success))
            {
                index+= 2;
                while(index < execs.size()){
                    if(execs.at(index)->getType().compare("exec")!= 0)
                    {
                        ++index; //if it is not executable then keep increment it untill you find it
                    }
                    else
                        break;
                }
                --index;
            }
        }
   } 
}

// int main(){
//     rshell cmd;
//     cmd.getCmd();
//     cmd.execute();
// }
