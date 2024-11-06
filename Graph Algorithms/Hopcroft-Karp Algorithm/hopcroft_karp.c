#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 1000 // Define maximum number of vertices

int n, m; // Number of nodes in each part of the bipartite graph
int adj[MAX][MAX]; // Adjacency matrix for the graph
int pairU[MAX], pairV[MAX], dist[MAX];

// Adds an edge from u in the left partition to v in the right partition
void add_edge(int u, int v) {
    adj[u][v] = 1;
}

// BFS to check if there's an augmenting path
bool bfs() {
    int queue[MAX], front = 0, back = 0;
    for (int u = 1; u <= n; u++) {
        if (pairU[u] == 0) {
            dist[u] = 0;
            queue[back++] = u;
        } else {
            dist[u] = INT_MAX;
        }
    }
    dist[0] = INT_MAX;
    while (front < back) {
        int u = queue[front++];
        if (dist[u] < dist[0]) {
            for (int v = 1; v <= m; v++) {
                if (adj[u][v] && dist[pairV[v]] == INT_MAX) {
                    dist[pairV[v]] = dist[u] + 1;
                    queue[back++] = pairV[v];
                }
            }
        }
    }
    return dist[0] != INT_MAX;
}

// DFS to find an augmenting path and update pairs
bool dfs(int u) {
    if (u != 0) {
        for (int v = 1; v <= m; v++) {
            if (adj[u][v] && dist[pairV[v]] == dist[u] + 1) {
                if (dfs(pairV[v])) {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INT_MAX;
        return false;
    }
    return true;
}

// Hopcroft-Karp Algorithm to find maximum matching
int hopcroft_karp() {
    for (int u = 0; u <= n; u++) pairU[u] = 0;
    for (int v = 0; v <= m; v++) pairV[v] = 0;

    int matching = 0;
    while (bfs()) {
        for (int u = 1; u <= n; u++) {
            if (pairU[u] == 0 && dfs(u)) {
                matching++;
            }
        }
    }
    return matching;
}

int main() {
    // Example bipartite graph with 4 nodes on each side
    n = 4; m = 4;

    // Define edges for the bipartite graph
    add_edge(1, 1);
    add_edge(1, 2);
    add_edge(2, 1);
    add_edge(2, 3);
    add_edge(3, 2);
    add_edge(3, 4);
    add_edge(4, 3);

    // Find maximum matching
    int max_matching = hopcroft_karp();
    printf("Maximum Matching: %d\n", max_matching);

    return 0;
}

