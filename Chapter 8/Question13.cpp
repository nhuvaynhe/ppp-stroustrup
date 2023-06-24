/*
	Question 11.
    Chapter 8, page 301
    Date: 04/04/2023
    Write a function return number of characters of string.
    Longest and shortest string.
    Lexicographically first and last string.
*/

#include "std_lib_facilities.h"

vector<int> getstringLength(vector<string> v)
{   
    vector<int> length;

    if (v.size() == 0) cout << "Empty vector!";
    
    for (string s : v){
        length.push_back(s.length());
    }

    return length;
}

//-------------------------------------------------------

struct stringInfo
{
    vector<string> longWords, shortWords;
    string first, last;
    string longest, shortest;
};

stringInfo getstringInfo(const vector<string>& v)
{
    vector<string> temp = v;
    stringInfo si;

    sort(temp.begin(), temp.end());
    si.first = si.longest = si.shortest = temp[0];
    si.last = temp.back();

    for (int i = 0; i < temp.size(); ++i)
    {
        if (si.longest.size() < temp[i].size()){
            si.longest = temp[i];
        }

        if (si.shortest.size() > temp[i].size()){
            si.shortest = temp[i];
        }
    }

    for (string s : v)
    {
        if (s.size() == si.longest.size()) si.longWords.push_back(s);
        if (s.size() == si.shortest.size()) si.shortWords.push_back(s);
    }

    return si;  // Return all the element in struct 'si'
}

//-------------------------------------------------------
int main()
{
    vector<string> fruit = {"orange", "broccoli", "carrot", "tomato", "pea", "spinach"};

    vector<int> stringLength = getstringLength(fruit);
    stringInfo si = getstringInfo(fruit);

    cout <<"-------------------------------------\n";
    cout << "\nNumber of character: ";
    for (int sLength : stringLength){
        cout << sLength <<", ";
    }

    cout << "\nFirst string: " << si.first;
    cout << "\nLast string: " << si.last <<'\n';

    cout <<"\nLongest word is: ";
    for (string longest : si.longWords){
        cout << longest <<", ";
    }

    cout <<"\nShortest word is: ";
    for (string shortest : si.shortWords){
        cout << shortest <<", ";
    }
    cout <<"\n\n-------------------------------------";

}
