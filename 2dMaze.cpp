#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool IsSafe(int **arr,int size,int x,int y){
    if(x<size && y<size && arr[x][y]==1){
        return true;
    }
    return false;
}

bool SquareMaze(int **arr,int size,int x,int y,int **Sol){
    if(x==size-1 && y==size-1){
        Sol[x][y]=1;
        return true;
    }
    if(IsSafe(arr,size,x,y)){
        Sol[x][y]=1;
        if(SquareMaze(arr,size,x+1,y,Sol)){
            return true;
        }
        if(SquareMaze(arr,size,x,y+1,Sol)){
            return true;
        }
        Sol[x][y]=0;
        return false;
    }
    return false;
}

int main(){
    int n=5;
    
    int *arr=(int*) malloc(sizeof(int *)*5);
    for(int i=0;i<5;i++){
        (arr+i)=(int) malloc(sizeof(int)*5);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("arr[%d][%d]:",i+1,j+1);
            scanf("%d",*(arr+i)+j);
        }
    }
    printf("The given maze is:\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d ", (*(arr+i)+j));
            }
            printf("\n");
        }
    
    int *Sol=(int*) malloc(sizeof(int *)*5);
    for(int i=0;i<5;i++){
        (Sol+i)=(int) malloc(sizeof(int)*5);
        for(int j=0;j<5;j++){
            Sol[i][&j]=0;
        }
    }
    printf("The solution maze is:\n");
    if(SquareMaze(&arr,5,0,0,&Sol)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d ",Sol[i][&j]);
            }
            printf("\n");
        }
    }
    return 0;
}