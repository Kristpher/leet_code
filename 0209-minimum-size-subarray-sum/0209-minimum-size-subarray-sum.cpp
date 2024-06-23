class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int r=0,l=0;
        long long sum=0;
        int minim=INT_MAX;
        while(r<=nums.size()-1)
        {
          sum=sum+nums[r];
       
    while(sum>=target){
        
           minim=min(minim,r-l+1);
          sum=sum-nums[l];
           l++;
          }
             r++;
        }
       return minim == INT_MAX ? 0 : minim;
    }
};