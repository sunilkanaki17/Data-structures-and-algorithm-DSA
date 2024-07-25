#include<bits/stdc++.h>
using namespace std;

void insertionsort(int arr[],int n)
{
    int temp;
    int j;
    for(int i=1;i<n;i++)
    {
        temp=arr[i];
        j = i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
        
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
        arr[i] = rand()%100;
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    insertionsort(arr,n);
    printarr(arr,n);
}