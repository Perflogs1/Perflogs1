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
struct stack{
    struct node{
        int data;
        struct node* next;
    };
    struct node *top;
};
struct stack s;
void push(int x){
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    new->data=x;
    new->next=s.top;
    s.top=new;
}
int pop(){
    struct node *temp;
    temp=s.top;
    if(s.top==NULL){
        printf("Stack is empty");
    }else{
        s.top=s.top->next;
        return temp->data;
    }
}
int stackEmpty(){
    if(s.top==NULL){
        return 1;
    }else{
        return 0;
    }
}
void DFS(int adj[][no_of_vertices],int i,int visited[]){
    int j;
    printf("%d",i);
    visited[i]=1;
    for(j=0;j<no_of_vertices;j++){
        if(adj[i][j]!=0 && visited[j]!=1){
            DFS(adj,j,visited);
        }
    }
}
void dfs(int adj[][no_of_vertices],int i,int visited1[]){
    push(i);
    while (!stackEmpty())
    {
        i=pop();
        visited1[i]=1;
        printf("%d",i);
        for(int j=0;j<no_of_vertices;j++){
            if(adj[i][j]==1 && visited1[j]!=1){
                if(s.top==NULL){
                    push(j);
                }
                else if(s.top->data!=j){
                    push(j);
                }
            }
        }
    }

}
void main(){
    printf("Enter the no. of vertices: ");
    scanf("%d",&no_of_vertices);
    int adj[no_of_vertices][no_of_vertices];
    int visited[no_of_vertices];
    for(int i=0;i<no_of_vertices;i++){
        visited[i]=0;
    }
    int visited1[no_of_vertices];
    for(int i=0;i<no_of_vertices;i++){
        visited1[i]=0;
    }    

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
    s.top=NULL;
    DFS(adj,0,visited);
    printf("\n");
    dfs(adj,0,visited1);
}