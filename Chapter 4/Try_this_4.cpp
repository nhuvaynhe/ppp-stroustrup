//For exercise

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char letter = 'a';

    for (int i=0; i<26; ++i) 
        cout<<(char)(letter + i)<<" "<<97 + i<<'\n';
}
