#include <stdio.h>
#include <stdlib.h>
int * findKey(int **arr, int key, int row, int col)
{
    int *ans = (int *)malloc(2*sizeof(int));
    ans[0] = -1;
    ans[1] = -1;
    int i = 0;
    int j = col-1;
    while(j>=0 || i<row)
    {
        if(arr[i][j]==key)
        {
            ans[0]=i;
            ans[1]=j;
            break;
        }
        else if(arr[i][j]<key)
        {
            i++;
        }
        else
            j--;
    }
    return ans;
}

int main()
{
    int row, col;
    printf("Enter the no of rows : ");
    scanf("%d",&row);
    printf("Enter the no of columns : ");
    scanf("%d",&col);
    int **arr = (int **)malloc(row*sizeof(int *));
    printf("Enter the sorted 2D array : ");
    for(int i=0; i<row; i++)
    {
        arr[i] = (int *)malloc(col*sizeof(int));
        for(int j=0; j<col; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int key;
    printf("Enter key : ");
    scanf("%d",&key);
    int *index = findKey(arr, key, row, col);
    printf("%d %d\n",index[0],index[1]);
    return 0;
}
