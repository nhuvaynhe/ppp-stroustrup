//Finding the repeated word in a sentence

#include <iostream>
using namespace std;

int main()
{
    string previous=" ";   // previous word, initialized to "not a word"
    string current;         // current word
    int flag = 0;
    while (cin>>current && flag != 8){   // read a stream of word
        if (previous == current)     // check if the word is the same as last
            cout<<"repeated word: "<<current<<'\n';
        previous = current;
        ++flag;
    }
}