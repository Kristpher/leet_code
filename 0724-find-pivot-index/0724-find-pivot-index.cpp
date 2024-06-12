class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left=0;
        int right=0;
        int maxim=0;
        int sum=0;
        for(int i=1;i<nums.size();i++)
        right+=nums[i];
        if(right==0)
        return 0;
       
        for(int i=1;i<nums.size();i++)
        {

          right-=nums[i];
          left+=nums[i-1];
          if(right==left)
          return i;

        }
        return -1;
    }
};