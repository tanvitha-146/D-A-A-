#include<stdio.h>
int main(){
    int n,i,j,k;
    int path[10][10];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix(99999 for no edge):\n");
        for(i = 0; i < n; i++){
            for(j = 0; j < n;j++){
                scanf("%d", &path[i][j]);
            }
        }
    
        for(k = 0; k < n; k++){
            for(i = 0; i < n; i++){
                for(j = 0; j < n;j++){
                    if(path[i][k] != 99999 && path[k][j] != 99999 && path[i][k] + path[k][j] < path[i][j]){
                        path[i][j] = path[i][k] + path[k][j];
                    }
                }
            }
        }

    printf("The shortest distance matrix :\n");
    for(i = 0; i < n;  i++){
        for(j = 0; j < n; j++){
            if(path[i][j] == 99999){
                printf("inf ");
            }else{
                printf("%d ", path[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}