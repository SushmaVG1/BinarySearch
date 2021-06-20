#include <stdio.h>
#include <stdlib.h>

int peak(int *arr,int n)
{
    int start = 0;
    int end = n;
    while(start<end)
    {
        int mid = start + (end-start)/2;
        if(mid == 0 && arr[mid]>arr[mid+1])
            return mid;
        else if(mid == 0 && arr[mid]<arr[mid+1])
            break;
        if(mid == n-1 && arr[mid]>arr[mid-1])
            return mid;
        else if(mid == n-1 && arr[mid]<arr[mid-1])
            break;
        else if ( arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1] )
            return mid;
        else if (arr[mid-1]>arr[mid+1])
            end = mid;
        else
            start = mid;
    }
    return -1;
}

int main()
{
    int n;
    printf("Enter size of mountain / bitonic array : ");
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    printf("Enter the contents of array : ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int index = peak(arr,n);
    printf("Index of peak element : %d", index);
    return 0;
}
