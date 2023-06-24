// Question 7, page 219
// 23/03/2023
// Write  a  grammar  for  bitwise  logical  expressions.

#include "std_lib_facilities.h"

/*
    Implement this grammar:

    Expression:
        Term
        Term 'Or' Term

    Term:
        Subterm
        Subterm 'XOR' Subterm
    
    Subterm:
        Primary
        Primary 'AND' Primary
    
    Primary:
        'Not' 
        Number
*/