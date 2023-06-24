// Calculator program
// Not a question, self-study
// 22/03/2023

#include "std_lib_facilities.h"

const char number = '8';    // t.kind==number means that t is a number Token
const char quit = 'e';         // t.kind==quit means that t is a quit Token
const char print = '=';         // t.kind==print means that t is a print Token
const string prompt = "> ";
const string result = "Answer: ";        // used to indicate that what follows is a result
//-----------------------------------------------------------------
class Token{
public:
    char kind;          // what kind of token
    double value;       // for number
    Token (char ch)
        :kind(ch), value(0) { }
    Token (char ch, double val)
        :kind(ch), value(val) { }
};
//-----------------------------------------------------------------
class Token_stream {
    public:
        Token get();        // get a Token
        void putback(Token t);  // put a token back
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

//-----------------------------------------------------------------
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
            error("Bad Token");
    }
    return 0;
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
void calculate()
{
    while (cin) {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t=ts.get();
            if (t.kind == quit) {
                    return;
            }
        ts.putback(t);
        cout << result << expression() << '\n';
    }
}

int main()
try
{
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