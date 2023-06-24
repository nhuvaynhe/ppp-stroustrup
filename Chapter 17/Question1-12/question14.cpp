/*
    Question 14.
    Chapter 17, page 624.
    Date: 06/05/2023
 
    Could the “list of gods” example from §17.10.1 have been written using a 
    singly-linked list?
*/

#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

struct God
{
    string name, myth, vehicle, weapon;

    God () { }
    God(string n, string m, string v, string w)
        : name{n}, myth{m}, vehicle{v}, weapon{w} { }

    God(string n, string m, string w)
        : name{n}, myth{m}, vehicle{"NONE"}, weapon{w} { }
};

class Link 
{
public:
    God value;

    Link(const God& v, Link* s = nullptr)
        : value{v}, succ{s} { }
    
    Link* insert(Link* n);
    Link* add(Link* n);
    void erase(Link* n);
    Link* find(const string& s);
    const Link* find(const string& s) const;

    Link* advance(int n) const;


    Link* next() { return succ; }

private:
    Link* succ;
}; 
//--------------------------------------------------------------------------
Link* Link::insert(Link* n)
{
    if (n==nullptr) return this;
    if (this==nullptr) return n;
    
    Link* p = this;
    while (p->succ) {
        p = p->succ;
    }

    p->succ = n;

    return n;
}

Link* Link::add(Link* n) 
{   
    return this;
}

void Link::erase(Link* n)
{   
    Link* temp = this;

    while (temp->succ) 
    {
        if (temp->succ == n) 
            break;
        else 
            temp = temp->succ;
    }

    if (n->succ)
        temp->succ = n->succ;

    n->succ = nullptr;
}

Link* Link::advance(int n) const 
{   
    const Link* p = this;
    if (p==nullptr) return nullptr;
    if (0<n) {
        while (n--) {
            if (p->succ==nullptr) return nullptr;
            p = p->succ;
        }
    }
    
    return const_cast<Link*>(p);
}

Link* Link::find(const string& s) 
{ 
    Link* p = this;
    while (p) {
        if (p->value.name == s) return p;
        p = p->succ;
    }

    return nullptr;
}

const Link* Link::find(const string& s) const 
{ 
    const Link* p = this;
    while (p) {
        if (p->value.name == s) return p;
        p = p->succ;
    }

    return nullptr;
}

void print_all(Link* p)
{   
    cout << "\n--------------------------------------------------------------------------\n";
    Link* first = p;
    while (first) {
        cout << "\t{Name: " << setw(8) << first->value.name << " | Myth: " << setw(8) << first->value.myth 
             << " | Vehicle: " << setw(15) << first->value.vehicle << " | Weapon: " << setw(18) <<  first->value.weapon << "}" ;

        if (first=first->next()) cout << '\n';      // check whether the next node is null pointer or not
    }                                       // and assign p to the next node
    
}
//-------------------------------------------------------------------------- 
int main()
{
    God thor = God("Thor", "Norse", "Mjolnir");

    Link* god = new Link{thor};
    god->insert(new Link{ God("Hera", "Greek", "Peacock Chariot", "Cattle")} );
    god->insert(new Link{ God("Odin", "Norse", "Sleipner", "Spear and Gungnir") });
    god->insert(new Link{ God("Ra", "Egyptian", "Chariot", "The Sun") });
    god->insert(new Link{ God("Osiris", "Egyptian", "Crook and Flail") });


    Link* p = god->find("Osiris");
    god->erase(p);

    print_all(god);
}