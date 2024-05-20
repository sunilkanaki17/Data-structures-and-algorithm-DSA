#include <bits/stdc++.h>
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
void insertatbeg(Node *&head,int x)
{
    Node *newnode = new Node(x);
    newnode->next = head;
    head = newnode;
}

void insertatend(Node *&head,int x)
{
    Node *newnode = new Node(x);
    if(head==NULL)
    {
        head = newnode;
    }
    else{
    Node *temp;
    temp=head;
    while(temp->next!=NULL)
    {
        temp= temp->next;
    }
    temp->next = newnode;
    }
}

void insertatpos(Node *&head,int x)
{
    Node *temp = head;
    Node *y;
    int pos,c=0;
    cout<<"Enter Position";
    cin>>pos;
    while(temp!=NULL)
    {
        c+=1;
        if(c==pos-1)
        {
            Node *newnode = new Node(x);
            y = temp->next;
            temp->next = newnode;
            newnode->next = y; 
        }
        temp=temp->next;
    }

}

void deleteatpos(Node *&head,int x)
{
    int c=0;
    Node *temp=head;
    if(x==1)
    {
        head=temp->next;
       // free(temp);
    }
    else{
   
    while(temp!=NULL)
    {
        c++;
        if(c==x-1)
        {
            //free(temp->next);
            temp->next = temp->next->next;
        }
        temp=temp->next;
    }
    }

}

void display(Node *&head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
int main() {
   Node *head= NULL;
   int choice;
   int val;
   while(1)
   {
   cout<<"Enter choice"<<endl;
   cout<<"1 - Insert at beginning"<<endl<<"2 - Insert at end"<<endl<<"3 - Insert at Position"<<endl<<"4 - Delete at Pos"<<endl<<"5 - Exit"<<endl;
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
        case 3:cout<<"Enter Data"<<endl;
               cin>>val;
               insertatpos(head,val);
               display(head);
               break;
        case 4:cout<<"Delete at Position"<<endl;
               cin>>val;
               deleteatpos(head,val);
               display(head);
               break;
        case 5: exit(0);
                break;
        default :cout<<"Invalid choice"<<endl;
                    break;
        
   }
   }
}
