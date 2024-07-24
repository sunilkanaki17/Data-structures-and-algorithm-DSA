#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5]={5,7,3,1,5};
    int temp;
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if(arr[i]>arr[j])
            {
                /*temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;*/

                //or swap
                swap(arr[i],arr[j]);
            }
        }
    }

    //if(arr[i]>arr[j]) -> ascending
    //if(arr[i]<arr[j]) -> descending
    cout<<"Sorted : ";
    for(int i=0;i<5;i++)
        cout<<arr[i]<<" ";
}