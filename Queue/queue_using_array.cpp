// Online C++ compiler to run C++ program online
#include <iostream>
#define n 5
using namespace std;

class queue{
    public:
    int front;
    int rear;
    int arr[n];
    
    queue()
    {
        front = -1;
        rear = -1;
    }
    void enqueue(int val)
    {
        if(rear==n-1)
            cout<<"Queue full"<<endl;
        else
        {
            if(front==-1 && rear==-1)
            {
                rear++;
                front++;
            }
            else
            {
                rear++;
                
            }
            arr[rear] = val;
        }
    }
    void dequeue()
    {
        if(front==-1 && rear==-1)
            cout<<"Queue empty"<<endl;
        else
        {
            for(int i=0;i<rear;i++)
            {
                arr[i] = arr[i+1];
            }
            rear--;
        }
    }
    int frontele()
    {
        return arr[front];
    }
    int rearele()
    {
        return arr[rear];
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
    cout<<q.frontele()<<endl;
    cout<<q.rearele()<<endl;
    q.dequeue();
    q.dequeue();
    cout<<q.frontele()<<endl;
    cout<<q.rearele();
    return 0;
}
