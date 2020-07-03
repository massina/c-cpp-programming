/*
The Big 3 is a rule in C++ that applies to standard pointers, 
that if a class defines any of the following it should explicitly define all 3
○ The destructor (what is called when delete is executed)
○ Copy constructor (How to copy by value for the variable)
○ Copy Assignment Operator (For assigning one object to another)
*/

struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head;
    node *tail;
    int *size = new int(0);

public:
    linked_list()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Destructor function.
    linked_list::~linked_list()
    {
        // Free memory (dynamic allocated).
        delete size;
    }

    linked_list::linked_list(const linked_list &rhs)
    {
        head = rhs.head;
        tail = rhs.tail;
        size = new int(*(rhs.size));
    }
};