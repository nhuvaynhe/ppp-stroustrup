//Arrange strings in order

#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter three strings: \n";
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    if (s1 == s2 && s1 == s3){
        cout<<"The order is: "<<s3<<", "<<s2<<", "<<s1;
    }

    else if (s1 > s2 && s1 > s3){
        if (s2 > s3){
            cout<<"The order is: "<<s3<<", "<<s2<<", "<<s1;
        }
        else{
            cout<<"The order is: "<<s2<<", "<<s3<<", "<<s1;
        }
    }

    else if (s2 > s1 && s2 > s3){
        if (s1 > s3){
            cout<<"The order is: "<<s3<<", "<<s1<<", "<<s2;
        }
        else{
            cout<<"The order is: "<<s1<<", "<<s3<<", "<<s2;
        }
    }

    else if (s3 > s1 && s3 > s2){
        if (s1 > s2){
            cout<<"The order is: "<<s2<<", "<<s1<<", "<<s3;
        }
        else{
            cout<<"The order is: "<<s1<<", "<<s2<<", "<<s3;
        }
    }
}