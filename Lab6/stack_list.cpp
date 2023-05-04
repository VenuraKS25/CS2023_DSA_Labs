#include<iostream>

using namespace std;

class Node
{    
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack_List
{
    Node* top;
    public:
    Stack_List()
    {
        top = NULL;
    }
    ~Stack_List()
    {
        while(top != NULL)
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    void push(Node* node);
    int pop();
    void display();
    void clear();
};

void Stack_List::push(Node* node)
{
    if(top == NULL)
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
    if(top == NULL)
    {
        return -1;
    }
    else
    {
        Node* poppedNode = top;
        top = top->next;
        poppedNode->next = NULL;
        return poppedNode->data;
    }
}

void Stack_List::display()
{
    if(top == NULL)
    {
        cout<<"Stack underflow"<<endl;
    }
    else
    {
        Node* ptr = top;
        while(ptr != NULL)
        {
            cout<<ptr->data<<endl;
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
    Stack_List stack_list;
    srand(time(NULL));

    cout<<"Using Stack - Linked List"<<endl;
    for(int i = 0; i<10; i++)
    {
        stack_list.push(new Node(rand()));
    }
    stack_list.display();
    cout<<endl;
    for(int i = 0; i<5; i++)
    {
        stack_list.pop();
    }
    stack_list.display();
    cout<<endl;
    for(int i = 0; i<4; i++)
    {
        stack_list.push(new Node(rand()));
    }
    stack_list.display();

    return 0;
}