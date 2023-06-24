//The distance between two cities

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<double> distance = {};

    int sum = 0;
    double dist = 0;

    cout<<"Enter the distance between two cities: ";
    while (cin>>dist){
        distance.push_back(dist);
    }

    sort(distance.begin(), distance.end());
    for (int x : distance){
        sum += x;
    }
    cout<<"\nThe largest distance is: "<<distance[distance.size()-1];
    cout<<"\nThe smallest distance is: "<<distance[0];
    cout<<"\nThe total distance is: "<<sum;
    
}