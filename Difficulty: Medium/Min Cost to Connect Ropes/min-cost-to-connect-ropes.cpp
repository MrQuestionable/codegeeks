class Solution {
  public:
    int minCost(vector<int>& arr) {
        if(arr.size()==0)return 0;
        int total=0;
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto it:arr){
            q.push(it);
        }
        while(q.size()>1){
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            total+=a+b;
            q.push(a+b);
        }
    return total;    
    }
};