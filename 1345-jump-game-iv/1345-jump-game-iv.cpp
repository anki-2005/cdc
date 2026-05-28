class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;

        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; i++)
            graph[arr[i]].push_back(i);

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            steps++;
            while (sz--) {
                int i = q.front(); q.pop();

                vector<int> neighbors = {i - 1, i + 1};
                if (graph.count(arr[i]))
                    for (int j : graph[arr[i]])
                        neighbors.push_back(j);
                graph.erase(arr[i]);

                for (int j : neighbors) {
                    if (j < 0 || j >= n || visited[j]) continue;
                    if (j == n - 1) return steps;
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
        return -1;
    }
};