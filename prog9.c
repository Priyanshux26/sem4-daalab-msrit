/*
Consider an electrical layout where ‘n’ houses are connected by electrical wires. Design a
program using Kruskal’s Algorithm to output a connection with minimum cost. Trace the
algorithm. Find its time complexity.
*/
#include <stdio.h>
int p[10];
int parent(int x)
{
    while(x!=p[x])
    {
        x=p[x];
    }
    return x;
}
void kruskal(int graph[10][10],int n)
{
    int u,v;
    for(int i=0;i<n;i++)    p[i]=i;
    int ne=0;
    int sum=0;
    while(ne<n-1)
    {
        int min= 999;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][j]<min)
                {
                    min=graph[i][j];
                    u=i;
                    v=j;
                }
            }
        }
        if(parent(u)!=parent(v))
        {
            printf("connect %d----->%d=%d\n",u,v,graph[u][v]);
            sum=sum+graph[u][v];
            p[v]=u;
            ne++;
        }
        graph[u][v]=999;
        graph[v][u]=999;        
        
        
    }
    printf("mst cost=%d",sum);
}

int main()
{
    int graph[10][10],n,source;
    printf("Enter number of node=");
    scanf("%d",&n);
    printf("\n Enter weighted graph\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    printf("-----------Minimum Spanning Tree-----------");
    kruskal(graph,n);

    return 0;
}


OUTPUT:
Enter number of node=6

 Enter weighted graph
0 30 40 999 999 999
30 0 50 10 999 999
40 50 0 999 20 999
999 10 999 0 60 80
999 999 20 60 0 70
999 999 999 80 70 0
..................Minimum Spanning Treee.....................
connect 1----->3=10
connect 2----->4=20
connect 0----->1=30
connect 0----->2=40
connect 4----->5=70
mst cost=170
