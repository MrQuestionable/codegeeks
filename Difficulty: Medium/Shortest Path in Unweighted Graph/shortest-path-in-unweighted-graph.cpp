class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<int>> adj(V);
        vector<int> vis(V,0);
        vector<int> dist(V,1e9);
        queue<int> q;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dist[src]=0;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vis[node]=1;
            for(auto it:adj[node]){
                if(dist[node]+1<dist[it]){
                    dist[it]=1+dist[node];
                    q.push(it);
                }
            }
        }
        if (dist[dest] == 1e9){
            return -1; 
        }

    return dist[dest];
    }
};
