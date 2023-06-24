//Drill of chapter 3, page 126

#include <iostream>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    double val = 0;
    vector<double> largest = {0};
    vector<double> smallest = {0};
    vector<double> total = {};
    
    char unit = ' ';
    constexpr int m_to_cm = 100;
    constexpr int in_to_cm = 2.54;
    constexpr int ft_to_in = 12;
    constexpr int ft_to_cm = 12*2.54;

    cout<<"Please enter an integer and followed by a unit (m/ c/ i/ f): \n";

    int i = 0;
    int j = 0;
    int sum = 0;
    int ite = 0; // Count the number of input
    int test;

    while (cin>>val>>unit){
        switch (unit){
        case 'm':
            val = val*m_to_cm;
            break;
        case 'c':
            val = val;
            break;
        case 'f':
            val = val*ft_to_cm;
            break;
        case 'i':
            val = val*in_to_cm;
            break;
        default:
            test = 1;
            cout<<"\nPlease try again!!!";
            return 0;
            break;
        }

        if (test != 1){
            sum = sum + val;
            ++ite;
            total.push_back(val);

            if (val - largest[i] >= 0){
                largest.push_back(val);
                ++i;
                cout<<val<<" cm is the largest number so far \n";
            }
            else if (j == 0 || smallest[j] - val >= 0){
                smallest.push_back(val);
                ++j;
                cout<<val<<" cm is the smallest number so far\n";
            }
            else cout<<val<<" cm is between smallest and largest number \n";
        }
    }

    sort(total.begin(), total.end());
    
    //Find the number that appears the most time
    int nCount = 1;
    int nMode = 0;
    int nMaxcount = 1;

    for (int i = 1; i <= total.size(); ++i){
        if (total[i] == total[i-1])
        {
            ++nCount;
        } else {
            nCount = 1;
        }

        if (nMaxcount < nCount)
        {
            nMode = total[i];
            nMaxcount = nCount;
        }
    }

    cout<<"\nThe sum so far is: "<<sum/m_to_cm<<" meters";
    cout<<"\nThe number of input so far is: "<<ite;
    cout<<"\nAll input in increasing order: ";
    for (int x : total){
        cout<<x/100<<"m, ";
    }
    cout<<"\nThe number appears the most is: "<<nMode/m_to_cm<< " meters with "<<nMaxcount<<" times";
}