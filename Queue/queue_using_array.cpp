// Online C++ compiler to run C++ program online
#include <iostream>
#define n 5
using namespace std;

class queue{
    public:
    int arr[100];
    int front;
    int rear;
    
    queue()
    {
        front=0;
        rear=0;
    }
    
    void enqueue(int x)
    {
        if(rear==n)
            cout<<"overflow"<<endl;
        else
        {
            arr[rear++] = x;
        }
    }
    
    int dequeue()
    {
        int x;
        if(front==0 && rear==0)
        {
            cout<<"Empty"<<endl;
            return -1;
        }
        else
        {
            
            x = arr[front];
            arr[front] = -1;
            front++;
            if(front==rear)
            {
                front =0 ; rear=0;
            }

            }
        return x;
    }
    
};
int main() {
    queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    //cout<<q.dequeue()<<endl;
    q.enqueue(17);
    //cout<<q.dequeue()<<endl;
    //cout<<q.dequeue()<<endl;
    
    
}
