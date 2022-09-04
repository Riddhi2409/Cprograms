#include<stdio.h>
int adj[4][4]={0};
void multiply(int a[4][4],int b[4][4],int c[4][4]){
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            int sum=0;
            for  (int k =0;k<4;k++)
            {
                sum+= a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }
    }
}
void powMatrix(int p, int adjp[4][4]){
    int i,j,k,c[4][4]={0};
     for(i=0; i<4; i++){
          for(j=0; j<4; j++){
           adjp[i][j] = adj[i][j];
          }
     }
    for (i=0;i<p-1;i++){
        multiply(adjp,adj,c);
        for(k=0; k<4; k++){
          for(j=0; j<4; j++){
            adjp[k][j] = c[k][j];
          }
        }
    }

}
void display(int a[4][4]){
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            printf("%d ",a[i][j]);
        };
        printf("\n");
    }
}
void main()
{
    int nodes,i,edges,j,k;
    printf("enter no. of edges: ");
    scanf("%d",&edges);
    printf("enter the no. of nodes: ");
    scanf("%d",&nodes);
    int temp[4][4]={0};
    printf("the nodes which are directly connected:\n");
    for (i=0;i<edges;i++){
        int x ,y;
        scanf("%d %d",&x,&y);
        adj[x][y]=1;
    }
    int p[4][4]={0};
    for (i=1;i<=4;i++){
        powMatrix(i,temp);
        printf("adjacenct power raised to %d:\n",i);
        display(temp);
        for (k=0;k<4;k++){
            for (j=0;j<4;j++){
                p[k][j]+=temp[k][j];
            }
        }
    }
    for (i=0;i<4;i++){
        for(j=0;j<4;j++){
            if (p[i][j]!=0)
                p[i][j]=1;
        }
    }
    printf("the path matrix is :\n");
    display(p);
}