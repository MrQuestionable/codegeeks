#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, adj, vis, st);            
        }
        st.push(node);
    }

    void dfs2(int node, vector<vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]) dfs2(it, adj, vis);            
        }
    }

    int countSCC(int V, vector<vector<int>> &edges) { 

        // 1. EXPLICIT EDGE LIST PARSING
        vector<vector<int>> adj(V);
        for(auto& edge : edges) {
            // edge[0] is the source, edge[1] is the destination
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> vis(V, 0);
        stack<int> st;

        // PASS 1: Sort by finishing time
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }

        // PASS 2: Transpose (reverse) the graph
        vector<vector<int>> adjt(V);
        for(int i = 0; i < V; i++){
            vis[i] = 0; // Reset visited array efficiently
            for(auto it : adj[i]){
                adjt[it].push_back(i); // Reverse the edge
            }
        }

        // PASS 3: Count the SCCs
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();

            if(!vis[node]){
                scc++;
                dfs2(node, adjt, vis);
            }
        }

        return scc;    
    }
};