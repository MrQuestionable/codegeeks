class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int n=arr.size();
        int totsum=0,mod=1e9+7;   
        for(auto& it:arr)totsum+=it;
        if(totsum-diff<0 || (totsum-diff)%2!=0)return 0;
        int target=(totsum-diff)/2;
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        if(arr[0]==0)dp[0][0]=2;
        else dp[0][0]=1;
        if(arr[0] != 0 && arr[0] <= target) {
                dp[0][arr[0]] = 1;
            }
        for(int i=1;i<n;i++){
            for(int t=0;t<=target;t++){
                int nottake=dp[i-1][t];
                int take=0;
                if(t>=arr[i]){
                take=dp[i-1][t-arr[i]];
                }
                dp[i][t]=(take+nottake)%mod;
            }
        }
    return dp[n-1][target];    
    }
};