class Solution {
public:
    int findMaxK(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int l=0;
       int r=nums.size()-1;
       int maxim=0;
       while(l<r){
        if(nums[l]+nums[r]>0)
        {
            r--;

        }
        else if(nums[l]+nums[r]<0)
        {
            l++;
        }
        else{
            return nums[r];
        }
       } 
       return -1;
    }
};