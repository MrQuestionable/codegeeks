class Solution {
  public:
    void dfs(int node,vector<vector<pair<int,int>>>& adj,vector<int> &vis,stack<int> &st ){
        vis[node]=1;
        for(auto it:adj[node]){
            int v=it.first;
            if(!vis[v])dfs(v,adj,vis,st);
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        vector<int> vis(V,0);
        vector<int> dist(V,1e9);
        stack<int> st;// code here
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        dist[0]=0;
        while(!st.empty()){
                    int src = st.top();
                    st.pop();
                    if (dist[src] != 1e9) {
                        for(auto it : adj[src]){
                            int v = it.first;
                            int wt = it.second;

                            if(dist[src] + wt < dist[v]) {
                                dist[v] = dist[src] + wt;
                            }
                        }
                    }
                }
                for(int i = 0; i < V; i++){
                    if(dist[i] == 1e9) dist[i] = -1;
                }

                return dist;    
            }
        };
