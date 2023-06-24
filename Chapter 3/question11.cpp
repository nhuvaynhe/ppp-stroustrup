//Money converted

#include <iostream>
using namespace std;

int main()
{
    int cent = 0; 
    int penny = 0; // 1-cent coins
    int nickle = 0; // 5-cent coins
    int dime = 0;  // 10-cent coins
    int quarter = 0; // 25-cent coins 
    int half_dollar = 0; //50-cent coins
    int one_dollar = 0; // 100-cent coins

    cout<<"How many pennies do you have?: ";
    
    while (cin >> cent){
        one_dollar = cent/100;
        half_dollar = (cent - one_dollar*100)/50;
        quarter = (cent -one_dollar*100 - half_dollar*50)/25;
        dime = (cent -one_dollar*100 - half_dollar*50 - quarter*25)/10;
        nickle = (cent -one_dollar*100 - half_dollar*50 - quarter*25 - dime*10)/5;
        penny = (cent -one_dollar*100 - half_dollar*50 - quarter*25 -dime*10 -nickle*5);
        
        if (one_dollar == 1 || one_dollar == 0 ){
            cout<<"\nYou have "<<one_dollar<<" dollar \n";
        }
        else{
            cout<<"\nYou have "<<one_dollar<<" dollars \n";
        }

        if (half_dollar == 1 || half_dollar == 0){
            cout<<"You have "<<half_dollar<<" half dollar \n";
        }
        else{
            cout<<"You have "<<half_dollar<<" half dollars \n";
        }

        if (quarter == 1 || quarter == 0){
            cout<<"You have "<<quarter<<" quater \n";
        }
        else{
            cout<<"You have "<<quarter<<" quaters \n";
        }

        if (dime == 1 || dime == 0){
            cout<<"You have "<<dime<<" dime \n";
        }
        else{
            cout<<"You have "<<dime<<" dimes \n";
        }

         if (nickle == 1 || nickle == 0){
            cout<<"You have "<<nickle<<" nickle \n";
        }
        else{
            cout<<"You have "<<nickle<<" nickles \n";
        }

        if (penny == 1 || penny == 0){
            cout<<"You have "<<penny<<" penny \n";
        }
        else{
            cout<<"You have "<<penny<<" pennis \n";
        }
    }

}