#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
     int data;
     Node *next;

     Node(int x)
     {
        this->data = x;
        this->next = NULL;
     }
};

void insertatbeg(Node *&head,int x)
{
    Node *newnode = new Node(x);
    Node *temp=head;
    if(head==NULL)
    {
        head = newnode;
        head->next = head;
    }
    else{
       newnode->next = head;
       while(temp->next!=head)
       {
        temp=temp->next;
       }
       temp->next = newnode;
       head = newnode;
    }
}

void insertatend(Node *&head,int x)
{
    Node *newnode = new Node(x);
    Node *temp=head;
    if(head==NULL)
    {
        head = newnode;
        head->next = head;
    }
    else{
       while(temp->next!=head)
       {
        temp=temp->next;
       }
       temp->next = newnode;
       newnode->next = head;
    }
}

void insertatpos(Node *&head,int x,int pos)
{
    Node *newnode = new Node(x);
    Node *temp1;
    Node *temp = head;
    int count=0;
    while(temp->next!=head)
    {
        count++;
        if(count==pos)
        {
            temp1 = temp->next;
            temp->next = newnode;
            newnode->next = temp1;
            break;
        }
        temp=temp->next;
    }
}

void deleteatbeg(Node *&head)
{
    if(head==NULL)
    {
        cout<<"No Nodes"<<endl;
    }
    else if(head->next==head)
    {
        head = NULL;
    }
    else{
        Node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next = head->next;
        head = head->next;
    }
}

void deleteatend(Node *&head)
{
    if(head==NULL)
    {
        cout<<"No Nodes"<<endl;
    }
    else if(head->next==head)
    {
        head = NULL;
    }
    else{
        Node *temp=head;
        Node *temp1=NULL;
        while(temp->next!=head)
        {
            temp1 = temp;
            temp=temp->next;
        }
        temp1->next = head;
        free(temp);
    }
}

void deleteatpos(Node *&head,int pos)
{
    Node *temp=head;
    Node *temp1=NULL;
    int count = 0;
    while (temp->next!=head)
    {
        count++;
        if(count==pos)
        {
            temp1->next = temp->next;
            free(temp);
            break;
        }
        temp1 = temp;
        temp=temp->next;
    }
    
}

void display(Node *&head)
{
    if(head==NULL)
    {
        cout<<"No nodes to display"<<endl;
    }
    else{
    Node *temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    }
}

int main()
{
   Node *head=NULL;
   int choice;
   int val;
   int pos;
   while(1)
   {
   cout<<"Enter choice"<<endl;
   cout<<"1 - Insert at beg"<<endl<<"2 - Insert at end"<<endl<<"3 - Insert at pos"<<endl<<"4 - Delete at beg"<<endl<<"5 - Delete at end"<<endl<<"6 - Delete at Pos"<<endl;
   cin>>choice;
   switch(choice)
   {
       case 1: cout<<"Enter Data"<<endl;
               cin>>val;
               insertatbeg(head,val);
               display(head);
               break;
        case 2: cout<<"Enter Data"<<endl;
               cin>>val;
               insertatend(head,val);
               display(head);
               break;
        case 3: cout<<"Enter Data"<<endl;
               cin>>val;
               cout<<"Enter Pos"<<endl;
               cin>>pos;
               insertatpos(head,val,pos);
               display(head);
               break;
        case 4 : deleteatbeg(head);
                display(head);
                break;
        case 5 : deleteatend(head);
                display(head);
                break;
        case 6 : cout<<"Enter Pos"<<endl;
               cin>>pos;
               deleteatpos(head,pos);
               display(head);
               break;
    }
   }
}