#include <stdio.h>
#include <stdlib.h>

int findPeak(int *mountArr, int n)
{
    int start = 0;
    int end = n;
    while(start<end)
    {
        int mid = start + (end-start)/2;
        if(mountArr[mid]>mountArr[mid+1] && mountArr[mid]>mountArr[mid-1])
            return mid;
        else if(mountArr[mid-1]>mountArr[mid+1])
            end = mid;
        else
            start = mid;
    }
    return -1;
}

int binaryIncreasingSearch(int start, int end, int *m, int key)
{
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        int num = m[mid];
        if(num==key)
            return mid;
        else if(num<key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int binaryDecreasingSearch(int start, int end, int *m, int key)
{
    while(start<end)
    {
        int mid = start + (end-start)/2;
        int num = m[mid];
        if(num==key)
            return mid;
        else if(num>key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int findInMountainArray(int target, int *mountainArr, int n)
{
    int peak = findPeak(mountainArr, n);
    if(mountainArr[peak] == target)
        return peak;
    int index = binaryIncreasingSearch(0,peak,mountainArr,target);
    if(index != -1)
        return index;
    else
        index = binaryDecreasingSearch(peak,n,mountainArr,target);
    return index;
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
    int key;
    printf("Enter the key : ");
    scanf("%d",&key);
    int index = findInMountainArray(key,arr,n);
    printf("Index of the element : %d", index);
    return 0;
}
