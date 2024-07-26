#include<bits/stdc++.h>
using namespace std;

void merge(int *arr,int s,int e)
{
    int mid = (s+e)/2;

    int l1 = mid-s+1;
    int l2 = e-mid;

    int *first = new int[l1];
    int *second = new int[l2];

    int mainindex = s;
    for(int i=0;i<l1;i++)
    {
        first[i] = arr[mainindex++];
    }

    for(int i=0;i<l2;i++)
    {
        second[i] = arr[mainindex++];
    }

    int index1 =0;
    int index2 = 0;
    mainindex = s;

    while(index1<l1 && index2<l2)
    {
        if(first[index1]<second[index2])
        {
            arr[mainindex++] = first[index1++];
        }
        else{
            arr[mainindex++] = second[index2++];
        }
    }

    while(index1<l1)
    {
        arr[mainindex++] = first[index1++];
    }

    while(index2<l2)
    {
        arr[mainindex++] = second[index2++];
    }

    delete[] first;
    delete[] second;

}

void mergesort(int *arr,int s,int e)
{
    //base class
    if(s>=e)
        return;
    
    int mid = (s+e)/2;

    //left element sort
    mergesort(arr,s,mid);

    //right element sort
    mergesort(arr,mid+1,e);

    //merge sorted array
    merge(arr,s,e);

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

    mergesort(arr,0,n-1);

     for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}
