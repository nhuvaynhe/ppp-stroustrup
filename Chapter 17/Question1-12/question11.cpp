/*
    Question 11.
    Chapter 17, page 624.
    Date: 04/05/2023
 
    Complete the “list of gods” example from §17.10.1 and run it.
*/

#include <iostream>
using namespace std;

class Link 
{
public:
    string value;

    Link(const string& v, Link* p = nullptr, Link* s = nullptr)
        : value{v}, prev{p}, succ{s} { }
    
    Link* insert(Link* n);
    Link* add(Link* n);
    Link* erase();
    Link* find(const string& s);
    const Link* find(const string& s) const;

    Link* advance(int n) const;

    Link* next() const { return succ; };
    Link* previous() const { return prev; };
private:
    Link* prev;
    Link* succ;
};
//-------------------------------------------------------------------------- 
Link* Link::insert(Link* n)
{
    if (n==nullptr) return this;
    if (this==nullptr) return n;
    n->succ = this;
    if (prev) prev->succ = n;
    n->prev = prev;

    prev = n;
    return n;
}

Link* Link::add(Link* n)        // insert n after p
{   
    if (n==nullptr) return this;
    if (this==nullptr) return nullptr;

    n->prev = this;
    if (succ) {
        n->succ = succ;
    } else n->succ = nullptr; // problem for the last node!!!
    succ = n;

    return n;
}

Link* Link::erase()
{
    if (this==nullptr) return nullptr;
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
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
    else if (n<0) { 
        while (n++) {
            if (p->prev == nullptr) return nullptr;
            p = p->prev;
        }
    }
    
    return const_cast<Link*>(p);
}

Link* Link::find(const string& s) 
{ 
    Link* p = this;
    while (p) {
        if (p->value == s) return p;
        p = p->succ;
    }

    return nullptr;
}

const Link* Link::find(const string& s) const 
{ 
    const Link* p = this;
    while (p) {
        if (p->value == s) return p;
        p = p->succ;
    }

    return nullptr;
}

//-------------------------------------------------------------------------- 
void print_all(Link* p)
{
    cout << "\n{";
    while (p) {
        cout << p->value;

        if (p=p->next()) cout << ", ";      // check whether the next node is null pointer or not
    }                                       // and assign p to the next node
    
    cout << "}";
}
//-------------------------------------------------------------------------- 
int main()
{
    Link* norse_gods = new Link{"Thor"};
    norse_gods = norse_gods->insert(new Link{"Odin"});
    norse_gods = norse_gods->insert(new Link{"Zeus"});
    norse_gods = norse_gods->insert(new Link{"Freia"});

    Link* greek_gods = new Link{"Hera"};
    greek_gods = greek_gods->insert(new Link{"Athena"});
    greek_gods = greek_gods->insert(new Link{"Mars"});
    greek_gods = greek_gods->insert(new Link{"Poseidon"});

    Link* p2 = norse_gods->find("Freia");


    if (p2) // check if both nodes are found
    {   
        if (p2 == norse_gods) norse_gods = p2->next();
        p2->erase(); // remove p2 from norse_gods list
    }

    cout << "\n-----------------------------------------------------------";
    print_all(norse_gods);


}