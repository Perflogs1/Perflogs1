#include<stdio.h>
#include<stdlib.h>
#define INFINITY 9999
#define MAX 10

void djisktra(int G[MAX][MAX],int n,int startnode)
{
    int visited[MAX];
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int count,mindistance,minnode,nextnode;
    
    int i,j;
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            if(G[i][j]==0)
            {
                cost[i][j]=INFINITY;
            }
            else
            {
                cost[i][j]=G[i][j];
            }
        }
    }
    
    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        visited[i]=0;
        pred[i]=startnode;
    }
    
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    while(count<n-1)
    {
        mindistance=INFINITY;
        for(i=0;i<n;i++)
        {
            if(distance[i]<mindistance && !visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
        }
        visited[nextnode]=1;
        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(mindistance+cost[nextnode][i]<distance[i])
                {
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
            }
        }
        count++;
    }
    
    for(i=0;i<n;i++)
    {
        if(i!=startnode)
        {
            printf("Shortest distance of node %d=%d \n",i,distance[i]);
            printf("Path = %d",i);
            j=i;
        }
        do{
            j=pred[j];
            printf("<-%d",j);
        }while(j!=startnode);
    }
    
}

int main()
{
    int init[MAX][MAX];
    int i,j;
    int start;
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            init[i][j]=1;
            if(i==j)
            {
                init[i][j]=0;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(init[i][j]==1 && i!=j)
            {
                int value;
                printf("Enter the distance from node %d to %d: ", i, j);
                scanf("%d", &value);
                init[i][j] = value;
                init[j][i] = value;
            }
        }
    }
    printf("Enter the source node: ");
    scanf("%d",&start);
    djisktra(init,n,start);
    
    return 0;
}

