# Hopcroft-Karp Algorithm for Maximum Matching in Bipartite Graphs

This repository contains an implementation of the **Hopcroft-Karp Algorithm** in C, which is used to find the maximum matching in a bipartite graph. This algorithm is efficient and widely used in applications such as job assignment, resource allocation, and other network flow problems.

## Overview

The Hopcroft-Karp algorithm finds the maximum matching in a bipartite graph by efficiently locating augmenting paths. It alternates between BFS and DFS to incrementally improve the matching, achieving a time complexity of \(O(\sqrt{V} \cdot E)\), where \(V\) and \(E\) are the number of vertices and edges, respectively.

### Features

- Efficient maximum matching in bipartite graphs
- Uses BFS and DFS to locate and augment paths
- Designed for bipartite graphs represented using an adjacency matrix

## File Structure

- **hopcroft_karp.c**: The main C file containing the implementation of the Hopcroft-Karp algorithm.
- **README.md**: This documentation file.

## How to Run

1. Clone this repository.
2. Compile the C program:
   ```bash
   gcc hopcroft_karp.c -o hopcroft_karp

## Example
The example in hopcroft_karp.c represents a bipartite graph with nodes divided into two parts (left and right). An example graph configuration is:
* Left nodes: 1, 2, 3, 4
* Right nodes: 1, 2, 3, 4
* Edges: {(1,1), (1,2), (2,1), (2,3), (3,2), (3,4), (4,3)}
Running the program on this graph will provide the following output: Maximum Matching: 3

## Explanation of the Code
* add_edge: Adds an edge between a node in the left partition and a node in the right partition. The adjacency matrix adj is used to store edges.
* bfs: Performs BFS to identify the shortest augmenting path. For unmatched nodes in the left set, the distances are initialized to 0. It then iterates over neighboring nodes, updating distances and marking reachable pairs, building the foundation for the DFS step.
* dfs: Recursively finds and updates augmenting paths. If a node in the left set is unmatched, it explores possible pairings with nodes in the right set using updated distances from bfs.
* hopcroft_karp: This function brings together bfs and dfs to implement the core of the Hopcroft-Karp algorithm. While there is an augmenting path found by bfs, it calls dfs to improve the matching count.

## Applications
The Hopcroft-Karp algorithm is valuable in a variety of practical scenarios where maximum matching is required, such as:
* Job Assignment: Assign jobs to workers to maximize the number of jobs completed. Each worker can be assigned one job, and the algorithm ensures maximum pairing.
* Resource Allocation: Match resources to requests in a way that maximizes satisfaction, such as allocating rooms to events or students to courses.
* Network Flow Problems: Solve specific types of network flow problems efficiently, especially in bipartite graphs.

## Time and Space Complexity
* Time Complexity: O(√V * E), where V is the number of vertices and E is the number of edges in the bipartite graph. This efficiency is achieved through alternating BFS (to find all shortest augmenting paths) and DFS (to incrementally improve the matching count).
* Space Complexity: O(V + E). This includes space for the adjacency matrix (or adjacency list in larger implementations) and auxiliary data structures such as distance-tracking arrays required for BFS and DFS.
