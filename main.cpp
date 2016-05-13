#include <iostream>
#include <string>
#include "Parsed.cpp"
// #include "CmdShell.cpp"

using namespace std;

void testParsed(){
    Parsed parser;
    string input = "exec1;exec2 arg1 arg2 && exec3 arg3|| exec4 &&exec5 ";
    cout << "Parsing: " << input << endl;
    parser.parseInput(input);
    
    string temp = "0";
    while(temp.compare("-1")!=0){
        temp = parser.getNext();
        cout << temp << endl;
    }
}

int main(){
    testParsed();
   
}