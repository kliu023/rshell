#ifndef BASE_H
#define BASE_H
#include <string>
using namespace std;
class Base{
    private:
        const string data;
    public:
        Base(){};
        virtual const string getType(){return "Base";};
        virtual const string getData(){return data;};
};
#endif