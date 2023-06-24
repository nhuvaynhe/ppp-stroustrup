/*
    Chapter 17.
    Try this #2
    Date: 02/05/2023

    Write a little program using base classes and members where you define the 
    constructors and destructors to output a line of information when they are 
    called. Then, create a few objects and see how their constructors and destruc-
    tors are called.
*/

#include "std_lib_facilities.h"

class Animal
{
public:
    Animal() {
        cout << "Animal constructor called" << endl;
    }

    virtual ~Animal() {
        cout << "Animal destructor called" << endl;
    }
};

class Mammal: public Animal {
public:
    Mammal() {
        cout << "Mammal constructor called" << endl;
    }

    virtual ~Mammal() {
        cout << "Mammal destructor called" << endl;
    }
};

class Dog: public Mammal {
public:
    Dog() {
        cout << "Dog constructor called" << endl;   
    }

    ~Dog() {
        cout << "Dog destructor called" << endl;
    }
};

class Cat: public Mammal {
public:
    Cat() {
        cout << "Cat constructor called" << endl;
    }

    ~Cat() {
        cout << "Cat destructor called" << endl;
    }
};

int main()
{
    Animal* dog = new Dog();
    cout << endl;
    Animal* cat = new Cat();
    cout << endl;

    delete dog;
    cout << endl;
    delete cat;
}