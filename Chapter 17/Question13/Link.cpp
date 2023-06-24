/*
    Question 13.
    Chapter 17, page 624.
    Date: 04/05/2023
 
    Complete the “list of gods” example from §17.10.1 and run it.
*/

#include "Link.h"
#include <string>

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

Link* Link::getFirst()
{
	if (Link* temp = this)
	{
		while (temp->prev)
			temp = temp->prev;
		return temp;
	}

	return nullptr;
}

void Link::add_ordered(Link* n)
{
    Link* p = this->getFirst();
    while (p) {
        if (p->value.name > n->value.name) {
            add(n);
        } else { 
            p = p->succ;
        }
    }

    return;
}


void print_all(Link* p)
{   
    cout << "--------------------------------------------------------------------------\n";

    while (p) {
        cout << "\t{Name: " << p->value.name << " | Myth: " << p->value.myth 
             << " | Vehicle: " << p->value.vehicle << " | Weapon: " << p->value.weapon << "}" ;

        cout << "\n--------------------------------------------------------------------------";
        if (p=p->next()) cout << '\n';      // check whether the next node is null pointer or not
    }                                       // and assign p to the next node
    
}