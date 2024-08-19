#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int x)
    {
        this->data = x;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertatbeg(Node *&head,int x)
{
    Node *newnode = new Node(x);
    if(head==NULL)
    {
        head = newnode;
        head->next = NULL;
        head->prev = NULL;
    }
    else{
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insertatend(Node *&head,int x)
{
    Node *newnode = new Node(x);
    Node *temp = head;
    if(head==NULL)
    {
        head = newnode;
        head->prev = NULL;
        head->next = NULL;
    }
    else{
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = NULL;
    }

}

void insertatpos(Node *&head,int x,int pos)
{
    Node *newnode = new Node(x);
    Node *temp = head;
    int count = 0;
    while(temp!=NULL)
    {
        count++;
        if(count==pos)
        {
            newnode->prev = temp;
            newnode->next = temp->next;
            temp->next->prev = newnode;
            temp->next = newnode;
            break;
        }
        temp=temp->next;
    }
}

void deleteatbeg(Node *&head)
{
    if(head==NULL)
    {
        cout<<"No nodes"<<endl;
    }
    else{
        if(head->next==NULL)
        {
            head=NULL;
        }
        else{
        head = head->next;
        head->prev = NULL;
        }
    }
}

void deleteatend(Node *&head)
{
    Node *temp=head;
    if(head==NULL)
    {
        cout<<"No nodes"<<endl;
    }
    else{
        if(head->next==NULL)
        {
            head=NULL;
        }
        else{
           while(temp->next!=NULL)
           {
            temp=temp->next;
           }
            temp->prev->next = NULL;
           
        }
    }
}

void deleteatpos(Node *&head,int pos)
{
    Node *temp1;
    Node *temp = head;
    int count = 0;
    while(temp!=NULL)
    {
        count++;
        if(count==pos)
        {
            temp1 = temp->prev;
            temp1->next = temp->next;
            temp->next->prev = temp1;
            free(temp);
            break;
        }
        temp=temp->next;
    }
}

void reverse(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL
    Node *next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        cur = next;
    }
    head = prev;
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
