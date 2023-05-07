#include<stdio.h>
#include<stdlib.h>
int vertices;
void printgraph(int graph[][vertices])
{
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

void prims(int i,int graph[][vertices])
{
    int key[vertices];
    int parents[vertices];
    int visited[vertices];
    for(int j=0;j<vertices;j++)
    {
        key[j]=9999;
        parents[j]=-1;
        visited[j]=0;
    }
    int count=0;
    int term=i;
    
    while(1)
    {
        for(int j=0;j<vertices;j++)
        {
        if(visited[j]!=1 && graph[i][j]<key[j])
        {
            key[j]=graph[i][j];
            parents[j]=i;
        }
        }
        int smallest=9999;
        for(int j=0;j<vertices;j++)
        {
            if(smallest>key[j]&& visited[j]!=1)
            {
                smallest=key[j];
                i=j;
            }
        }
        
        visited[i]=1;
        count++;
        if(count==6)
        {
            break;
        }
    }
    
    //printf("Edge \t Weight \n");
    for(int j=0;j<vertices;j++)
    {
        printf("%d - %d = %d \n",j,parents[j],key[j]);
    }

}

int main()
{
    printf("Enter the no of vertices: ");
    scanf("%d",&vertices);
    int graph[vertices][vertices];
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
           if(i==j)
        {
            graph[i][j]=0;
        }
        else
        {
            graph[i][j]=9999;
        } 
        }
        
    }
    
    int choice=1;
    while(choice==1)
    {
        int i,j,cost;
        printf("Enter vertices between which you want edges: ");
        scanf("%d %d",&i,&j);
        printf("Enter the cost: ");
        scanf("%d",&cost);
        graph[i][j]=cost;
        graph[j][i]=cost;
        printf("Enter 1 if you want to add edges: ");
        scanf("%d",&choice);
    }
    
    printgraph(graph);
    prims(5,graph);
    return 0;
    
}


