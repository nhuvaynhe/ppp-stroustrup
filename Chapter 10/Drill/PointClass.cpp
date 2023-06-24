/*
    Drill
    Chapter 10, page 376.
    12/04/2023.

    Pointclass.cpp
*/

#include "PointClass.h"


//--------------------------------------------------------------
int main()
{
    cout << "Please input coordinate x and y of a point: ";
    vector<Point> original_posts;
    Point x_y;

    for (int i=0; i<3; ++i) {
        cin >> x_y;
        original_posts.push_back(x_y);
    }
    
    string filename = "mydata.txt";

    fstream fs(filename);   // Open for input

    for (Point p : original_posts)
        fs << '(' << p.x_cor << ',' << p.y_cor << ")\n"; 

    fs.close();             // Close file for open a new file

    vector<Point> point_processed;
    fs.open(filename, ios_base::in);    // Open a new file
    bool equal = true;

    for (Point p; fs >> p; )
        point_processed.push_back(p);
        

    for (int i=0; i < original_posts.size(); ++i)
    {
        if (!(original_posts[i] == point_processed[i])) {       //Compare element of two vectors
            equal = false;
        }
    }

    if (equal) {
        cout << "Two Points vector are the same" << endl;
    } else cout <<"Something wrong!";

    fs.close();                 // Close file
}