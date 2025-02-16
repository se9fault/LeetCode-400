/*
Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is
a pair of nodes), write a function to check whether these edges make up a valid
tree.

Example 1:
Input: n = 5, edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true

Example 2:
Input: n = 5, edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false

Note: you can assume that no duplicate edges will appear in edges. Since all
edges are undirected, [0,1] is the same as [1,0] and thus will not appear
together in edges.
*/

class Solution {
public:
    bool validTree(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n, vector<int>());
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        if (!dfs(adj, visited, 0, -1)) {
            return false;
        }
        for (auto v : visited) {
            if (!v) {
                return false;
            }
        }
        return true;
    }
private:
    bool dfs(vector<vector<int>> &adj, vector<bool> &visited, int cur, int pre) {
        if (visited[cur]) {
            return false;
        }
        visited[cur] = true;
        for (auto node : adj[cur]) {
            if (node == pre) {
                continue;
            }
            if (!dfs(adj, visited, node, cur)) {
                return false;
            }
        }
        return true;
    }
};
