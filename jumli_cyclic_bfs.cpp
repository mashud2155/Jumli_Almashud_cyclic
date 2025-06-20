#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

int main() {
    cout << "Enter number of vertices: ";
    cin >> N;

    vector<vector<int>> adj(N, vector<int>(N));
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < N; ++i) {
        cout << "Row for " << char('A' + i) << ": ";
        for (int j = 0; j < N; ++j)
            cin >> adj[i][j];
    }

    vector<int> indegree(N, 0);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (adj[i][j])
                indegree[j]++;

    queue<int> q;
    for (int i = 0; i < N; ++i)
        if (indegree[i] == 0)
            q.push(i);

    int visitedCount = 0;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        visitedCount++;

        for (int j = 0; j < N; ++j) {
            if (adj[current][j]) {
                indegree[j]--;
                if (indegree[j] == 0)
                    q.push(j);
            }
        }
    }

    if (visitedCount != N)
        cout << "Cycle Detected using BFS" << endl;
    else
        cout << "No Cycle Detected using BFS" << endl;

    return 0;
}
