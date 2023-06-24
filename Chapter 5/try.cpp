#include <iostream>
#include <cmath>
using namespace std;

// ask user for a yes-or-no answer;
// return 'b' to indicate a bad answer (i.e., not yes or no)
char ask_user(string question)
{
    cout << question << "? (yes or no) \n";
    string answer = " ";
    cin >> answer;
    if (answer == "y" || answer == "yes") return 'y';
    if (answer == "n" || answer == "no") return 'n';
    else return 'b'; // 'b' for a bad answer
}

int area(int length, int width)     // claculate area of a rectangle
{
    if (length <= 0 || width <= 0) cerr<<"non-positive area () argument";
    return length*width;
}

int framed_area(int x, int y)       // calculate area within frame
{
    constexpr int frame_width = 2;
    if (x - frame_width <= 0 || y - frame_width <= 0)
        cerr<<"non-positive area() argument called by framed-area()";
    return area(x - frame_width, y - frame_width);
}

int f(int x, int y, int z)
{
    int area1 = area(x, y);
    if (area1 <= 0) cerr<<"non-positive area";
    int area2 = framed_area(x, z);
    int area3 = framed_area(y, z);
    double ratio = double(area1)/area3;
    // ...
}

int main()
{
    int x, y, z;
    cout<<"Enter three integer: \n";
    cin >> x >> y >> z;
    area(x,y);
}