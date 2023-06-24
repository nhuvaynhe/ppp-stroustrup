// Chapter 5: Error. 
// Drill exercise.
// 15/03/2023

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "Success!\n";
    cout << "Success!\n";
    cout << "Success" << "!\n";
    cout << "success" << '\n';
    int res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
    vector<int> vy(10); v[5] = 7; if (v[5]!=7) cout << "Success!\n";
    bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n";
    string s = "ape"; bool c2 = true; if (c2) cout << "Success!\n";
    string s1 = "ape"; if (s1 != "fool") cout << "Success!\n";
    string s2 = "fool"; if (s2 == "fool") cout << "Success!\n";
    string s3 = "ape"; if (s3 == "ape") cout << "Success!\n";   
    for (int i=0; i <= v.size(); ++i) cout << "Success!\n";
    vector<char> v2(5); for (int i=0; i<=v2.size(); ++i) ; cout << "Success!\n"; 
    string s4 = "Success!\n"; for (int i=0; i<6; ++i) cout << s4;
    if (c) cout << "Success!\n"; else cout << "Fail!\n";
    int x = 2000; int c3 = x; if (c3==2000) cout << "Success!\n"; 
    for (int i=0; i<10; ++i) cout << s4; 
    for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n"; 
    int i=0; int j = 9; while (i<10) ++i; if (j>i) cout << "Success!\n"; 
    int x2 = 3; double d = 5/(x2 - 2); if (d==2*x2-1) cout << "Success!\n";
    string s5 = "Success!\n"; for (int i=0; i<=10; ++i) cout << s5; 
    int i2=0; while (i2<10) ++i2; if (j<i) cout << "Success!\n"; 
    int x3 = 4; double d2 = 5/(x3 - 2); if (d2 = 2+0.5) cout << "Success!\n";
    cout << "Success!\n";
}
