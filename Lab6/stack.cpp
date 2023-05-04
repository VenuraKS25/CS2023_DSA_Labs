#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack_Array
{
private:
    int size;
    int *stack;
    int top;

public:
    Stack_Array(int size)
    {
        top = -1;
        this->size = size;
        stack = new int[size];
    }
    ~Stack_Array()
    {
        delete[] stack;
    }

    void push(int data);
    int pop();
    bool isEmpty();
    bool isFull();
    void display();
    void clear();
};

bool Stack_Array::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack_Array::isFull()
{
    if (top == size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack_Array::push(int data)
{
    if (isFull())
    {
        cout << "Stack overflow" << endl;
        return;
    }
    else
    {
        top++;
        stack[top] = data;
    }
}

int Stack_Array::pop()
{
    if (isEmpty())
    {
        cout << "Stack underflow" << endl;
        return -1;
    }
    else
    {
        int pop_data = stack[top];
        top--;
        return pop_data;
    }
}

void Stack_Array::display()
{
    for (int i = top; i > -1; i--)
    {
        cout << stack[i] << endl;
    }
}

void Stack_Array::clear()
{
    top = -1;
}

class Stack_List
{
    Node *top;

public:
    Stack_List()
    {
        top = NULL;
    }
    ~Stack_List()
    {
        while (top != NULL)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
    void push(Node *node);
    int pop();
    void display();
    void clear();
};

void Stack_List::push(Node *node)
{
    if (top == NULL)
    {
        top = node;
    }
    else
    {
        node->next = top;
        top = node;
    }
}

int Stack_List::pop()
{
    if (top == NULL)
    {
        return -1;
    }
    else
    {
        Node *poppedNode = top;
        top = top->next;
        poppedNode->next = NULL;
        return poppedNode->data;
    }
}

void Stack_List::display()
{
    if (top == NULL)
    {
        cout << "Stack underflow" << endl;
    }
    else
    {
        Node *ptr = top;
        while (ptr != NULL)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
}

void Stack_List::clear()
{
    top = NULL;
}

int main()
{
    int array[14];
    Stack_Array stack_arr(10);
    Stack_List stack_list;
    srand(time(NULL));

    for (int i = 0; i < 14; i++)
    {
        array[i] = rand();
    }

    

    

    cout << "Using Stack - Array" << endl;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < 10; i++)
    {
        stack_arr.push(array[i]);
    }
    stack_arr.display();

    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        stack_arr.pop();
    }
    stack_arr.display();
    cout << endl;
    for (int i = 10; i < 14; i++)
    {
        stack_arr.push(array[i]);
    }
    stack_arr.display();
    cout << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"Time taken by Stack - Array : "<<duration.count()<<endl;
    /////////////////////////////////////////////////////////////////
    cout << "Using Stack - Linked List" << endl;
    start = high_resolution_clock::now();
    for (int i = 0; i < 10; i++)
    {
        stack_list.push(new Node(array[i]));
    }
    stack_list.display();
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        stack_list.pop();
    }
    stack_list.display();
    cout << endl;
    for (int i = 10; i < 14; i++)
    {
        stack_list.push(new Node(array[i]));
    }
    stack_list.display();
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout<<"Time taken by Stack - Linked List : "<<duration.count()<<endl;
    return 0;
}