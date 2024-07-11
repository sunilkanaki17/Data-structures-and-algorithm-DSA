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
     newnode->next = NULL;
    if(head==NULL)
    {
        head = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
}

void insertatend(Node *&head,int x)
{
    Node *newnode = new Node(x);
    Node *temp=head;
    newnode->next = NULL;
    if(head==NULL)
    {
        head = newnode;
    }
    else{
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = newnode;
    }
}

void display(Node *&head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertatpos(Node *&head,int x,int pos)
{
    int count=0;
    Node *newnode = new Node(x);
    Node *temp=head;
    Node *temp1=NULL;
    newnode->next = NULL;
    while(temp->next!=NULL)
    {
        count++;
        
        if(count==pos-1)
        {
            temp1=temp->next;
            temp->next = newnode;
            newnode->next = temp1;
            
        }
        temp=temp->next;     
    }

}

void deleteatbeg(Node *&head)
{
    Node *temp=head;
    if(head==NULL)
    {
        cout<<"No nodes"<<endl;
    }
    else{
        head = head->next;
        free(temp);
    }
}

void deleteatend(Node *&head)
{
    Node *temp=head;
    Node *temp1=NULL;
    if(head==NULL)
    {
        cout<<"No nodes"<<endl;
    }
    else{
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next = NULL;
        free(temp);

    }
}

void deleteatpos(Node *&head,int pos)
{
    int count=0;
    Node *temp=head;
    Node *temp1=NULL;
    if(head==NULL)
    {
        cout<<"No nodes"<<endl;
    }
    else{
        while(temp->next!=NULL)
        {
            count++;
            if(count==pos)
            {
                temp1->next = temp->next;
                free(temp);
                break;
            }
            else{
            temp1=temp;
            temp=temp->next;
            }
        }

    }
}

void reverse(Node *&head)
{
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;

    while(curr!=NULL)
    {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
    }
    head = prev;
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
   cout<<"1 - Insert at beg"<<endl<<"2 - Insert at end"<<endl<<"3 - Insert at pos"<<endl<<"4 - Delete at beg"<<endl<<"5 - Delete at end"<<endl<<"6 - Delete at Pos"<<endl<<"7 - Reverse"<<endl;
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
        case 7: reverse(head);
                display(head);
                break;
    }
   }
}
