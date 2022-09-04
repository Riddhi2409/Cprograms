#include<stdio.h>
#include<string.h>
void main()
{
    int edge,node;
    printf("enter the no. of edges: ");
    scanf("%d",&edge);
    printf("enter the no. of node: ");
    scanf("%d",&node);
    int adjMat[15][15]={0};
    printf("enter the two nodes which are connected by direct edges:\n");
    for (int i=0;i<edge;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        adjMat[x][y]=1;
        adjMat[y][x]=1;
    }
    for (int i=0;i<node;i++){
        for (int j=0;j<node;j++){
            printf("%d ",adjMat[i][j]);
        };
        printf("\n");
    }
}