/*
    Question #11.
    Chapter 18, page 665.
    Date: 08/05/2023.

    Look up (e.g., on the web) skip list and implement that kind of list. This is 
    not an easy exercise.
*/

#include <iostream>
#include <vector>
using namespace std;

struct Cell;

struct Column {
    int value;
    vector<Cell> cells;
};

struct Cell {
    Column *previous_column, *next_column;
};

struct SkipLists {
    static const int MAX_LEVEL = 20;
    Column *head, *tail;

    SkipLists();
    bool empty();

    Column *upper_bound(int);   // find the Column with higher value than finding one
    Column *lower_bound(int);   // find the Column with lower value than finding one
    
    void insert(int);
    void erase(int);
};

SkipLists::SkipLists()
{
    head = new Column;
    tail = new Column;
    head->value = 0;
    tail->value = 0;

    for(int i = 0; i < MAX_LEVEL; ++i) {
        head->cells.push_back((Cell){NULL, tail});
        tail->cells.push_back((Cell){head, NULL});
    }
}

bool SkipLists::empty() {
    return head->cells[0].next_column == tail;
}

Column *SkipLists::lower_bound(int value)
{
    Column* iter = head;
    for(int level = MAX_LEVEL; level >= 0; --level) {
        while(iter->cells[level].next_column != tail && iter->cells[level].next_column->value < value) {
            iter = iter->cells[level].next_column;
        }
    }
    
    return iter->cells[0].next_column;
}

Column *SkipLists::upper_bound(int value)
{
    Column* iter = head;
    for(int level = MAX_LEVEL; level >= 0; --level) {
        while(iter->cells[level].next_column != tail && iter->cells[level].next_column->value <= value) {
            iter = iter->cells[level].next_column;
        }
    }
    
    return iter->cells[0].next_column;
}

void SkipLists::insert(int value)
{   
    // checking whether the value is in list
    Column* temp = lower_bound(value);
    if (temp != tail && temp->value == value) {
        return;
    }

    // create a new column
    Column* inserted_column = new Column;
    inserted_column->value = value;
    inserted_column->cells.push_back((Cell){NULL, NULL});

    // flip a coin to decide the level of cell
    while(inserted_column->cells.size() < MAX_LEVEL && rand() % 2 == 0) {
        inserted_column->cells.push_back((Cell){NULL, NULL});
    }

    // insert
    Column* iter = head;
    for(int level = MAX_LEVEL; level >= 0; --level) {
        while(iter->cells[level].next_column != tail && iter->cells[level].next_column->value < value) {
            iter = iter->cells[level].next_column;
        }

        if (iter->cells[level].next_column != tail && iter->cells[level].next_column->value == value) {
            // if the value already exists in the list, return without inserting a new value
            return;
        }

        if (level < inserted_column->cells.size()) {
            // connect iter with inserted_column, connect inserted_column with next_iter
            Column* next_iter = iter->cells[level].next_column;

            iter->cells[level].next_column = inserted_column;
            next_iter->cells[level].previous_column = inserted_column;

            inserted_column->cells[level].next_column = next_iter;
            inserted_column->cells[level].previous_column = iter;
        }
    }
}


void SkipLists::erase(int value)
{
    // checking whether the value is in list
    Column* erased_column = lower_bound(value);
    if (erased_column == tail || erased_column->value != value) {
        return;
    }

    // erased
    Column* iter = head;
    for(int level = MAX_LEVEL; level >= 0; --level) {
        while(iter->cells[level].next_column != tail && iter->cells[level].next_column->value <= value) {
            iter = iter->cells[level].next_column;
        }

        if (iter == erased_column)
        {
            Column* next_iter = iter->cells[level].next_column;
            Column* pre_iter = iter->cells[level].previous_column;

            pre_iter->cells[level].next_column = next_iter;
            next_iter->cells[level].previous_column = pre_iter; 
        }
    }

    delete erased_column;
}

void printList(SkipLists& list) {
    cout << "List values: ";
    Column* iter = list.head->cells[0].next_column;
    while (iter != list.tail) {
        cout << iter->value << " ";
        iter = iter->cells[0].next_column;
    }
    cout << endl;
}

int main() {
    SkipLists list;
    
    for (int i = 0; i < 20; ++i) {


        list.insert(i*2);
    }

    printList(list);
}
