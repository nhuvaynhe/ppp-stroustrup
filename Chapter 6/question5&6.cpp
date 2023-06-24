// Add the article the to the “English” grammar in §6.4.1, so that it can 
// describe sentences such as “The birds fly but the fish swim.”
// Question 5, page 219
// 23/03/2023

#include "std_lib_facilities.h"

/*
    Implements this grammar:
    
    Sentence:
        Subject Verb
        Sentence Conjunction Sentence
        
        Subject:
            Noun
            "the" Noun
        
        Conjunction:
            "and"
            "or"
            "but"
        
        Noun:
            "birds"
            "fish"
            "C++"
        
        Verb:
            "rules"
            "fly"
            "swim"

    and checks if an entered sentence is correct according to it or not.
*/

