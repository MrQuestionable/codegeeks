class Solution {
  public:
    bool f(int ind,vector<int>& arr, int k,vector<vector<int>> &dp){
        if(k==0)return true;
        
        if(ind==arr.size()||k<0)return false;
        if(dp[ind][k]!=-1)return dp[ind][k];
        bool take = false;
                if (arr[ind] <= k) {
                    take = f(ind + 1, arr, k - arr[ind], dp);
                }
        bool notake=f(ind+1,arr,k,dp);
        return dp[ind][k]=(take||notake);
    }
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return f(0,arr,k,dp);
    }
};