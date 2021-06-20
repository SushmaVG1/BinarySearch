#include <stdio.h>
#include <stdlib.h>

int binarySearchRecursion(int *arr, int key, int start, int end)
{
    if(end>=start)
    {
        int mid = start + (end - start)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            return(binarySearchRecursion(arr,key,mid+1,end));
        else
            return(binarySearchRecursion(arr,key,0,mid-1));
    }
    return -1;
}

int binarySearchIterative(int *arr, int key, int start, int end)
{
    while(end>=start)
    {
        int mid = start + (end - start)/2;
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
    printf("Enter length of array : ");
    scanf("%d",&n);
    printf("Enter the contents of array : ");
    int *arr = (int *)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the number to be searched : ");
    int num;
    scanf("%d",&num);
    int index1 = binarySearchRecursion(arr,num,0,n);
    int index2 = binarySearchIterative(arr,num,0,n);
    printf("\nNumber is at index : %d\n",index1);
    printf("\nNumber is at index : %d\n",index2);
    return 0;
}
