class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<=n-1;j++){
                int mini=INT_MAX;
                for(int k=i;k<j;k++){
                    int cost=dp[i][k]+dp[k+1][j]+(arr[i-1]*arr[k]*arr[j]);
                    mini=min(mini,cost);
                }
            dp[i][j]=mini;    
            }
        }
    return dp[1][n-1];    
    }
};