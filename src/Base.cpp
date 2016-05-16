#include "Base.h"
Base::Base(string input){data = input;}
const string Base::getType(){return "Base";}
const string Base::getData(){return data;}
bool Base::doNext(bool input){return true;}
