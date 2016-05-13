#include <string.h>
#include <stdio.h>
#include "Parsed.h"

void Parsed::parseInput(const string& input){//passes in each string seperated by spaces through parseWord
    string temp;
    int index;
    char* next = strtok(const_cast<char*>(input.c_str())," ");
    do{
        temp = next;
        parseWord(temp);
        next = strtok(NULL, " ");
    } while(next != NULL);
}

void Parsed::addWord(const string input){//pushes given input to exec/arg. if exec is true, sets it to false
    if(isExec){
        isExec = false;
        cmds.push_back(new Executable(input));
    }
    else
        if(cmds.at(cmds.size()-1)->getType().compare("conn")){
            
        }
}

void Parsed::addConnector(const string input){//pushes given connector to cmds. sets Exec to true
    cmds.push_back(new Connector(input));
    isExec = true;
}

void Parsed::parseWord(const string& input){//parses string of connectors
    string str = input;
    string temp;
    int index = str.find_first_of(";&|");
   
    while(!str.empty()){
        if(index == -1){//if there are no connectors
            // inputs.push_back(str);
            // cmds.push_back(new Executable(str));
            break;
        }
        else if(str.compare(tokNext)==0 || str.compare(tokSucc)==0 || str.compare(tokFail)==0){//if one of the connectors
            // inputs.push_back(str);
            cmds.push_back(new Connector(str));
            break;
        }
        else if(index == 0){
            if(str.at(0) == ';'){
                temp = str.substr(0,1);
                // inputs.push_back(temp);
                cmds.push_back(new Connector(str));
                str = str.substr(1);
            }
            else{
                temp = str.substr(0,2);
                str = str.substr(2);
                // inputs.push_back(temp);
                cmds.push_back(new Connector(str));
            }
        }
        else{
            temp = str.substr(0, index);
            inputs.push_back(temp);
            str = str.substr(index);
        }
        index = str.find_first_of(";&|");
    }
}




string Parsed::getNext(){
    string temp;
    if(inputs.size()==0 || index == inputs.size())
        return "-1";
    else{
        temp = inputs.at(index);
        index++;
        return temp;
    }
}
