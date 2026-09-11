#include <stdio.h>
struct Pair {
    int max;
    int min;
};
struct Pair getMinMax(int arr[], int low, int high) {
    struct Pair result, left_pair, right_pair;
    int mid;
    if (low == high) {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            result.max = arr[low];
            result.min = arr[high];
        } else {
            result.max = arr[high];
            result.min = arr[low];
        }
        return result;
    }
    mid = (low + high) / 2;
    
    left_pair = getMinMax(arr, low, mid);
    right_pair = getMinMax(arr, mid + 1, high);

    if (left_pair.max > right_pair.max) {
        result.max = left_pair.max;
    } else {
        result.max = right_pair.max;
    }
    
    if (left_pair.min < right_pair.min) {
        result.min = left_pair.min;
    } else {
        result.min = right_pair.min;
    }
    return result;
}
int main(){
    int n,a[100];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++){
     scanf("%d", &a[i]);
    }
     struct Pair result = getMinMax(a, 0, n- 1);
    printf("Minimum element in the array: %d\n", result.min);
    printf("Maximum element in the array: %d\n", result.max);
    return 0;
}
