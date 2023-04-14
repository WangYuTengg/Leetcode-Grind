int dfs(int node, int target, int w, char *visited, int *population, char **graph, int N) {
    visited[node] = 1;
    int count = (population[node] <= w) ? 1 : 0;

    if (node == target) {
        return count;
    }

    for (int i = 0; i < N; i++) {
        if (graph[node][i] && !visited[i]) {
            int sub_count = dfs(i, target, w, visited, population, graph, N);
            if (sub_count >= 0) {
                count += sub_count;
                return count;
            }
        }
    }
    return -1;
}

int* city_population(int N, int* population, int** road, int Q, int** cities) {
    int *ans = (int *)malloc(Q * sizeof(int));

    char **graph = (char **)malloc(N * sizeof(char *));
    for(int i = 0; i < N; i++) {
        graph[i] = (char *)calloc(N, sizeof(char));
    }

    for(int i = 0; i < N - 1; i++) {
        int u = road[i][0] - 1;
        int v = road[i][1] - 1;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for(int i = 0; i < Q; i++) {
        int u = cities[i][0] - 1;
        int v = cities[i][1] - 1;
        int w = cities[i][2];

        char *visited = (char *)calloc(N, sizeof(char));
        ans[i] = dfs(u, v, w, visited, population, graph, N);
        free(visited);
    }

    for(int i = 0; i < N; i++) {
        free(graph[i]);
    }
    free(graph);

    return ans;
}
