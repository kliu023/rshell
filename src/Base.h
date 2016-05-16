#ifndef BASE_H
#define BASE_H

#include <string>
using namespace std;
class Base{
    protected:
        string data;
    public:
        Base(){};
	    Base(string input);
        virtual const string getType();
        virtual const string getData();
        virtual bool doNext(bool input);
};
#endif
