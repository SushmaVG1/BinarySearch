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

int main()
{
    int num;
    printf("Enter length of array : ");
    scanf("%d",&num);
    int *arr = (int *)malloc(num*sizeof(int));
    printf("Enter contents of array : ");
    for(int i=0;i<num;i++)
        scanf("%d",&arr[i]);
    int key;
    printf("Enter key : ");
    scanf("%d",&key);
    int floor = findFloor(arr,num,key);
    int ceil = findFloor(arr,num,key);
    if(floor!=-1 && ceil!=-1)
    {
        int diff1 = key - floor;
        int diff2 = ceil - key;
        if(diff1<diff2)
            printf("Minimum difference element : %d",floor);
        else
            printf("Minimum difference element : %d",ceil);
    }
    if(floor==-1)
        printf("Minimum difference element : %d",ceil);
    if(ceil==-1)
        printf("Minimum difference element : %d",floor);
    return 0;
}
