#include <stdio.h>
#include <limits.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int maxCrossingSum(int a[], int low, int mid, int high)
{
    int leftSum = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= low; i--)
    {
        sum += a[i];
        leftSum = max(leftSum, sum);
    }

    int rightSum = INT_MIN;
    sum = 0;

    for (int i = mid + 1; i <= high; i++)
    {
        sum += a[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubarraySum(int a[], int low, int high)
{
    if (low == high)
        return a[low];

    int mid = (low + high) / 2;

    int left = maxSubarraySum(a, low, mid);
    int right = maxSubarraySum(a, mid + 1, high);
    int cross = maxCrossingSum(a, low, mid, high);

    return max(max(left, right), cross);
}

int main()
{
    int n,a[100];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++){
     scanf("%d", &a[i]);
    }

    int result = maxSubarraySum(a, 0, n - 1);

    printf("Maximum subarray sum = %d\n", result);

    return 0;
}
