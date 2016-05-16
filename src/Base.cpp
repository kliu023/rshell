Base::Base(string input){data = input;};
virtual const string Base::getType(){return "Base";};
virtual const string Base::getData(){return data;};
virtual bool Base::doNext(bool input){return true;};
