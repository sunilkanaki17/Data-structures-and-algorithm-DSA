#include<bits/stdc++.h>
using namespace std;

void selectionsort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        if(min!=i)
        {
            swap(arr[min],arr[i]);
        }
    }
    cout<<"Selection sort : ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
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

    selectionsort(arr,n);
}