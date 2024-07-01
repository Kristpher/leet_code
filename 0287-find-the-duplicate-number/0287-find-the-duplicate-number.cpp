class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    vector<int>v(nums.size(),0);
    int ind=0;
    for(int i=0;i<nums.size();i++)
    {   if(v[nums[i]-1]==1){
       ind=nums[i];
        break;
        }
        v[nums[i]-1]=1;
    }
    return ind;
    }
};