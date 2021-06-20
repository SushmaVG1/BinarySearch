#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *arr, int start, int end, int key)
{
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]==key)
            return mid;
        else if(mid>0 && arr[mid-1]==key)
            return mid-1;
        else if(mid<end-1 && arr[mid+1]==key)
            return mid+1;
        else if(arr[mid]<key)
            start = mid + 2;
        else
            end = mid - 2;
    }
    return -1;
}

int main()
{
    int size;
    printf("Enter the length of nearly sorted array : ");
    scanf("%d",&size);
    int *arr = (int *)malloc(size*sizeof(int));
    printf("Enter the contents of array : ");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter the key to be searched : ");
    scanf("%d",&key);
    int index = binarySearch(arr,0,size,key);
    printf("Key found at index : %d",index);
    return 0;
}
