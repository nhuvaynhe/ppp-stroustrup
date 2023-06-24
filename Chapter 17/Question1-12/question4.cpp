/*
    Question 4.
    Chapter 17, page 624.
    Write a function, char* strdup(const char*), that copies a C-style string 
    into memory it allocates on the free store. 
*/

char* my_strdup(const char* c)
{
    int length = 0;
    while (c[length] != 0)
        ++length;

    char* newC = new char[length+1];
    for (int i=0; i<=length; ++i) {
        newC[i] = c[i];
    }

    return newC;
}

int main()
{
    char str[] = "HeLLo WoRlD";

    char* c = my_strdup(str);
}