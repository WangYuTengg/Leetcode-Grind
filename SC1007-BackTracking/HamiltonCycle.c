#include <stdio.h>
#include <stdbool.h>
#define N 6

void addEdge(int adjMatrix[N][N], int v, int w);
bool hamilton_cycle_util(int adjMatrix[N][N], int path[N], int *pathLength);

int main()
{
    // initialise graph
    int graph[N][N] = {0};
    addEdge(graph, 2, 3);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 4);
    addEdge(graph, 0, 1);

    // initialise path
    int path[N];
    for (int i = 0; i < N; i++)
    {
        path[i] = -1;
    }
    path[0] = 0; // set first element of path array to start vertex
    int pathLength = 1;

    bool result = hamilton_cycle_util(graph, path, &pathLength);
    printf("Hamilton cycle exists: %s\n", result ? "true" : "false");
    return 0;
}

void addEdge(int adjMatrix[N][N], int v, int w)
{
    adjMatrix[v][w] = 1;
    adjMatrix[w][v] = 1;
}

bool hamilton_cycle_util(int adjMatrix[N][N], int path[N], int *pathLength)
{
    // set current vertex
    int currentVertex = path[*pathLength - 1];

    // base case
    if (*pathLength >= N && adjMatrix[0][currentVertex])
    {
        return true;
    }

    // iterate through adjacent vertices of currentVertex
    bool result = false;
    for (int i = 0; i < N; i++)
    {
        // adjacent vertices
        if (adjMatrix[currentVertex][i])
        {

            // check whether adjacent vertex is already visited
            bool inPath = false;
            for (int j = 0; j < *pathLength; j++)
            {
                if (i == path[j])
                    inPath = true;
            }

            // not visited, recursive call
            if (!inPath)
            {
                path[*pathLength] = i;
                (*pathLength)++;
                result = hamilton_cycle_util(adjMatrix, path, pathLength);
                if (result)
                    return true;
                else
                {
                    // backtrack
                    (*pathLength)--;
                    path[*pathLength] = -1;
                }
            }
        }
    }

    return result;
}