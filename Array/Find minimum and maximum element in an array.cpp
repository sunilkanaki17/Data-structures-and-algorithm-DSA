class Solution {
public:
    pair<long long, long long> getMinMax(long long a[], int n) {
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(max<a[i])
            {
                max=a[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(min>a[i])
            {
                min=a[i];
            }
        }
        return {min,max};
    }
};
