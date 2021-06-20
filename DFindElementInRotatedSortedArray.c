#include <stdio.h>
#include <stdlib.h>

int rotations(int *arr, int start, int end, int n)
{
    end--;
    while(start<=end)
    {
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

int binarySearch(int* arr, int key, int start, int end)
{
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            start = mid + 1;
        else
            end = mid - 1;
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
    int key;
    printf("Enter the key to be searched : ");
    scanf("%d",&key);
    int min = rotations(arr,0,n,n);
    int index1 = binarySearch(arr,key,0,min-1);
    int index2 = binarySearch(arr,key,min,n);
    if(index1 != -1)
        printf("Index : %d\n",index1);
    if(index2 != -1)
        printf("Index : %d\n",index2);
    return 0;
}

