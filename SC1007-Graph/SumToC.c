#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 210

int S, P, M;
int graph[MAX][MAX];
int source, target;
bool visited[MAX];
int parent[MAX];

bool dfs(int u)
{
    if (u == target)
    {
        return true;
    }
    visited[u] = true;

    for (int v = 0; v <= target; ++v)
    {
        if (graph[u][v] > 0 && !visited[v])
        {
            parent[v] = u;
            if (dfs(v))
            {
                return true;
            }
        }
    }
    return false;
}

int fordFulkerson()
{
    int max_flow = 0;

    while (true)
    {
        memset(visited, 0, sizeof(visited));
        if (!dfs(source))
        {
            break;
        }

        int path_capacity = 1;
        for (int v = target; v != source; v = parent[v])
        {
            int u = parent[v];
            graph[u][v] -= path_capacity;
            graph[v][u] += path_capacity;
        }
        max_flow += path_capacity;
    }

    return max_flow;
}

int main()
{
    scanf("%d %d %d", &S, &P, &M);

    source = 0;
    target = S + P + M + 2;

    for (int i = 1; i <= S; ++i)
    {
        graph[source][i] = 1;
    }
    for (int i = S + P + 1; i <= S + P + M; ++i)
    {
        graph[i][target - 1] = 1;
    }
    graph[target - 1][target] = P;

    for (int i = 1; i <= S; ++i)
    {
        int num_projects, num_mentors;
        scanf("%d %d", &num_projects, &num_mentors);

        for (int j = 0; j < num_projects; ++j)
        {
            int project_id;
            scanf("%d", &project_id);
            graph[i][S + project_id] = 1;
        }
        for (int j = 0; j < num_mentors; ++j)
        {
            int mentor_id;
            scanf("%d", &mentor_id);
            graph[i][S + P + mentor_id] = 1;
        }
    }

    int max_matches = fordFulkerson();
    printf("%d\n", max_matches);

    return 0;
}
