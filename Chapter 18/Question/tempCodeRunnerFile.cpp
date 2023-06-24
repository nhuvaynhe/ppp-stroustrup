struct Column {
    int value;
    vector<Cell> cells;
};

struct Cell {
    Column *previous_column, *next_column;
};

struct SkipLists {
    static const int MAX_LEVEL = 20;
    Column *head, *tall;

    SkipLists();
    bool empty();

    Column *upper_bound(int);
    Column *lower_bound(int);
    
    void insert(int);
    void erase(int);
};