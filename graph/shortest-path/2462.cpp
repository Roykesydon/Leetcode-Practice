#include <iostream>
#include <vector>

using namespace std;

class Graph {
   private:
    vector<vector<int>> dp;

   public:
    Graph(int n, vector<vector<int>>& edges) {
        dp.resize(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++) dp[i][i] = 0;

        for (auto edge : edges) {
            int fromNode = edge[0];
            int toNode = edge[1];
            int cost = edge[2];

            dp[fromNode][toNode] = min(dp[fromNode][toNode], cost);
        }

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    }

    void addEdge(vector<int> edge) {
        int n = dp.size();
        int fromNode = edge[0];
        int toNode = edge[1];
        int cost = edge[2];
        dp[fromNode][toNode] = min(dp[fromNode][toNode], cost);


        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = min(dp[i][j], dp[i][fromNode] + dp[toNode][j] + dp[fromNode][toNode]);
    }

    int shortestPath(int node1, int node2) {
        return (dp[node1][node2] == 1e9) ? (-1) : (dp[node1][node2]);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */