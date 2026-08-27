#include<stdio.h>
#define SIZE 10
int hashTable[SIZE];

void initialise(){
    for(int i = 0; i < SIZE;i++)
    hashTable[i] = -1;
}

void insert(int key){
    int index = key % SIZE;
    int start = index;
    while (hashTable[index] != -1){
        index = (index + 1) % SIZE;
        if(index == start){
            printf("The hash Table is full\n");
            return;
        }
        
    }
    hashTable[index] =  key;
}
void display(){
    int i;
    printf("\nHASH TABLE\n");
    for(i = 0; i < SIZE;i++){
        if(hashTable[i] == -1)
            printf("%d : Empty\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
    }
}
int main(){
    int i,n,key;
    initialise();
    printf("Enter the number of elements:");
    scanf("%d", &n);

    printf("Enter the elements:");
    for(i = 0; i < n;i++){
        scanf("%d", &key);
        insert(key);
    }
    display();
    return 0;
}