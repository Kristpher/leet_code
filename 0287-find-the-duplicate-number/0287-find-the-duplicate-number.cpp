class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    int temp=0;
    for(int i=0;i<nums.size();i++){   
       int temp=abs(nums[i]);
       if(nums[temp]<0)
       {
         return temp;
       }
       nums[temp]*=-1;
    }
    return -1;
    }
};
