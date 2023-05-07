#include<stdio.h>
#include<stdlib.h>
int no_of_vertices;
void printGraph(int adj[][no_of_vertices]){
    for(int i=0;i<no_of_vertices;i++){
        for(int j=0;j<no_of_vertices;j++){
            printf("%d",adj[i][j]);
        }
        printf("\n");
    }
}
struct queue{
    struct node{
        int data;
        struct node *next;
    };
    struct node *front;
    struct node *rear;
};
struct queue Q;
void enqueue(int x){
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    new->data=x;
    new->next=NULL;
    if(Q.front==NULL && Q.rear==NULL){
        Q.front=Q.rear=new;
    }else{
        Q.rear->next=new;
        Q.rear=new;
    }
}
int dequeue(){
    struct node *temp;
    temp=Q.front;
    int dequeued;
    if(Q.front==NULL && Q.rear==NULL){
        printf("Queue is empty");
        return 0;
    }else if(Q.front==Q.rear){
        dequeued=temp->data;
        free(temp);
        Q.front=NULL;
        Q.rear=NULL;
        return dequeued;
    }else{
        dequeued=temp->data;
        Q.front=Q.front->next;
        free(temp);
        return dequeued;
    }
}
void bfs(int i,int adj[][no_of_vertices],int visited[]){
    enqueue(i);
    while(Q.front!=NULL && Q.rear!=NULL){
        i=dequeue();
        visited[i]=1;
        printf("%d ",i);
        for(int j=0;j<no_of_vertices;j++){
            if(adj[i][j]!=0 && visited[j]!=1 && Q.rear==NULL){
                enqueue(j);
            }else if(adj[i][j]!=0 && visited[j]!=1 && Q.rear->data!=j){
                enqueue(j);
            }
        }
    }
}


int main(){
    Q.front=NULL;
    Q.rear=NULL;
    printf("Enter the no. of vertices: ");
    scanf("%d",&no_of_vertices);
    int adj[no_of_vertices][no_of_vertices];
    int visited[no_of_vertices];
    for(int i=0;i<no_of_vertices;i++){
        visited[i]=0;
    }
    // int visited1[no_of_vertices];
    // for(int i=0;i<no_of_vertices;i++){
    //     visited1[i]=0;
    // }    

    for(int i=0;i<no_of_vertices;i++){
        for(int j=0;j<no_of_vertices;j++){
            adj[i][j]=0;
        }
    }
    int choice=1;
    while(choice==1){
        int i,j;
        printf("Enter the vertices between which you want edges: ");
        scanf("%d%d",&i,&j);
        adj[i][j]=1;
        adj[j][i]=1;
        printf("Enter 1 if you want to add more edges: ");
        scanf("%d",&choice);
    }
    printGraph(adj);
    bfs(0,adj,visited);
    




    return 0;
}