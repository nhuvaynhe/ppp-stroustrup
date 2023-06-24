//Writing a letter

#include<iostream>
using namespace std;

int main()
{
    cout<<"\nEnter the name of the person you want to write to \n";
    string first_name;
    cin>>first_name;

    cout<<"Enter the name of your another friend \n";
    string friend_name;
    cin>>friend_name;

    cout<<"Enter the age of your friend \n";
    int age;
    while (cin>>age){
        if (age <= 0 || age >= 110)
        cerr<<"you're kidding! \n";
    
    cout<<"Enter you friend sex: male or female \n";
    string friend_sex;
    cin>>friend_sex;

    cout<<"\nDear "<<first_name<<'\n';
    cout<<"    How are you? I'm fine. I miss you."
        <<" Have you seen "<<friend_name<<" lately?";

    if (friend_sex == "male") //Check the sex
        cout<<" If you see "<<friend_name<<" please ask him to call me. ";
    if (friend_sex == "female")
        cout<<" If you see "<<friend_name<<" please ask her to call me. ";

    cout<<"\n    I hear you just had a birthday and you are "<<age<<" years old. ";

    if (age == 17) //Check the age 
        cout<<"Next year you will be able to vote. \n";
    if (age < 70 & age != 17)
        cout<<"Next year you will be "<<age+1<<". Time flies fast, huh!\n";
    if (age >70)
        cout<<"I hope you're enjoying retirement \n";
    cout<<"                 Your sincerely,";
    cout<<"\n                 Nguyen Ngoc Dai \n";
    }  
}