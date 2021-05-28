#include<stdio.h>
 
int findMaxElement(int *a, int size){
    int max = a[0];

    for (int i = 0; i < size; i++)
    {
        if(max < a[i+1]){
            max = a[i + 1];
        }
    }
    return max;
}

int ArraySum(int *arr, int size){
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int isValid(int *a, int size, int std, int max){
    int student = 1;
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += a[i];

        if (sum > max)
        {
            sum = a[i];
            student++;
        }

        if (student > std)
        {
            return 0;
        }
    }
    return 1;
}

int bookAlocation(int *a, int size, int std){
    int start = findMaxElement(a, size);
    int end = ArraySum(a, size);
    int res = 0;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        
        if (isValid(a, size, std, mid))
        {
            res = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return res;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int std = 2;

    int size = sizeof(arr)/sizeof(arr[0]);

    printf("%d", bookAlocation(arr, size, std));

    return 0;
}