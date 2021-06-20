#include <stdio.h>
#include <stdlib.h>
int firstOccurence(int *arr, int key, int start, int end)
{
    int first = -1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]==key)
        {
            first = mid;
            end = mid - 1;
        }
        else if(arr[mid]<key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return first;
}

int lastOccurence(int *arr, int key, int start, int end)
{
    int last = -1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]==key)
        {
            last = mid;
            start = mid + 1;
        }
        else if(arr[mid]<key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return last;
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
    int first = firstOccurence(arr,num,0,n);
    int last = lastOccurence(arr,num,0,n);
    printf("First occurence : %d\n",first);
    printf("Last occurence : %d\n",last);
    printf("Count of the number : %d\n",last-first+1);
    return 0;
}
