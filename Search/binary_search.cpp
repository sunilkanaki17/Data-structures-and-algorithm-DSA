#include<bits/stdc++.h>
using namespace std;

int binarysearch(int *arr,int n,int key)
{
    int s=0;
    int e=n-1;
    int mid = s + (e-s)/2;

    while(s<=e)
    {
        if(key==arr[mid])
            return mid;

        else if(key > arr[mid])
        {
            s = mid+1;
        }
        else{
            e=mid-1;
        }

        mid = s + (e-s)/2;
    }
    return -1;
}

int main()
{
    int arr[6] = {2,4,6,8,10,12};
    int key = 10;
    int index = binarysearch(arr,6,key);
    cout<<index<<endl;
}