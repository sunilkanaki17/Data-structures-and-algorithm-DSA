class Solution{
    public:
    // Function to search x in arr
    // arr: input array
    // X: element to be searched for
    int search(int arr[], int N, int X)
    {
        int result;
        for(int i=0;i<N;i++)
        {
            if(arr[i]==X)
            {
                result=i;
                break;
            }
            else
            {
                result=-1;
            }
        }
        return result;      
    }
};
