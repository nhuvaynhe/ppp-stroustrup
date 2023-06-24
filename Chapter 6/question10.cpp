// A 'Permutation' and 'Combination'
// A permuation takes an order to consider while a Combination does not.
// Question 10, page 219
// 25/03/2023

#include "std_lib_facilities.h"

int factorial(int num) 
{
    if (num == 0) return 1;
    int sum = 1;

    for (int i = num; i > 0; --i)
    {
        sum *= i;
    }
    return sum;
}
//-----------------------------------------------------------------------
class Number_picking {
    public:
        int Permuation(int a, int b);
        int Combination(int a, int b);
};

int Number_picking::Permuation(int a, int b)
{
    if (a == 0) error("'a' can not be equal 0");
    if (b == 0) error("You do not need any number. Can't calculate!");
    int deno = a - b;       // Abbreviation of denominator
    int mauso = factorial(deno);
    int tuso = factorial(a);
    return tuso/mauso;
}

int Number_picking::Combination(int a, int b)
{
    return a/factorial(b);
}
//-----------------------------------------------------------------------
Number_picking np; 

int main()
{
    int a;
    int b;
    cout << "Please enter two numbers ('a' and 'b'): \n";
    cin >> a >> b;
    if (!cin) error("Wrong input!");
    if (b > a) error("'b' must be lower than 'a'");
     
    char p_or_c;
    cout << "What do you want to calculate?\n";    
    cout << "\t 'P' for Permutation \n"
         << "\t 'C' for Combination \n";
    cin >> p_or_c;

    if (p_or_c == 'P' || p_or_c == 'p')
    {   
        int permu = np.Permuation(a, b);
        cout <<"For "<<a<<" number "<<b<<" different numbers. \n"
             << "There are "<<permu<<" permuations. \n";
    }
    else if (p_or_c == 'C' || p_or_c == 'c')
    {
        int tuso = np.Permuation(a, b);
        int combi = np.Combination(tuso, b);
        cout <<"For "<<a<<" number "<<b<<" different numbers. \n"
             << "There are "<<combi<<" combinations. \n";
    }
    else error("Wrong input!");

}