#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct Q
{
    int data[MAX];
    int rear,front;
}Q;

typedef struct node
{
    struct node *next;
    int vertex;
}node;

void enqueue(Q *,int);
int dequeue(Q *);
int empty(Q *);
int full(Q *);
void BFS(int);
void readgraph();            
void insert(int vi,int vj);     
void DFS(int i);
 void printlist();
int visited[MAX];
node *G[20];               
int n;                   
Q q;
void main()
{
    int i,op;
    
    do
      { printf("\n\n1)Create");
      printf("\n2.bfs");
  printf("\n3.dfs");
  printf("\n4.print grph");
  printf("\n5.exit");

        printf("\nEnter Your Choice: ");
        scanf("%d",&op);
        switch(op){
case 1: readgraph();
         
        break;
case 2: printf("\nStarting Node No. : ");
               scanf("%d",&i);
               BFS(i);
               
               
               break;
case 3:  for(i=0;i<n;i++)
             visited[i]=0;
               printf("\nStarting Node No. : ");
               scanf("%d",&i);
               DFS(i);
               
               break;

case 4:
                printlist(G);
                break;
          }
       }while(op!=5);
}

void BFS(int v)
{
    int w,i,visited[MAX];
    

    node *p;
    q.rear=q.front=-1;             
    for(i=0;i<n;i++)
        visited[i]=0;
    enqueue(&q,v);
    printf("\nVisit\t%d",v);
    visited[v]=1;
    while(!empty(&q))
    {
        v=dequeue(&q);
        
        for(p=G[v];p!=NULL;p=p->next)
        {
            w=p->vertex;
            if(visited[w]==0)
            {
                enqueue(&q,w);
                visited[w]=1;
                printf("\nvisit\t%d",w);
            }
            }
}}

void DFS(int i)
{
    node *p;
    printf("\n%d",i);
    p=G[i];
    visited[i]=1;
while(p!=NULL){
    
     i=p->vertex;
        if(!visited[i])
            DFS(i);
        p=p->next;
    }}



int empty(Q *P)
{
    if(P->rear==-1)
        return(1);
    return(0);
}

int full(Q *P)
{
    if(P->rear==MAX-1)
        return(1);
    return(0);
}

void enqueue(Q *P,int x)
{
    if(P->rear==-1)
    {
        P->rear=P->front=0;
        P->data[P->rear]=x;
    }
    else
    {
        P->rear=P->rear+1;
        P->data[P->rear]=x;
    }
}

int dequeue(Q *P)
{
    int x;
    x=P->data[P->front];
    if(P->rear==P->front)
    {
        P->rear=-1;
        P->front=-1;}
    else
        P->front=P->front+1;
    return(x);
}

void readgraph()
{     int i,vi,vj,no_of_edges;
    printf("\nEnter no. of vertices :");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
        G[i]=NULL;
   
    printf("\nEnter no of edges :");
    scanf("%d",&no_of_edges);
    for(i=0;i<no_of_edges;i++)
    {
        printf("\nEnter an edge (u,v)  :");
        scanf("%d%d",&vi,&vj);
        insert(vi,vj);
        insert(vj,vi);
 }
}

void insert(int vi,int vj)
{
    node *p,*q;
    
    q=(node *)malloc(sizeof(node));
    q->vertex=vj;
    q->next=NULL;
   
    if(G[vi]==NULL)
        G[vi]=q;
    else
    {
      
        p=G[vi];
        while(p->next!=NULL)
            p=p->next;
        p->next=q;
}
}

void printlist(node *G[]) {
    for (int i = 0; i < n; i++) {
node *p = G[i];
printf("Vertex %d: ", i);
      while (p != NULL) {
     printf("%d ", p->vertex);
            p = p->next;
 }
printf("\n");
}
}
