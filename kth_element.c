
#include <stdio.h>
int K_Small(int arr[], int n, int k) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            
            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
   
    return arr[k - 1];
}

int main() {
    int n, k;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    int arr[100]; 
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of which smallest element to be found: ");
    scanf("%d", &k);


    if (k > 0 && k <= n) {
        int result = K_Small(arr, n, k);
        printf("The %d-th smallest element is: %d\n", k, result);
    } else {
        printf("Invalid\n");
    }
    return 0;
}