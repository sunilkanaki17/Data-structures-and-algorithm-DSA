#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;  
    }
};
void inseratbegin(Node *&head,int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head=temp;
}
void insertatend(Node *&tail,int d)
{
    Node *temp = new Node(d);
    //temp->next = NULL;
    tail->next = temp;
    tail = temp;

}
void print(Node *&head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node *node1 = new Node(10);
   // node *node1 = new node(20);
   Node * head = node1;
   Node *tail = node1;

    inseratbegin(head,69);
    print(head);
    //cout<<endl;

    inseratbegin(head,11);
    print(head);

    inseratbegin(head,20);
    print(head);

    inseratbegin(head,9);
    print(head);

    insertatend(tail,25);
    print(head);

    insertatend(tail,50);
    print(head);

    insertatend(tail,12);
    print(head);

    insertatend(tail,36);
    print(head);
}
