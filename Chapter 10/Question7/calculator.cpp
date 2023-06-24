/*
	Question 7.
	Chapter 10, page 378.

	Make  a  version  of  the  calculator  from  Chapter  7  that  accepts  Roman 
	numerals rather than the usual Arabic ones, for example, XXI + CIV == 
	CXXV.
*/

#include "Roman.h"

//define constants used for controlling the program
const char let = 'A';
const char Pexit = 'E';
const char print = ';';
const char roman = '8';
const char name = 'a';
const char root = 'S';
const char help = 'H';
const char pows = 'P';
//------------------------------------------------------------------------------

//define token struct
struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string val) :kind(ch), name(val) { }
};

//------------------------------------------------------------------------------

//define token_stream class
class Token_stream {
private:
    bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }
	Token_stream(istream&);
	Token get();

	void unget(Token t) { 					// Put the token back to the stream
                buffer=t; full=true; 
        }

	void ignore(char);
};
//actually define get() function in Token class
string romanChars;

bool Roman_chain(char c)
{
	//a bit hacky but does the job
	switch (c)
	{
	case '(': case ')':
	case '+': case '-':
	case '*': case '/': case '%':
	case '=': case ',': 
	case let: case print:
		return false;
	default:
		romanChars += c;
		return true;
	}
}
//----------------------------------------------------------------------
Token Token_stream::get()
{
	if (full) { full=false; return buffer; }
	char ch;
	cin >> ch;

	switch (ch) {
		case '(':
        case ')':
        case '+': case '-': case '*': case '/':
        case '%':
        case ';':		// Print the result
        case ',':
		case '=':
		case '#':
			romanChars = "";
			return Token(ch);
		case 'I':case 'V':case 'X':case 'L':
		case 'C':case 'D':case 'M': {	
			while (Roman_chain(ch))
				cin.get(ch);
			cin.unget();

			int val = Roman_cal(romanChars);
			return Token(roman, val);
		}
		default: {
			if (isalpha(ch) || ch == '_') {  		// Allow the underscores
				string s;
				s += ch;
				while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s+=ch;
				cin.unget();
				if (s == "let") return Token(let);
				if (s == "exit") return Token(Pexit);
				if (s == "sqrt") return Token(root);
				if (s == "help") return Token(help);
				if (s == "pow")  return Token(pows);
				return Token(name,s);
			}
			error("Bad token");
		}
		return 0;
	}
}

void Token_stream::ignore(char c){
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin>>ch)
		if (ch==c) return;
}

//------------------------------------------------------------------------------

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};
vector<Variable> names;	

//------------------------------------------------------------------------------
double get_value(string s) {							// Get a value from input string
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ",s);
	return 0;
}

void set_value(string s, double d){						// Put a new value into name
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ",s);
}

bool is_declared(string s){								// Check whether the name has been declared
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}
//------------------------------------------------------------------------------

Token_stream ts;

//------------------------------------------------------------------------------

double expression(Token_stream& ts);

//------------------------------------------------------------------------------
double primary(Token_stream& ts){
	Token t = ts.get();
	switch (t.kind) {
		case '(': {
			double d = expression(ts);
			t = ts.get();
			if (t.kind != ')') error("')' expected");
			return d;
		}
		case '-':
			return - primary(ts);

		// for sqrt
		case root: {
			double d = expression(ts);
			if(d<0)error("cant be negative");
			else{
				double final = sqrt(d);
				return final;
			}
		}
		case pows: {
			t=ts.get();
	        if (t.kind != '(') error("'(' expected");
	        double d=expression(ts);
	        t=ts.get();
	        if (t.kind!=',') error("',' expected");
	        double i = narrow_cast<int>(expression(ts));
	        t=ts.get();
	        if (t.kind != ')') error("')' expected");
	        return pow(d,i);
		}
		case help: {
			cout << "\nYou are allowed to use +,-,*,/,sqrt(), and pow()\n\n";
			cout << "Once you are done entering an expression, enter a ';' to execute the expression.\n";
			cout << "pow() is used in the following syntax: pow(<number to be raised>,<number to raise it to>)\n\n";
		}
	    // number = '8'
		case roman:
			return t.value;
		// name = 'a'
		case name:
			return get_value(t.name);
		case '=':
			return primary(ts);
		default:
			error("primary expected");
	}
	return 0;
}

//------------------------------------------------------------------------------

double term(Token_stream& ts){
	double left = primary(ts);
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*':
		{
			left *= primary(ts);
			break;
		}
		case '/':
		{	
			double d = primary(ts);
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		case '%':
        {
            double d = primary(ts);
            if (d==0) error("Can't devide by zero");
            left = fmod(left,d);
            t = ts.get();
            break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

//------------------------------------------------------------------------------

double expression(Token_stream& ts){
	double left = term(ts);
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term(ts);
			break;
		case '-':
			left -= term(ts);
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

//------------------------------------------------------------------------------
const string prompt = "> ";
const string result = "= ";

double declaration(){
	Token t = ts.get();
	if (t.kind != 'a' && t.kind != '_') error ("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) 
    {   
        cout<<"This name has been declared twice!"
            <<"\nDo you want to change it value? [Y/N]\n";
        char yes_no;
        while (cin >> yes_no){;
            if (yes_no == 'N') return 0;
            else if (yes_no == 'Y'){
                cout << "Input value you want to change \n" <<prompt;
                double d2 = expression(ts);
                set_value(name, d2);
                cout << "New value is of "<<name<<" is: ";
                return d2;
            }
        }
    }
    Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name);
	double d = expression(ts);
	names.push_back(Variable(name,d));
	return d;
}

//------------------------------------------------------------------------------

double statement(){
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression(ts);
	}
}

//------------------------------------------------------------------------------

void clean_up_mess(){
	ts.ignore(print);
}

//------------------------------------------------------------------------------

void calculate(){
	while(true) try {
		cout << prompt;
		Token t = ts.get();

		// print = ';'
		while (t.kind == print) t=ts.get();
		// quit = 'Q'
		if (t.kind == Pexit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

//------------------------------------------------------------------------------

int main(){
	try {
		//predefine names:
    	names.push_back(Variable("pi", 3.14159));
    	names.push_back(Variable("e", 2.718281828));
    	names.push_back(Variable("k", 1000));

		cout<<"\tWelcome to our simple calculator. \n"
            <<"\tPlease enter expressions using floating-point numbers. \n"
            <<"\tEnter 'help' for instruction of the program \n"
			<<"\tEnter 'quit' to exit the program \n"
            <<"\tIf there are any error, press ';'\n";

    	calculate();
    	keep_window_open();       // cope with Windows console mode
    	return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >>c&& c!=';') ;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=';');
		return 2;
	}
}