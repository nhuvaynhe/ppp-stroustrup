/*
    Question 13.
    Chapter 17, page 624.
    Date: 04/05/2023
 
    Complete the “list of gods” example from §17.10.1 and run it.
*/

#ifndef _LINK_H_
#define _LINK_H_

#include <iostream>
using namespace std;

struct God
{
    string name;
    string myth;
    string vehicle;
    string weapon;

    God(string n, string m, string v, string w)
        : name{n}, myth{m}, vehicle{v}, weapon{w} { }

    God(string n, string m, string w)
        : name{n}, myth{m}, vehicle{"NONE"}, weapon{w} { }
};

class Link 
{
public:
    God value;

    Link(const God& v, Link* p = nullptr, Link* s = nullptr)
        : value{v}, prev{p}, succ{s} { }
    
    Link* insert(Link* n);
    Link* add(Link* n);
    Link* erase();
    Link* find(const string& s);
    const Link* find(const string& s) const;

    Link* advance(int n) const;

    Link* next() const { return succ; };
    Link* previous() const { return prev; };

    void add_ordered(Link* n);
    Link* getFirst();
private:
    Link* prev;
    Link* succ;
};
//-------------------------------------------------------------------------- 
void print_all(Link* p);


#endif