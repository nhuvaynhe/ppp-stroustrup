//Convert characters into number

#include <iostream>
using namespace std;

int main()
{
   cout<<"Enter the character you want to convert: ";
   string word;
   cin >> word;

   int zero = 0;
   int one = 1;
   int two = 2;
   int three = 3;

   if (word == "zero"){
    cout<<zero;
   } 
   else if (word == "one"){
    cout<<one;
   }
   else if (word == "two"){
    cout<<two;
   }
   else if (word == "three"){
    cout<<three;
   }
   else{
    cout<<"Not a number i known!";
   }
}