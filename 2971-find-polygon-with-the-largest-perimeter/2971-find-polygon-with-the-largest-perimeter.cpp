class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=0;
        long long peri=0;
        long long ind=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum-nums[i]>nums[i]){
            peri=sum;
            ind=i;
            }
           
           
        }
        
        if(ind>1)
        return peri;
        return -1;
    }
};