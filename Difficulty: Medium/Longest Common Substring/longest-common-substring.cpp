class Solution {
public:
    int longCommSubstr(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();

        // 1-based indexing DP table initialized to 0
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int max_len = 0; // We need this to track the longest streak found anywhere

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){

                // If characters match, add 1 to the diagonal (the previous streak)
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    // Update our global max streak
                    max_len = max(max_len, dp[i][j]); 
                }
                else {
                    // If they don't match, the contiguous streak is BROKEN. Reset to 0.
                    dp[i][j] = 0; 
                }
            }
        }

        return max_len;
    }
};