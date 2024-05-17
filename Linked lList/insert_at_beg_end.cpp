#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
void insertatbeg(Node *&head,int val) ///Insert at beginning
{
    if(head==NULL)
    {
        Node *temp = new Node(val);
        temp->next = NULL;
    }
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

void insertatend(Node *&head,int val)
{
    Node *temp1;
    if(head==NULL)
    {
        Node *temp = new Node(val);
        temp->next = NULL;
    }
    Node *temp = new Node(val);

    temp1 = head;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next = temp;
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
    Node *head = NULL;
    //Node *node1=new Node(10);

    insertatbeg(head,10);
    print(head);

    insertatend(head,30);
    print(head);


}
