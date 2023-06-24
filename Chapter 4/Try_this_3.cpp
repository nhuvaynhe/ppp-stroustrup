//Loop exercise 

#include <iostream>
using namespace std;

int main()
{
    char letter = 'a';
    int i = 0;

    while (i < 26){
        cout<<(char)(letter + i)<<" "<<97 + i<<'\n';
        ++i;
    }
}