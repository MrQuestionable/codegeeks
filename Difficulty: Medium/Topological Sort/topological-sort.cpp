
class Solution {
  public:

    // Function to perform topological sort on a DAG
    void topoSortUtil(int v, vector<vector<int>>& adj, vector<bool>& visited,
                      stack<int>& st) {

        // Mark the current node as visited
        visited[v] = true;

        // Recur for all adjacent vertices
        for (int i : adj[v]) {
            if (!visited[i])
                topoSortUtil(i, adj, visited, st);
        }

        // Push current vertex to stack which stores the result
        st.push(v);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        // Stack to store the result
        stack<int> st;
        vector<bool> visited(V, false);

        vector<vector<int>> adj(V);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
        }

        // Call the recursive helper function to store
        // Topological Sort starting from all vertices one by
        // one
        for (int i = 0; i < V; i++) {
            if (!visited[i])
                topoSortUtil(i, adj, visited, st);
        }

        vector<int> ans;

        // Append contents of stack
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};