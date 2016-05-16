#include "Executable.h"

Executable::Executable(string input){data = input;}

const string Executable::getType(){return "exec";}