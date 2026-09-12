class Solution {
public:
    bool solve(int ind, int sum, vector<int>& arr, vector<vector<int>>& dp){
        // 1. Base cases
        if(sum == 0) return true;
        if(ind == 0) return (arr[0] == sum); // Check equality and return

        // 2. Check DP table
        if(dp[ind][sum] != -1) return dp[ind][sum];

        // 3. Work and Recursive calls
        bool take = false;
        if(sum >= arr[ind]){
            take = solve(ind - 1, sum - arr[ind], arr, dp);
        }
        bool notake = solve(ind - 1, sum, arr, dp);

        // 4. Store and return
        return dp[ind][sum] = (take | notake);
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        // DP table of size 'n' rows and 'sum + 1' columns
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return solve(n - 1, sum, arr, dp);
    }
};