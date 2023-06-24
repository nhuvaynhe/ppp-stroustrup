/*
    Question 13.
    Chapter 17, page 624.
    Date: 04/05/2023
 
    Complete the “list of gods” example from §17.10.1 and run it.
*/

#include <iostream>
#include <string>
#include<iomanip>
using namespace std;
//-------------------------------------------------------------------------- 
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

    Link(const God& v, Link* p = nullptr, Link* s = nullptr)
        : value{v}, prev{p}, succ{s} { }
    
    Link* insert(Link* n);
    Link* add(Link* n);
    Link* erase();
    Link* find(const string& s);
    const Link* find(const string& s) const;

    Link* advance(int n) const;

    Link* extract();

    Link* prev;
    Link* succ;
}; 
//-------------------------------------------------------------------------- 
Link* Link::insert(Link* n)
{
    if (n==nullptr) return this;
    if (this==nullptr) return n;
    
    n->succ = this;
    if (prev) {
        prev->succ = n;
        n->prev = prev;
    } else {
        n->prev = nullptr;
    }

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

void print_all(Link* p)
{   
    cout << "\n--------------------------------------------------------------------------\n";
    Link* first = p;
    while (first) {
        cout << "\t{Name: " << setw(8) << first->value.name << " | Myth: " << setw(8) << first->value.myth 
             << " | Vehicle: " << setw(15) << first->value.vehicle << " | Weapon: " << setw(18) <<  first->value.weapon << "}" ;

        if (first=first->succ) cout << '\n';      // check whether the next node is null pointer or not
    }                                       // and assign p to the next node
    
}

Link* Link::extract()
{
    Link* p = this->prev;
    Link* s = this->succ;
    if (p) { // If there is a previous link...
        p->succ = s; // ...connect it to the link after this one
    }
    if (s) { // If there is a next link...
        s->prev = p; // ...connect it to the link before this one
    }
    // Clear pointers to remove the link from the list
    this->prev = nullptr;
    this->succ = nullptr;
    return this;
}


Link* add_ordered(Link* p, Link* n)
{
    if (!p) {
        return n;
    }
    if (n->value.name < p->value.name) {
        n->succ = p;
        p->prev = n;
        return n;
    }
    Link* curr = p;
    while (curr->succ && curr->succ->value.name < n->value.name) {
        curr = curr->succ;
    }
    n->succ = curr->succ;
    if (curr->succ) {
        curr->succ->prev = n;
    }
    curr->succ = n;
    n->prev = curr;
    return p;
}



//-------------------------------------------------------------------------- 
int main()
{   
    Link* godsList = new Link{ God("Thor", "Norse", "Mjolnir") };
	godsList = godsList->insert(new Link{ God("Hera", "Greek", "Peacock Chariot", "Cattle") });
	godsList = godsList->insert(new Link{ God("Ra", "Egyptian", "Chariot", "The Sun") });
	godsList = godsList->insert(new Link{ God("Odin", "Norse", "Sleipner", "Spear and Gungnir") });
	godsList = godsList->insert(new Link{ God("Zeus", "Greek", "Thunderbolt") });
	godsList = godsList->insert(new Link{ God("Osiris", "Egyptian", "Crook and Flail") });
	godsList = godsList->insert(new Link{ God("Freia", "Norse", "Cat Chariot", "Brisingamen") });
	godsList = godsList->insert(new Link{ God("Poseidon", "Greek", "Horse", "Trident") });
	godsList = godsList->insert(new Link{ God("Horus", "Egyptian", "Falcon") });

    Link* greekList = nullptr;
    Link* norseList = nullptr;
    Link* egyptianList = nullptr;

    Link* curr = godsList;
    while (curr) {
    if (curr->value.myth == "Greek") {
        // Extract the node and add it to the Greek list
        Link* node = curr; // Store pointer to current node
        curr = curr->succ; // Move current pointer to next node
        node->extract(); // Remove node from godsList
        greekList = add_ordered(greekList, node); // Add node to Greek list
    } else if (curr->value.myth == "Norse") {
        // Extract the node and add it to the Norse list
        Link* node = curr;
        curr = curr->succ;
        node->extract();
        norseList = add_ordered(norseList, node);
    } else if (curr->value.myth == "Egyptian") {
        // Extract the node and add it to the Egyptian list
        Link* node = curr;
        curr = curr->succ;
        node->extract();
        egyptianList = add_ordered(egyptianList, node);
    } else {
        curr = curr->succ;
    }
}



    print_all(egyptianList);
    print_all(norseList);
    print_all(greekList);

    return 0;
}

