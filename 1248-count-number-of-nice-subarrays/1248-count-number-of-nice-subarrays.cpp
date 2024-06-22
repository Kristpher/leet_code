class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int p=0;
        int flag=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            p++;
            else
            flag=1;
           
            
            
        }
        if(!flag)
        return 0;
        
    return p*2;
    };
};