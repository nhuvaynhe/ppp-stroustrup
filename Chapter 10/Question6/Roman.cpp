/*
    Question 6.
    Chapter 10, page 377.

    Convert 'Roman' to integer
*/

#include "std_lib_facilities.h"

class Roman
{
public:
    Roman(char r, int i) : roman{r}, roman_int{i} {}
    Roman();
    void as_int();
    int roman_int;
    char roman;
};
//-----------------------------------------------------------
Roman::Roman() { } 

bool isRoman(char c)
{
    if (c =='I' || c =='V' || c =='X' || c =='L' ||
        c =='C' || c =='D' || c =='M') 
    {
        return true;
    }
    else return false;
}

istream& operator>>(istream& is,Roman& r)
{   
    char c;
    is >> c;
    if (!isRoman(c)) error("NOT A ROMAN");
    if (!is) return is;

    switch(c){
        case 'I': r = Roman(c, 1); break;
        case 'V': r = Roman(c, 5); break;
        case 'X': r = Roman(c, 10); break;
        case 'L': r = Roman(c, 50); break;
        case 'C': r = Roman(c, 100); break;
        case 'D': r = Roman(c, 500); break;
        case 'M': r = Roman(c, 1000); break;
    }

    return is;
}
//-----------------------------------------------------------
bool checkRomanOrder(Roman& r, char& pre)
{
    switch(pre) {
        case 'I':
            if (r.roman == 'V') {
                    r.roman_int = 3;
                    pre = 'I';
                    return true;
            }
            if (r.roman == 'X') {
                    r.roman_int = 8;
                    pre = 'V';
                    return true;
            }
            // other case
            if (r.roman != 'I') return false; 
            // fall-through
        case 'V':
            if (r.roman != 'I' && r.roman != 'V') {
                return false; 
            }
            // fall-through
        case 'X':
            if (r.roman == 'C') {
                    r.roman_int = 80;
                    pre = 'X';
                    return true;
            }
            if (r.roman == 'L') {
                    r.roman_int = 30;
                    pre = 'X';
                    return true;
            }
            // other case
            if (r.roman != 'X' && r.roman != 'V' && r.roman != 'I'){
                return false; 
            }
            // fall-through
        case 'L':
            if (r.roman == 'C' || r.roman == 'D' || r.roman == 'M') {
                return false; 
            }
            // fall-through
        case 'C':
            if (r.roman == 'D') {
                    r.roman_int = 300;
                    pre = 'L';
                    return true;
            }
            // other case
            if (r.roman == 'D' || r.roman == 'M') {
                return false; 
            }
            // fall-through
        case 'D':
            if (r.roman == 'M') return false; 
            // fall-through
        default:
            // If the previous character was not recognized, 
            // there is no valid ordering to check, so return true.
            pre = r.roman;
            return true;
    }
}
//-----------------------------------------------------------
int main()
{
    cout << "Input roman character" << endl;
    Roman r;
    string roman;

    int sum = 0;
    char previous = 'M';

    for (int i=0; i<7; ++i)
    {   
        cin >> r;
        if (!checkRomanOrder(r, previous)) { 
            cout << "Wrong order!" << endl;
            cin.clear();
            cin.ignore(10000,'\n');
            --i;
        }
        else {
            sum += r.roman_int;
            roman.push_back(r.roman);

        }
    }

    cout << roman << '\t' << sum;
}