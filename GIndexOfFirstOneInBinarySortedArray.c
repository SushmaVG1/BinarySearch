#include <stdio.h>
#include <stdlib.h>

int searchFirstOne(int *arr, int n)
{
    int start = 0;
    int end = n;
    int ans = -1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]==1)
        {
            ans = mid;
            end = mid-1;
        }
        else
            start = mid+1;
    }
    return ans;
}

int main()
{
    int num;
    printf("Enter array length : ");
    scanf("%d",&num);
    int *arr = (int *)malloc(num*sizeof(int));
    printf("Enter the binary sorted array : ");
    for(int i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
    }
    int ans = searchFirstOne(arr,num);
    printf("Index of first 1 : %d",ans);
    return 0;
}
