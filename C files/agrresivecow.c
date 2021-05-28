#include<stdio.h>
 
int isvalid(int *a, int size, int mid){
    int cow = 1;
    int allow = a[0];
    int sub;

    for (int i = 1; i < size; i++)
    {
        sub = a[i] - allow;

        if (sub >= mid)
        {
            cow++;
            allow = a[i];
        }
        
    }
    return cow;
}

int main()
{
    int cow = 4;
    int arr[] = {1,5,8,11,13,16};
    int size = sizeof(arr)/sizeof(arr[0]);

    int start = arr[0];
    int end = size + 1;
    int ans = 0;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        int cowcount = isvalid(arr, size, mid);

        if (cowcount <= cow)
        {
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
        
    }

    printf("%d", ans);

    return 0;
}