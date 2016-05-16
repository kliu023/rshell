#include <stdlib.h>
#include <iostream>
#include <string>
#include "CmdShell.cpp"

using namespace std;

void testCmdShell(){
    CmdShell cmd;
    cmd.getCmd();
    cmd.execute();
}

int main(){
    testCmdShell();
}
