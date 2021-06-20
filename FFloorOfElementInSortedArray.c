#include <stdio.h>
#include <stdlib.h>

int findFloor(int *arr, int n, int key)
{
    int start = 0;
    int end = n;
    int floor = -1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]==key)
            return arr[mid];
        else if(arr[mid]<key)
        {
            floor = arr[mid];
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return floor;
}

int findCeil(int *arr, int n, int key)
{
    int start = 0;
    int end = n;
    int ceil = -1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]==key)
            return arr[mid];
        else if(arr[mid]>key)
        {
            ceil = arr[mid];
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ceil;
}

char findCharFloor(char *arr, int n, char key)
{
    int start = 0;
    int end = n;
    char floor = NULL;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]==key)
            return arr[mid];
        else if(arr[mid]<key)
        {
            floor = arr[mid];
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return floor;
}

char findCharCeil(char *arr, int n, char key)
{
    int start = 0;
    int end = n;
    char ceil = NULL;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]==key)
            return arr[mid];
        else if(arr[mid]>key)
        {
            ceil = arr[mid];
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ceil;
}

int main()
{
    int size;
    printf("Enter the length of the array : ");
    scanf("%d",&size);
    int * arr = (int *)malloc(size*sizeof(int));
    printf("Enter the contents of the array : ");
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    int num;
    printf("Enter the number : ");
    scanf("%d",&num);
    int floor = findFloor(arr,size,num);
    int ceil = findCeil(arr,size,num);
    printf("Floor : %d\n",floor);
    printf("Ceil : %d\n",ceil);
    printf("Enter characters : ");
    char * array = (char *)malloc(size+1*sizeof(char));
    for(int i=0;i<=size;i++)
        scanf("%c",&array[i]);
    fflush(stdin);
    printf("Enter a character : ");
    char ch;
    scanf("%c",&ch);
    char floor1 = findCharFloor(array,size,ch);
    char ceil1 = findCharCeil(array,size,ch);
    printf("Floor : %c\n",floor1);
    printf("Ceil : %c\n",ceil1);
    return 0;
}
