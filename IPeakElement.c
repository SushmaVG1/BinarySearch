#include <stdio.h>
#include <stdlib.h>

int peakElement(int *arr, int n)
{
    int start = 0;
    int end = n;
    if(n==1)
        return 0;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(mid==0 && arr[mid]>arr[mid+1])
            return mid;
        if(mid==n-1 && arr[mid]>arr[mid-1])
            return mid;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            return mid;
        else if(arr[mid]<arr[mid-1])
            end = mid-1;
        else
            start = mid + 1;
    }
    return -1;
}

int main()
{
    int num;
    printf("Enter the size of array : ");
    scanf("%d",&num);
    int *arr = (int *)malloc(num*sizeof(int));
    printf("Enter array contents : ");
    for(int i=0;i<num;i++)
        scanf("%d",&arr[i]);
    int index = peakElement(arr,num);
    printf("Index of peak element : %d",index);
    return 0;
}
