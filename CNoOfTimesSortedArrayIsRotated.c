#include <stdio.h>
#include <stdlib.h>

int rotations(int *arr, int start, int end, int n)
{
    end--;
    while(start<=end)
    {
        if(arr[start]<=arr[end])
            return start;
        int mid = start + (end-start)/2;
        if(arr[mid]<arr[(mid+1)%n] && arr[mid]<arr[(mid-1+n)%n])
            return mid;
        else if(arr[start]<=arr[mid])
            start = mid + 1;
        else if(arr[mid]<=arr[end])
            end = mid - 1;
        else
            continue;
    }
    return -1;
}

int main()
{
    int n;
    printf("Enter length of rotated array : ");
    scanf("%d",&n);
    printf("Enter the contents of rotated array : ");
    int *arr = (int *)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int rot = rotations(arr,0,n,n);
    printf("No of times the array is rotated : %d\n",rot);
    return 0;
}
