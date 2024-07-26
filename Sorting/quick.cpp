#include<bits/stdc++.h>
using namespace std;

int partition(int *arr,int s,int e)
{
    int pivot = arr[s];
    int count = 0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivot)
            count++;
    }
    int pivotindex = s+count;
    swap(arr[s],arr[pivotindex]);

    int i=s,j=e;
    while(i<pivotindex && j>pivotindex)
    {
        while(arr[i] < pivot)
        {
            i++;
        }

        while(arr[j] > pivot)
        {
            j--;
        }

        if(i<pivotindex && j>pivotindex)
            swap(arr[i++],arr[j--]);
        
        
    }

    return pivotindex;
}

void quicksort(int *arr,int s,int e)
{
    //base class
    if(s>=e)
        return;
    
    int p = partition(arr,s,e);

    quicksort(arr,s,p-1);

    quicksort(arr,p+1,e);

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

    quicksort(arr,0,n-1);

     for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}
