#include<stdio.h>
#include<stdlib.h>
struct Node{
    char ch;
    int freq;
    struct Node *left, *right;
};
struct Node* createNode(char ch,int freq){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void printCodes(struct Node *root,int code[],int top){
  if(root->left == NULL && root->right == NULL){
    printf("%c : ", root->ch);
  
  for(int i = 0; i < top;i++){
    printf("%d", code[i]);
  }
  printf("\n");
  return;
}

if(root->left != NULL){
    code[top] = 0;
    printCodes(root->left, code, top + 1);
}

if(root->right != NULL){
    code[top] = 1;
    printCodes(root->right, code, top + 1);
}
}

int main(){
    int n,i,j;
    char ch[20];
    int freq[20];
    struct Node *nodes[40], *temp;
    

    printf("Enter the number of the characters: ");
    scanf("%d", &n);
    
    printf("Enter the characters and their frequencies :\n");
    
    for(i = 0; i < n;i++){
        scanf(" %c %d", &ch[i], &freq[i]);
        nodes[i] = createNode(ch[i],freq[i]); 
    }
    int size = n;
    while(size > 1){
        
        for(i = 0;i < size - 1;i++){
            for(j = i + 1;j < size;j++){
                if(nodes[i]->freq > nodes[j]->freq){
                    temp = nodes[i];
                    nodes[i] = nodes[j];
                    nodes[j] = temp;
                }
            }
        }
        printf("Sorted frequencies: ");
for (i = 0; i < size; i++) {
    printf("%c(%d) ", nodes[i]->ch, nodes[i]->freq);
}
printf("\n");
    

    struct Node *left = nodes[0];
    struct Node *right = nodes[1];
    
    temp = createNode('$',left->freq + right->freq);
    temp->left = left;
    temp->right = right;

    nodes[0] = temp;
    nodes[1] = nodes[size - 1];
    size--;
    }
    int code[40];

    
    printf("\nHuffmann Codes:\n");
printCodes(nodes[0], code, 0);
    
    return 0;

}