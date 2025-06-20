#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack, vector<int>& path) {
    visited[node] = true;
    recStack[node] = true;
    path.push_back(node);

    for (int neighbor = 0; neighbor < N; ++neighbor) {
        if (adj[node][neighbor]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited, recStack, path)) return true;
            } else if (recStack[neighbor]) {
                path.push_back(neighbor);
                return true;
            }
        }
    }

    recStack[node] = false;
    path.pop_back();
    return false;
}

bool detectCycleDFS(vector<vector<int>>& adj) {
    vector<bool> visited(N, false);
    vector<bool> recStack(N, false);
    vector<int> path;

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack, path)) {
                cout << "Cycle Detected using DFS: ";
                for (int node : path) cout << char('A' + node) << " ";
                cout << endl;
                return true;
            }
        }
    }

    cout << "No Cycle Detected using DFS" << endl;
    return false;
}

bool detectCycleBFS(vector<vector<int>>& adj) {
    vector<int> indegree(N, 0);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (adj[i][j]) indegree[j]++;

    queue<int> q;
    for (int i = 0; i < N; ++i)
        if (indegree[i] == 0) q.push(i);

    int count = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        ++count;

        for (int j = 0; j < N; ++j) {
            if (adj[current][j]) {
                indegree[j]--;
                if (indegree[j] == 0)
                    q.push(j);
            }
        }
    }

    if (count != N) {
        cout << "Cycle Detected using BFS" << endl;
        return true;
    }

    cout << "No Cycle Detected using BFS" << endl;
    return false;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> N;

    vector<vector<int>> adj(N, vector<int>(N));
    cout << "Enter the adjacency matrix:\n";

    for (int i = 0; i < N; ++i) {
        cout << "Row for " << char('A' + i) << ": ";
        for (int j = 0; j < N; ++j) {
            cin >> adj[i][j];
        }
    }

    cout << "\nCycle Detection Results:\n";
    detectCycleDFS(adj);
    detectCycleBFS(adj);

    return 0;
}
