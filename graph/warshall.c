#include<stdio.h>
int adj[4][4]={0};
void display(int a[4][4]){
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            printf("%d ",a[i][j]);
        };
        printf("\n");
    }
}
printf("the path matrix is : \n")
void warshall(int a[4][4]){
    int i,j,k;
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            for (k=0;k<4;k++){
                a[i][j]=a[i][j] || (a[i][k] && a[k][j]);
            }
        }
    }
}
void main()
{
    int nodes,i,edges,j,k;
    printf("enter no. of edges: ");
    scanf("%d",&edges);
    printf("enter the no. of nodes: ");
    scanf("%d",&nodes);
    int p[4][4]={0};
    printf("the nodes which are directly connected:\n");
    for (i=0;i<edges;i++){
        int x ,y;
        scanf("%d %d",&x,&y);
        adj[x][y]=1;
    }
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            p[i][j]=adj[i][j];
        }
    }
    warshall(p);
    display(p);
}