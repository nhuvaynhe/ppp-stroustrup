// Calculator program
// Not a question, self-study
// 22/03/2023

/*
    Simple calculator.
    An updated version from the book.

    The grammar for input is:

    Statement:
        Expression
        Print
        Quit
    
    Print:
        =
    
    Quit:
        e
    
    Expression:
        Term
        Expression + Term
        Expression - Term
    
    Term: 
        Primary
        Term * Primary
        Term / Primary
        Term % Primary

    Primary:
        Number
        ( Expression )
        - Primary
        + Primary
    
    Number:
        floating-point-literal

    Input come from cin through the Token_stream called ts
*/

#include "std_lib_facilities.h"

const char number = '8';         // t.kind==number means that t is a number Token
const char quit = 'e';           // t.kind==quit means that t is a quit Token
const char print = '=';          // t.kind==print means that t is a print Token
const string prompt = "> ";
const string result = "Answer: ";     // used to indicate that what follows is a result
const char name = 'a';          // name token
const char let = 'L';           // declaration token
const string declkey = "let";   // delcaration keyword
//-----------------------------------------------------------------
class Token{
public:
    char kind;          // what kind of token
    double value;       // for number
    string name;
    Token (char ch): kind(ch), value(0) { }
    Token (char ch, double val): kind(ch), value(val) { }
    Token (char ch, string n): kind{ch}, name{n} { } 
};
//-----------------------------------------------------------------
class Token_stream {
    public:
        Token get();        // get a Token
        void putback(Token t);  // put a token back
        void ignore(char c);    // discard character up to and including a c
    private:
        bool full = false;      // is there a Token in the buffer?
        Token buffer = {'0'};   // here is where we keep the Token put back
};

//-----------------------------------------------------------------
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;     // copy Token t to buffer
    full = true;    // buffer is now full
}

Token Token_stream::get()
{
    if (full){
        //remove Token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;  // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch){
        case print:   // for print
        case quit:   // for exit
        case '(':
        case ')': 
        case '{': 
        case '}': 
        case '%':
        case '!':
        case '+': case '-': case '*': case '/': 
            return Token(ch);
        case '.':
        case '0': case '1': case '2': case '3': case '4':  
        case '5': case '6': case '7': case '8': case '9': 
            {
                cin.putback(ch);      // put digit back the input stream
                double val;
                cin >> val;
                return Token{number, val};
            }
        default:
            if (isalpha(ch)) {
                string s;
                s += ch;
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;
                cin.putback(ch);
                if (s==declkey) return Token(let); // declaration keyword
                return Token{name, s};
            }
            error("Bad token");
    }
    return 0;
}

void Token_stream::ignore(char c)
// c present the kind of Token
{
    // first look in buffer:
    if (full && c == buffer.kind){
        full = false;
        return;
    }
    full = false; 

    // now search input:
    char ch = 0;
    while (cin>>ch)
        if (ch==c) return;
}
//-----------------------------------------------------------------
class Variable {
    public: 
        string name;
        double value;
        Variable(string n, double v) :name(n), value(v) { }

};

vector<Variable> var_table;

double get_value(string s)
    // return the value of the Variable named s
{
    for (const Variable& v : var_table)
        if (v.name == s) return v.value;
    error("get undefined variable", s);
}

void set_value(string s, double d)
    // set the Variable named s to d
{
    for (Variable& v : var_table)
        if (v.name == s) {
                v.value == d;
                return;
        }
    error("set: undefined variable ",s);
}
//-----------------------------------------------------------------

Token_stream ts;        // provide get() and putback ()

//-----------------------------------------------------------------

double expression();

//-----------------------------------------------------------------
//deal with number and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind){
        case '(':
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case '{':
        {
            double d2 = expression();
            t = ts.get();
            if (t.kind != '}') error("'}' expected");
            return d2;
        }
        
        case '-':
            return - primary();

        case '+':
            return primary();
        
        case number:
            return t.value;

        default:
            error("primary expected");
    }
    return 0;
}
//-----------------------------------------------------------------
double subterm()
{   
    double left = primary();
    Token t = ts.get();

    while (true){
        switch (t.kind){
            case '!':
            {
                int x = left;
                int sum = 1;

                if (x == 0) sum = 1;
                else for (int i = x; i > 0; i = i - 1){
                    sum *= i;
                }
                
                left = sum;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}
//-----------------------------------------------------------------
double term()
{
    double left = subterm();
    Token t = ts.get();

    while (true){
        switch (t.kind) {
            case '*':
                left *= subterm();
                t = ts.get();
                break;
            case '/':
            {
                double d = subterm();
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
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
                ts.putback(t);
                return left;
        }
    }
}
//-----------------------------------------------------------------
double expression()
{
    double left = term();
    Token t = ts.get();

    while (true) {
        switch (t.kind){
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
            default:
                ts.putback(t);
                return left;
        }
    }
}

//-----------------------------------------------------------------
bool is_declared(string var)
    // is var already in var_table?
{
    for (const Variable& v : var_table)
        if (v.name == var) return true;
    return false;
}

double defind_name(string var, double val)
    // add (var,val) to var_table
{
    if (is_declared(var)) error(var," declared twice");
    var_table.push_back(Variable(var,val)); 
    return val;
}

double declaration()
    // assume we have seen "let"
    // handle: name = expression
    // declare a variable called "name" with the initial value "expression"
{
    Token t = ts.get();
    if (t.kind != name) error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error(" = missing in declaration of", var_name);

    double d = expression();
    defind_name(var_name, d);
    return d;
}

//-----------------------------------------------------------------

double statement()
{
    Token t = ts.get();
    switch (t.kind) {
        case let: 
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}

void calculate()
{
    while (cin) 
    try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t=ts.get();
            if (t.kind == quit) {
                    return;
            }
        ts.putback(t);
        cout << result << statement() << '\n';
    }
    catch (exception& e) {                  // Recovering from errors
        cerr << e.what() << '\n';
        clean_up_mess();
    }
}

//-----------------------------------------------------------------
int main()
try
{
    //predefine names:
    names.push_back(Variable("pi", 3.14159));
    names.push_back(Variable("e", 2.718281828));
    names.push_back(Variable("k", 1000));

    cout<<"\tWelcome to our simple calculator. \n"
            <<"\tPlease enter expressions using floating-point numbers. \n"
            <<"\tEnter 'e' to exit the program \n";
    calculate();
    keep_window_open();       // cope with Windows console mode
    return 0;
}
catch (runtime_error& e) {
    cerr << e.what() << '\n';
    keep_window_open("~~");
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open("~~");
    return 2;
}
