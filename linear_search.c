#include <stdio.h>
int main() {
  int array[100], n, i, key;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++) {
        if (array[i] == key) {
            break; 
        }
    }
    if (i < n) {
        printf("Element %d found at position %d.\n", key, i + 1);
    } else {
        printf("Element %d not found in the array.\n", key);
    }
    return 0;
}
