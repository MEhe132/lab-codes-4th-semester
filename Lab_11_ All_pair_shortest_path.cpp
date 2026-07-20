    #include <stdio.h>

    #define INF 99999
    #define MAX 100

    void floydWarshall(int graph[MAX][MAX], int n)
    {
        int dist[MAX][MAX];

        // Initialize distance matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = graph[i][j];
            }
        }

        // Floyd-Warshall Algorithm
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] != INF && dist[k][j] != INF &&
                        dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Print shortest distance matrix
        printf("\nAll Pairs Shortest Path Matrix:\n");

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] == INF)
                    printf("INF ");
                else
                    printf("%3d ", dist[i][j]);
            }
            printf("\n");
        }
    }

    int main()
    {
        int n;
        int graph[MAX][MAX];

        printf("Enter the number of vertices: ");
        scanf("%d", &n);

        printf("Enter the adjacency matrix (use %d for INF):\n", INF);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &graph[i][j]);
            }
        }

        floydWarshall(graph, n);

        return 0;
    }

    // 4
    // 0 3 99999 5
    // 2 0 99999 4
    // 99999 1 0 99999
    // 99999 99999 2 0