class Solution {
  public:
    long long maxDiamonds(vector<int>& arr, int k) {
        long long total=0;
        priority_queue<int> q(arr.begin(),arr.end());
        while(!q.empty()&&k>0){
            int curr=q.top();
            q.pop();
            total+=curr;
            q.push(curr/2);
            k--;
        }
    return total;    
    }
};