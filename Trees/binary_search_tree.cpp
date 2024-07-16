#include<bits/stdc++.h>
using namespace std;

class Node
{
    public: 
        int data;
        Node *left;
        Node *right;
    
    Node(int x)
    {
        this->data = x;
        this->right = NULL;
        this->left = NULL;
    }
};
Node *insert(Node *root,int val)
{
    if(root==NULL)
    {
        root = new Node(val);
        return root;
    }
    else if(val < root->data)
    {
        root->left = insert(root->left,val);
    }
    else if(val > root->data)
    {
        root->right = insert(root->right,val);
    }
    return root;
}

void inorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL); //act as seperator

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }

    }

}

int main()
{
    Node *root = NULL;
    int d;
    cout<<"Enter the data (-1 to exit)"<<endl;
    cin>>d;
    while(d!=-1)
    {
        root = insert(root,d);
        cin>>d;
    }
    cout<<"Inorder : ";
    inorder(root);
    cout<<endl;

    cout<<"Preorder : ";
    preorder(root);
    cout<<endl;

    cout<<"Postorder : ";
    postorder(root);
    cout<<endl;

    cout<<"Levelorder : "<<endl;
    levelorder(root);
    cout<<endl;

}
