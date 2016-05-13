#include <string.h>
#include "CmdShell.h"
#include "Parsed.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <algorithm>



void CmdShell::getCmd(){
    cout << "$ ";
    // cin >> input; //will not work since cin >> input will only get the first word
    getline(cin,input);
    execs.parseInput(input);
}


bool run(vector <char*> command)
{

    int pid = fork(); 
    if(pid < 0) //this retunrns false
    {
        perror("Forking Error");
        exit(0);
    }
    else if(pid == 0) //this is the child counter
    {
        if(execvp(command[0], &command[0]) < 0)
        {
            perror("exec");
            exit(1);
        }
        return true;
    }
    else if(pid > 0) //this is the parent counter
    {
        int start;
        if(waitpid(pid, &start, 0) == -1)
        {
            perror("Wait Error");
        }
        return true;
    }
    return false;
}


void execute(){
    string command;
    int size;
    int index;
    int numArgs=0;
    bool success;
    
    for(int i = 0; i < execs.size(); ++i){
            command = execs.at(i)->getData(); //commands[0]
            while(execs.at(i+numArgs)->getType().compare("conn") != 0 && i+numArgs < execs.size())
                numArgs++;
            string commands[numArgs+1];
            commands[0] = command;
            for(int j = 1; j <= numArgs; ++j)
                commands[j] = execs.at(i+j)->getData();
            i += numArgs;
            success = execvp(commands[0], &commands);
            if(){ //check if there are more inside execs (is i still less than size)
                //the next one is going to be the connector
                
            }
            
    }
    string type;
    
    
    
    string commands[size];
    (store commands)
    run commands
    // vector <char*> commands;
    
    vector <string> par;
    bool previous = true, comments = false;
    
    //what does this do? while(true) will make it be stuck in an infinite loop
    // while(true)
    // {
    //     command.clear();
    //     par.clear();
    //     comments = false;
    //     previous = true;
    // }
    
    
    for(int i = 0; i < par.size(); ++i){
        if (comments == true)
        { 
        }
            
        // else if (strcmp(command.at(command.size() - 1), "exit") == 0 && command.size() == 1) { 
        // else if (command.at(command.size()-1).compare("exit")==0 && command.size() == 1){
            // exit(0);
        // }
            
//             else if (strcmp(command.at(command.size() - 1),"&&") == 0) {
//                 if (previous == true) {
//                     command.pop_back(); 
//                     run(command);
//                 }
//                 command.clear();
//                 previous = true;
//             }
            
//             else if (str.compare(command.at(command.size() - 1), ";") == 0) {
//                 if (previous == true) {
//                     command.pop_back();
//                     previous = run(command);
//                 }
//                 else {
//                     previous = false;
//                 }
//                 command.clear();
//             }
            
//             else if (str.compare(command.at(command.size() - 1), "||") == 0) {
//                 if (previous == true) {
//                     command.pop_back();
//                     previous = !run(command);
//                 }
                
//                 else {
//                     previous = true;
//                 }
                
//                 command.clear();
//             } 
//             else if (str.compare(command.at(command.size() - 1), "#") == 0) {
//                 comments = true;
//                 command.pop_back();
//                 run(command);
//             }
            
//             else {};  
//         }
        
//         if (command.size() > 0 && !comments && previous) {
//             run(command);
//         }

    
    }  
//     }
}
    // string command;
    // string connector = ";","||","&&";
    // string next;
    // bool doNext = true;
    // if(next == -1)
    // {
    //     doNext = false;
    // }
    // while(doNext){
    //     next = execs.getNext();
    //     if(next == connector) //this means it is not argument list 
    //     {
    //         execute(command)
    //         connector = next
    //     }
    //     else{
    //         execute(command, next) //next is arglist
    //         connector = exec.getNext();
    //     }
    //     // if(execute returns true)
    //     //     do you run next command
    //     //     break out if not (break;)
            
    // }
    
    // if(next == connector || next == -1)
    //     execvp
    
// }




