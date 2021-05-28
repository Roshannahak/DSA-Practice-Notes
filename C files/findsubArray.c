#include <stdio.h>

void possibalSubarray(int *a, int size)
{
    int maxsum = a[0];
    for (int start = 0; start < size; start++)
    {
        for (int end = start; end < size; end++)
        {
            int sum = 0;
            for (int k = start; k <= end; k++)
            {
                sum = sum + a[k];
                if (maxsum < sum)
                {
                    maxsum = sum;
                }
                
            }
            printf("%d\n", sum);
        }
    }
    printf("the maximum sum of array is %d", maxsum);
}

int main()
{
    int arr[] = {1, 5, 6, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    possibalSubarray(arr, size);

    return 0;
}