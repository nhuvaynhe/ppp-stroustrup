//"Bleep" out the words i don't like

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> banned_word = {"broccoli", "spinach", "dream", "bts"};
    vector<string> sentence;
    
    for (string letter; cin>>letter; ){                     //Ctrl + Z to break a program
        for (string j : banned_word){
            if (letter == j)
                letter = "BLEEP";
        }
        sentence.push_back(letter);
    }
    
    cout<<"\n Sentence produced: \n";
    
    for (string i : sentence){
        cout<<i<<" ";
    }  
}