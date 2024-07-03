class Solution {
public:
    int minDifference(vector<int>& nums) {
    if(nums.size()<=4)
    return 0;
    sort(nums.begin(),nums.end());
    int n=nums.size()-1;
    int minim=INT_MAX;
    minim=min(minim,nums[n]-nums[3]);
    minim=min(minim,nums[n-3]-nums[0]);
    minim=min(minim,nums[n-2]-nums[1]);
    minim=min(minim,nums[n-1]-nums[2]);
    return minim;
    
    }
};