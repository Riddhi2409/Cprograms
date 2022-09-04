#include<stdio.h>
int adj[4][4]={0};
#define INF 999

void display(int a[4][4]){
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            printf("%d ",a[i][j]);
        };
        printf("\n");
    }
}

int min(int a, int b){
    if (a>b){
        return b;
    }
    return a;
}

void floyd(int p[4][4]){
    int i,j,k;
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            for (k=0;k<4;k++){
                p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
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
    printf("the nodes which are directly connected and weight:\n");
    for (i=0;i<edges;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        adj[x][y]=w;
    }
    display(adj);
    printf("\n");
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            if (adj[i][j]==0){
                p[i][j]=INF;
            }
            else
                p[i][j]=adj[i][j];
        }
    }
    display(p);
    printf("\n");
    printf("all pair shortest path:\n");
    floyd(p);
    display(p);
}