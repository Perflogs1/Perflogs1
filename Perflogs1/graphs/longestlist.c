#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int dest;       // destination vertex of the edge
    int weight;     // weight of the edge
    struct Node* next;  // pointer to the next node in the list
};

struct AdjList
 {
    struct Node* head;  
};


struct Graph {
    int num_vertices;   // number of vertices in the graph
    struct AdjList* adj_lists;  // array of adjacency lists
};

struct Node* createNode(int dest, int weight) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int num_vertices) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->num_vertices = num_vertices;
    graph->adj_lists = (struct AdjList*) malloc(num_vertices * sizeof(struct AdjList));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_lists[i].head = NULL;
    }
    return graph;
}

// This function adds an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adj_lists[src].head;
    graph->adj_lists[src].head = newNode;
}

//Dijkstra Algorithm (Longest path)
void longestPath(struct Graph* graph, int start_vertex) {
    int* distances = (int*) malloc(graph->num_vertices * sizeof(int));
    int* visited = (int*) malloc(graph->num_vertices * sizeof(int));

    for (int i = 0; i < graph->num_vertices; i++) {
        distances[i] = INT_MIN;
        visited[i] = 0;
    }
    distances[start_vertex] = 0;
    for (int i = 0; i < graph->num_vertices - 1; i++) {
        int max_distance = INT_MIN;
        int max_vertex = -1;
        for (int j = 0; j < graph->num_vertices; j++) {
            if (!visited[j] && distances[j] > max_distance) {
                max_distance = distances[j];
                max_vertex = j;
            }
        }
        if (max_vertex == -1) {
            break;
        }
        visited[max_vertex] = 1;
        struct Node* temp = graph->adj_lists[max_vertex].head;
        while (temp != NULL) {
            int u = max_vertex;
            int v = temp->dest;
            int weight = temp->weight;
            if (distances[u] != INT_MIN && distances[u] + weight > distances[v]) {
                distances[v] = distances[u] + weight;
            }
            temp = temp->next;
        }
    }
    printf("Longest paths from vertex %d:\n", start_vertex);
    for (int i = 0; i < graph->num_vertices; i++) {
        if (distances[i] == INT_MIN) 
        {
            printf("%d : No path\n");
} 
else {
printf("%d : %d\n", i, distances[i]);
}
}
}

void printGraph(struct Graph* graph) {
printf("Adjacency List:\n");
for (int i = 0; i < graph->num_vertices; i++) {
struct Node* temp = graph->adj_lists[i].head;
printf("Vertex %d: ", i);
while (temp != NULL) {
printf("(%d, %d) ", temp->dest, temp->weight);
temp = temp->next;
}
printf("\n");
}
}

int main() {
    int num_Vertices;
    int src,dest,weight;
    int start;
printf("\nEnter the no. of vertices in your graph : ");
  scanf("%d",&num_Vertices);

  struct Graph * graph = createGraph(num_Vertices);
  printf("Enter the edges of the graph in the format <SRC> <DESTINATION> <WEIGHT> (enter -1 to exit):\n");
  while(1){ 
    scanf("%d %d %d",&src , &dest , &weight);
    if(src == -1 &&  dest == -1 && weight == -1 )
      break;
    addEdge(graph,src,dest,weight);
  }
// addEdge(graph, 0, 1, 10);
// addEdge(graph, 0, 4, 11);
// addEdge(graph, 0, 3, 8);
// addEdge(graph, 1, 2, 5);
// addEdge(graph, 2, 1, 5);
// addEdge(graph, 2, 3, 7);
// addEdge(graph, 3, 4, 12);

printGraph(graph);


printf("\nEnter the start node : ");
scanf("%d",&start);
longestPath(graph, start);
return 0;
}































