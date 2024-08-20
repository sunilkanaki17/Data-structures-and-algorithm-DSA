// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node
{
    public:int data;
    Node *next;
    
    Node(int x)
    {
        this->data = x;
        next = NULL;
    }
};
class stack{
    public:
    Node *head;
    stack()
    {
       head = NULL;
    }
    void push(int x);
    void pop();
    int peek();
};
void stack::push(int x)
{
    Node *newnode = new Node(x);
    newnode->next = head;
    head = newnode;
}
void stack::pop()
{
    if(head==NULL)
        cout<<"underflow"<<endl;
    else
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}
int stack::peek()
{
    return head->data;
}
int main() {
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.pop();
    cout<<s.peek()<<endl;
}
