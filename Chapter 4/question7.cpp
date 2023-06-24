//Calculator +, -, *, /

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    
    vector<int> number = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  //To convert from char to number
    vector<string> char_number = {"0","1" ,"2" ,"3", "4", "5", "6", "7", "8", "9"};
    vector<string> string_number = {"zero", "one", "two", "three", "four", "five", "six",
                        "seven", "eight", "nine"};
    vector<char> request = { };  //To save the input of user

    char word = ' ';
    int location = 0; // To save the location of operator
    
    cout<<"Enter two digits and followed by an operator [+, -, *, /]: \n";
    cout<<"You can spell out the digit! \n";
    while (cin>>word){
        request.push_back(word);   //Ctrl+Z to stop
    }

    for (int i = 0; i < request.size(); ++i){    //Find the location of the operator
        if (request[i] == '+' || request[i] == '-' ||
            request[i] == '*' || request[i] == '/'){
                location = i; 
            }
    }

    char char_1;
    char char_2; // To save the character, easy to read the code
    string value_1;
    string value_2;
    
    for (int j = 0; j < request.size(); ++j){
        if (j < location){
            char_1 = request[j];
            value_1 += char_1;
        }
        else if (j > location){
            char_2 = request[j];
            value_2 +=  char_2;
        }
    }

    int num_value_1 = 0;
    int num_value_2 = 0;
    for (int i = 0; i < 10; ++i){    //Assign character into string
        if (value_1 == string_number[i]){
            num_value_1 = number[i];
        }
        else if (value_1 == char_number[i]){
            num_value_1 = number[i];
        }
    }

    for (int j = 0; j < 10; ++j){    //Assign character into string
        if (value_2 == string_number[j]){
            num_value_2 = number[j];
        }
        else if (value_2 == char_number[j]){
            num_value_2 = number[j];
        }
    }

    char math = request[location]; // The operator in char
    int sum = 0;
    int val1 = num_value_1;
    int val2 = num_value_2;
    switch (math)  // Calculate the output
    {
    case '+':
        sum = val1 + val2;
        cout<<"The sum of "<<val1<<" and "<<val2<<" is equal "<<sum<<'\n';
        break;
    case '-':
        sum = val1 - val2;
        cout<<"The minus of "<<val1<<" and "<<val2<<" is equal "<<sum<<'\n';
        break;
    case '*':
        sum = val1 * val2;
        cout<<"The multiply of "<<val1<<" and "<<val2<<" is equal "<<sum<<'\n';
        break;
    case '/':
        sum = val1 / val2;
        cout<<"The devision of "<<val1<<" and "<<val2<<" is equal "<<sum<<'\n';
        break;
    default:
        cout<<"Wrong input!! \n";
        break;
    }
}