//Question 8, page 253
//Fix the grammar

/*
The grammar for input is:

    Calculate: 
        Statement
        Print
        Help
        Exit
        Calculation Statement

    Statement:
        Declaration
        Constant Variable
        Expression

    Declaration:
        "let" Name "=" Expression

    Constant Variable:
        "constvar" Name "=" Expression
    
    Expression:
        Term
        Expression + Term
        Expression - Term
    
    Term:
        Primary
        Term * Primary
        Term / Primary
        Term % Primary

    Primary:
        Number
        ( Expression )
        - Primary
        + Primary
        Name "=" Expression
        Pow "(" Expression "," Expression ")"
        Sqrt "(" Expression ")"

    Number:
        floating-point-literal

*/