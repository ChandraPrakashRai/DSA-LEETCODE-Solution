#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void BFS(vector<bool>& visited, vector<vector<int>>& adj, int node) {
        queue<int> que;
        visited[node] = true;
        que.push(node);

        while (!que.empty()) {
            int curr = que.front();
            que.pop();

            for (int v : adj[curr]) {
                if (!visited[v]) {
                    visited[v] = true;
                    que.push(v);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        vector<bool> visited(V, false);
        vector<vector<int>> adj(V);

        // Make adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                BFS(visited, adj, i);
                count++;
            }
        }

        return count;
    }
};
