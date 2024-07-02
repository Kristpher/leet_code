class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    int flag=1;
    if(nums[0]<0) flag=0;
    for(int i=0;i<nums.size();i++)
    nums[i]*=nums[i];
    if(!flag) sort(nums.begin(),nums.end());
    return nums;
    }
};