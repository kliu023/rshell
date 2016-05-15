#ifndef BASE_H
#define BASE_H
#include <string>
using namespace std;
class Base{
    protected:
        string data;
    public:
        Base(){};
	Base(string input){data = input;};
        virtual const string getType(){return "Base";};
        virtual const string getData(){return data;};
        virtual bool doNext(bool input){return true;};
};
#endif
