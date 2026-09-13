class Solution {
public:
    int solve(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
        if (ind < 0) {
            return (target == 0) ? 1 : 0;
        }
        if(dp[ind][target]!=-1)return dp[ind][target];
        int notake = solve(ind - 1, target, arr, dp);

        int take = 0;
        if (target >= arr[ind]) {
            take = solve(ind - 1, target - arr[ind], arr, dp);
        }

        return dp[ind][target]=take + notake;
    }

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(n - 1, target, arr, dp);
    }
};