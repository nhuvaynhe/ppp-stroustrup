/*
	Question 2.
    Page 253
    Date: 30/03/2023
    Provide an assignment operator, =.
*/

#include "std_lib_facilities.h"

//define constants used for controlling the program
const char let = 'L';
const char constvar = 'C';     // constant name token
const char Pexit = 'E';
const char print = ';';
const char number = '8';
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
	Token get();
	void unget(Token t) { 					// Put the token back to the stream
                buffer=t; full=true; 
        }
	void ignore(char);
};
//actually define get() function in Token class
Token Token_stream::get()
{
	if (full) { full=false; return buffer; }
	char ch;
	cin.get(ch);            //does not skip whitespace
    while (isspace(ch)){    //if ch is whitespace
        if (ch == '\n') return Token(print);    //print result
        
        cin.get(ch);    ///print result
    }
    
	switch (ch) {
		case '(':
        case ')':
        case '+': case '-': case '*': case '/':
        case '%':
        case ';':		// Print the result
        case ',':
		case '=':
		case '#':
			return Token(ch);
		case 'H': case 'h':
			return help;
		case '.':
		case '0':case '1':case '2':case '3':case '4':
		case '5':case '6':case '7':case '8':case '9': {	
			cin.unget();
			double val;
			cin >> val;
			return Token(number,val);
			}
		default: {
            //do this if ch is a letter
			if (isalpha(ch) || ch == '_') {  		// Allow the underscores
				string s;
				s += ch;

                //while there are still chars in cin, read them into s
				while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s+=ch;
				cin.unget();

                //if string is equal to other commands defined below, return them
				if (s == "let") return Token(let);
                if (s == "constvar") return Token(constvar);
				if (s == "exit") return Token(Pexit);
				if (s == "sqrt") return Token(root);
				if (s == "help") return Token(help);
				if (s == "pow")  return Token(pows);
				return Token(name,s);
			}

            //if the char does not fit any of these paramenters return an error message
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
    string const_name;
	double value;
	// Constructor that takes both variable name and constant name
    Variable(string n, string cons, double v) 
        :name(n), const_name(cons), value(v) { }
	
    // Constructor that takes only variable name and value
    Variable(string n, double v) : Variable(n, "", v) { }
 
};

class Symbol_table {
public:
    vector<Variable> var_table;
    
    double get(string s);
    void set(string s, double d);
    bool is_declared(string s);

};
//------------------------------------------------------------------------------

Symbol_table sb;
Token_stream ts;

//------------------------------------------------------------------------------

double Symbol_table::get(string s) {							// Get a value from input string
	for (int i = 0; i<sb.var_table.size(); ++i)
		if (sb.var_table[i].name == s) return sb.var_table[i].value;
	error("get: undefined name ",s);
	return 0;
}

void Symbol_table::set(string s, double d){						// Put a new value into name
	for (int i = 0; i<sb.var_table.size(); ++i) {
        if (sb.var_table[i].const_name == s) error("can't change value of const var");
        else if (sb.var_table[i].name == s) {
			sb.var_table[i].value = d;
			return;
		}
    }
	error("set: undefined name ",s);
}

bool Symbol_table::is_declared(string s){								// Check whether the name has been declared
	for (int i = 0; i<sb.var_table.size(); ++i)
		if (sb.var_table[i].name == s) return true;
	return false;
}
//------------------------------------------------------------------------------

double expression();

//------------------------------------------------------------------------------
double primary(){
	Token t = ts.get();
	switch (t.kind) {
		case '(': {
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error("')' expected");
			return d;
		}
		case '-':
			return - primary();

		// for sqrt
		case root: {
			double d = expression();
			if(d<0)error("cant be negative");
			else{
				double final = sqrt(d);
				return final;
			}
		}
		case pows: {
			t=ts.get();
	        if (t.kind != '(') error("'(' expected");
	        double d=expression();
	        t=ts.get();
	        if (t.kind!=',') error("',' expected");
	        double i = narrow_cast<int>(expression());
	        t=ts.get();
	        if (t.kind != ')') error("')' expected");
	        return pow(d,i);
		}
	    // number = '8'
		case number:
			return t.value;
		// name = 'a'
		case name:
			return sb.get(t.name);
		case '=':
			return primary();
		default:
			error("primary expected");
	}
	return 0;
}

//------------------------------------------------------------------------------

double term(){
	double left = primary();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*':
		{
			left *= primary();
			break;
		}
		case '/':
		{	
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		case '%':
        {
            double d = primary();
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

double expression(){
	double left = term();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
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

//------------------------------------------------------------------------------
double setconst(){      //Set a constvalue
    Token t = ts.get();
	if (t.kind != 'a' && t.kind != '_') error ("name expected in declaration");
	string name = t.name;
	if (sb.is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name);
	double d = expression();
	sb.var_table.push_back(Variable(name,name,d));
	return d;
}
//------------------------------------------------------------------------------
double declaration(){
	Token t = ts.get();
    string name;
	if (t.kind != 'a' && t.kind != '_') error ("name expected in declaration");
    name = t.name;
	if (sb.is_declared(name)) 
    {   
        cout<<"This name has been declared twice!"
            <<"\nDo you want to change it value? [Y/N]\n";
        char yes_no;
        while (cin >> yes_no){;
            if (yes_no == 'N') return 0;
            else if (yes_no == 'Y'){    // Start to set a new value
                cout << "Input value you want to change \n" <<prompt;
                double d2 = expression();
                sb.set(name, d2);
                cout << "New value is of "<<name<<" is: ";
                return d2;
            }
        }
    }
    Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name);
	double d = expression();
	sb.var_table.push_back(Variable(name,d));
	return d;
}

//------------------------------------------------------------------------------

double statement(){
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration();
    case constvar:
        return setconst();
	default:
		ts.unget(t);
		return expression();
	}
}

//------------------------------------------------------------------------------

void clean_up_mess(){
	ts.ignore(print);
}

//------------------------------------------------------------------------------
void showhelp(){
	cout << "\nYou are allowed to use +,-,*,/,sqrt(), and pow()\n\n";
	cout << "Once you are done entering an expression, enter a ';' to execute the expression.\n";
	cout << "pow() is used in the following syntax: pow(<number to be raised>,<number to raise it to>)\n\n";
	
 	cin.clear();
 	cin.ignore(10000, '\n'); //clear the buffer for new values
}
void calculate(){
	while(true) try {
		cout << prompt;
		Token t = ts.get();

		// print = ';'
		while (t.kind == print) t=ts.get();
		// quit = 'Q'
		if (t.kind == help){
			showhelp();
			cout << prompt;
			Token t = ts.get();
		}
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
    	sb.var_table.push_back(Variable("pi","pi", 3.14159));
    	sb.var_table.push_back(Variable("e", "e", 2.718281828));
    	sb.var_table.push_back(Variable("k", "k", 1000));

		cout<<"\tWelcome to our simple calculator. \n"
            <<"\tPlease enter expressions using floating-point numbers. \n"
            <<"\tEnter 'help' for instruction of the program \n"
			<<"\tEnter 'quit' to exit the program \n"
            <<"\tIf there are any error, press ';'\n"
            <<"\tFor constant value, type 'constvar'\n";

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