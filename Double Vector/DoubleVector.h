class DoubleVector{
    public:
    DoubleVector();
    DoubleVector(int n);
    ~DoubleVector();

    int size();
    bool empty();
    int pop_back();
    int pop_front();
    void push_back(int value);
    void push_front(int value);

    int at(int k);

    void shift(int type);
    void resize();

    void insert(int value, int k);
    void replaceAt(int value, int k);
    void removeAt(int k);
    void removeAll(int value);

    void print();
    void printReverse();

    void concat(DoubleVector& lst);
    bool equals(DoubleVector& lst);

    private:
    int  m_size     {0};
    int  m_head     {0};
    int  m_tail     {0};
    int  m_capacity {0};
    int* m_list     {nullptr};
};