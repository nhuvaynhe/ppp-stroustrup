/*
    Question 13.
    Chapter 17, page 624.
    Date: 04/05/2023
 
    Complete the “list of gods” example from §17.10.1 and run it.
*/
#include "Link.h"

//-------------------------------------------------------------------------- 
int main()
{   
    God zeus = God("Zeus", "Greek", "lightning");
    God odin = God("Odin", "Norse", "Sleipner", "Spear called Gungnir");
    God dai = God("Boy", "Norse", "Sleipner", "Spear called Gungnir");
    

    Link* norse_gods = new Link{zeus};
    norse_gods = norse_gods->insert(new Link{odin});

    norse_gods->add_ordered(new Link{dai});
    print_all(norse_gods);

    return 0;
}