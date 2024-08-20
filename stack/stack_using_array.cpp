// Online C++ compiler to run C++ program online
#include <iostream>
#define max 100
using namespace std;

class stack{
    public : 
    int top;
    int a[max];
     
    stack()
    {
        this->top = -1;
    }
    bool isfull()
    {
        if(top==max)
            return true;
        return false;
    }
    bool isempty()
    {
        if(top==-1)
            return true;
        return false;
    }
    
    void push(int x)
    {
        if(isfull())
            cout<<"Stack overflow"<<endl;
        else
        {
            top=top+1;
            a[top] = x;
        }
    }
    
    int pop()
    {
        int x;
        if(isempty())
        {
            cout<<"Stack underflow"<<endl;
        }
        else
        {
            x = a[top];
            top=top-1;
            return x;
            
        }
        return -1;
    }
    
    int peek()
    {
        return a[top];
    }
    
};

int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(17);
    s.push(27);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop();
    
    
}
