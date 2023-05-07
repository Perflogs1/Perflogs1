#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 1000

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int dist[MAX_VERTICES];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int dfs(int v, int n) {
    visited[v] = 1;
    int max_dist = 0;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] != 0 && !visited[i]) {
            max_dist = max(max_dist, dfs(i, n) + graph[v][i]);
        }
    }
    visited[v] = 0;
    return max_dist;
}

int longest_path(int source, int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    return dfs(source, n);
}

int main() {
    int n, m, u, v, w;
    printf("Enter the number of vertices and edges:\n");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }

    int source;
    printf("Enter the source vertex:\n");
    scanf("%d", &source);

    int longest = 0;
    for (int i = 0; i < n; i++) {
        if (i != source) {
            longest = max(longest, longest_path(i, n));
        }
    }
    printf("The longest path in the graph is: %d\n", longest);
    return 0;
}

