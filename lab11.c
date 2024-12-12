#include<stdio.h>
int visited[10],a[10][10],n;
void dfs(int source)
{
    int i;
    visited[source]=1;
    for(i=1;i<=n;i++)
        if(a[source][i]==1&&visited[i]==0)
            dfs(i);
}
void main()
{
    int i,j,source;
    printf("Enter the number of cities\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    printf("0 if there is no path,1 if there is a path\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    printf("Enter the source city\n");
    scanf("%d",&source);
    for(i=1;i<=n;i++)
    visited[i]=0;
    dfs(source);
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
            printf("node %d is not reachable\n",i);
        else
            printf("node %d is reachable\n",i);
    }

}
