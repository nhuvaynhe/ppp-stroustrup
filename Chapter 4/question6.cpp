//Convert string into digit

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num = 0;
    vector<string> word = {"one", "two", "three", "four", "five", "six",
                        "seven", "eight", "nine"};
    vector<int> number = {};

    cout<<"Please enter a number you like: \n";
    cin>>num;
    number.push_back(num);
    cout<<num<<"  "<<word[num-2]<<'\n';
    
    
    vector<int> number2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<string> word2 = { };
    string keyword = " ";

    cout<<"Please enter a word you like: \n";
    int i = 0;
    while (cin >> keyword){
        word2.push_back(keyword);
        for (int i =0; i < 9; ++i){
            if (keyword == word[i]){
                cout<<keyword<<"  "<<number2[i]<<'\n';
            }
        }
    }
}