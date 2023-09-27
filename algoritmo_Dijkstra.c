#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 6

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
 
    printPath(parent, parent[j]);
 
    printf("%d ", j);
}

void printSolution(int dist[], int parent[], int src) {
    printf("Vertex\tDistance\tPath");
    for (int i = 0; i < V; i++) {
        printf("\n%d\t%d\t\t%d ", i, dist[i], src);
        printPath(parent, i);
    }
    printf("\n");
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];
    int parent[V];
 
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
 
    dist[src] = 0;
    parent[src] = -1;
 
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
 
        sptSet[u] = true;
 
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
 
    printSolution(dist, parent, src);
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };

    int src;
    printf("Ingresa el nodo de origen: ");
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}
