class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        int n=arr.size();
        for(int i=0;i<=(n/2)-1;i++){
            int r=2*i+1,l=2*i+2;
            if((l<n && arr[l]>arr[i])||(r<n && arr[r]>arr[i]))return false;
        }
    return true;    
    }
};
