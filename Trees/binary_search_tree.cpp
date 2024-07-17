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

bool search(Node *root,int key)
{
    if(root == NULL)
    {
        return false;
    }
    if(key==root->data)
    {
        return true;
    }
    else if(key > root->data)
    {
        return search(root->right,key);
    }
    else if(key < root->data)
    {
        return search(root->left,key);
    }
}

Node *deletefromBST(Node *root,int val)
{
    if(root==NULL)
        return root;
    if(root->data == val)
    {

        //0 child
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

        //1 child
        //left node
        if(root->left!=NULL && root->right==NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;

        }
        if(root->left==NULL && root->right!=NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }

        //2 child
        if(root->left!=NULL && root->right!=NULL)
        {
            Node *temp = root->right;
            while(temp->left!=NULL)
            {
                temp = temp->left;
            }
            int mini = temp->data;
            root->data = mini;
            root->right = deletefromBST(root->right,mini);
            return root;
        }
    }
    else if(val > root->data)
    {
        root->right = deletefromBST(root->right,val);
        return root;
    }
    else if(val  < root->data)
    {
        root->left = deletefromBST(root->left,val);
        return root;
    }
}

int main()
{
    Node *root = NULL;
    int d,key,val;
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

    cout<<"Enter the data to be searched"<<endl;
    cin>>key;
    if(search(root,key))
        cout<<"Data found"<<endl;
    else    
        cout<<"No data found"<<endl;

    cout<<"Enter the data to be deleted"<<endl;
    cin>>val;
    root = deletefromBST(root,val);

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
