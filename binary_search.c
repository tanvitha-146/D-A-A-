#include<stdio.h>
int main()
{
    int i, n, key;
    int beg, end, mid;
    int found = 0;
    printf("Enter the no.of elements in the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements in the sorted order:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    beg = 0;
    end = n-1;
    while(beg <= end){
        mid = (beg + end) / 2;
        if(key == a[mid]){
            printf("Element is found at the position: %d\n", mid + 1);
            found = 1;
            break;
        }
        else if(key > a[mid]){
            beg = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return 0;
    
}