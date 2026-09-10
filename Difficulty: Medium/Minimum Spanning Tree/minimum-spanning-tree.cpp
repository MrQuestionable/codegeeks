class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> edge(V);
                for(auto& it : edges) {
                    int u = it[0];
                    int v = it[1];
                    int wet = it[2];
                    edge[u].push_back({v, wet});
                    edge[v].push_back({u, wet}); 
                }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<int> vis(V,0);
        q.push({0,0});
        int sum=0;
        while(!q.empty()){
            auto it=q.top();
            int wt=it.first;
            int node=it.second;
            q.pop();
            if(vis[node])continue;
            vis[node]=1;
            sum+=wt;
            for(auto it:edge[node]){
                int adjnode=it.first;
                int ewt=it.second;
                if(!vis[adjnode]){
                    q.push({ewt,adjnode});
                }
            }
        }
    return sum;    
    }
};