class Solution {
public:
    int lis(vector<int>& arr) {
        int n = arr.size();
        vector<int> next(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for(int i = n - 1; i >= 0; i--){
            for(int j = i - 1; j >= -1; j--){

                int len = next[j + 1];

                if(j == -1 || arr[i] > arr[j]){
                    len = max(len, 1 + next[i + 1]); 
                }

                curr[j + 1] = len;
            }
            next = curr;
        }

        return next[0];       
    }
};