#include<bits/stdc++.h>
using namespace std;

void bubblesort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool swapped = false;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }   
}

void printarr(int arr[],int n)
{
    cout<<"Sorted: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n;
    int arr[100];
    cout<<"Enter n"<<endl;
    cin>>n;

    cout<<"Array : ";
    for(int i=0;i<n;i++)
    {
        arr[i] = rand()%10;
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    bubblesort(arr,n);
    printarr(arr,n);
}