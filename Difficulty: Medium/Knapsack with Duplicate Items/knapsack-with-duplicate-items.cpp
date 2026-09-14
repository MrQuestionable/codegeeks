class Solution {
  public:
    int solve(int ind,int w ,vector<int>& val, vector<int>& wt,vector<vector<int>> &dp){
        if(ind==0){
            return ((int)(w/wt[0]))*val[0];
        }
        if(dp[ind][w]!=-1)return dp[ind][w];
        int notake=solve(ind-1, w, val, wt,dp);
        int take=0;
        if(w>=wt[ind]){
            take= val[ind] + solve(ind,w-wt[ind],val,wt,dp);
        }
        return dp[ind][w]=max(take,notake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        return solve(n-1,capacity,val,wt,dp);
    }
};