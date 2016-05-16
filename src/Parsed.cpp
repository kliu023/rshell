#include "Parsed.h"

Parsed::Parsed():tokNext(";"), tokSucc("&&"), tokFail("||"), tokComm("#"){isExec = true;}

void Parsed::parseInput(const string& input){//passes in each string seperated by spaces through parseWord
    string temp; 
    size_t comm;
    char* next = strtok(const_cast<char*>(input.c_str())," ");
    do{
        temp = next;
	comm = temp.find(tokComm);
	if(comm!=std::string::npos){
	    temp = temp.substr(0,comm);
	    parseWord(temp);
	    break;
	}
        parseWord(temp);
        next = strtok(NULL, " ");
    } while(next != NULL);
}

void Parsed::addWord(const string input){//pushes given input to exec/arg. if isExec is true, sets it to false
    if(isExec){
        isExec = false;
        cmds.push_back(new Executable(input));
    }
    else
        cmds.push_back(new Arguments(input));
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
            addWord(str);
            break;
        }
        else if(str.compare(tokNext)==0 || str.compare(tokSucc)==0 || str.compare(tokFail)==0){//if one of the connectors
            addConnector(str);
            break;
        }
        else if(index == 0){
            if(str.at(0) == ';'){
                temp = str.substr(0,1);
                addConnector(temp);
                str = str.substr(1);
            }
            else{
                temp = str.substr(0,2);
                str = str.substr(2);
                addConnector(temp);
            }
        }
        else{
            temp = str.substr(0, index);
            addWord(temp);
            str = str.substr(index);
        }
        index = str.find_first_of(";&|");
    }
}

Base* Parsed::at(const int i){
    return cmds.at(i);
}

int Parsed::size(){
    return cmds.size();
}

