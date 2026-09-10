#include<bits/stdc++.h>
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        int cnt;
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                q.push(mat[i][j]);
            }
        }
        while(k>0){
            cnt=q.top();
            q.pop();
            k--;
        }
    return cnt;    
    }
};
